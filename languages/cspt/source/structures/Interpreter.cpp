#include "Interpreter.hpp"

Interpreter::Interpreter(SymbolTable* _symbol_table)
: symbol_table(_symbol_table) {}

RTResult Interpreter::visit_number(NumberNode node)
{
  return RTResult().success(std::make_shared<Number>(std::stod(node.value_tok.value), node.start, node.end, symbol_table));
}

RTResult Interpreter::visit_string(StringNode node)
{
  return RTResult().success(std::make_shared<String>(node.value_tok.value, node.start, node.end, symbol_table));
}

RTResult Interpreter::visit_boolean(BooleanNode node)
{
  return RTResult().success(std::make_shared<Boolean>(node.value_tok.value == "true", node.start, node.end, symbol_table));
}

RTResult Interpreter::visit_list(ListNode node)
{
  RTResult result = RTResult();
  std::vector<std::shared_ptr<Value>> values = {};

  for (auto& elem_node : node.nodes)
  { 
    std::shared_ptr<Value> value = result.register_result(visit(elem_node));
    if (result.should_return()) return result;

    values.push_back(value);
  }

  return result.success(std::make_shared<List>(values, node.start, node.end, symbol_table));
}

RTResult Interpreter::visit_null(NullNode node)
{
  return RTResult().success(std::make_shared<Null>(node.start, node.end, symbol_table));
}

RTResult Interpreter::visit_unary_op(UnaryOpNode node)
{
  RTResult result = RTResult();

  std::shared_ptr<Value> operand = result.register_result(visit(node.operand));

  switch (node.op_tok.type)
  {
    case TokenType::TT_PLUS:
      return result.success(operand->to_positive());

    case TokenType::TT_MINUS:
      return result.success(operand->to_negative());

    case TokenType::TT_NOT:
      return result.success(operand->to_not());

    default:
      throw std::invalid_argument("Invalid unary operator: " + node.op_tok.to_string_type());
  }
}

RTResult Interpreter::visit_binary_op(BinaryOpNode node)
{
  RTResult result = RTResult();

  std::shared_ptr<Value> left = result.register_result(visit(node.left));
  std::shared_ptr<Value> right = result.register_result(visit(node.right));

  switch (node.op_tok.type)
  {
    case TokenType::TT_PLUS:
      return result.success(left->add(right));

    case TokenType::TT_MINUS:
      return result.success(left->subtract(right));

    case TokenType::TT_MUL:
      return result.success(left->multiply(right));

    case TokenType::TT_DIV:
      return result.success(left->divide(right));

    case TokenType::TT_POW:
      return result.success(left->power(right));

    case TokenType::TT_EQUALS:
      return result.success(left->equal(right));

    case TokenType::TT_NEQUALS:
      return result.success(left->not_equal(right));

    case TokenType::TT_LT:
      return result.success(left->less_than(right));

    case TokenType::TT_GT:
      return result.success(left->greater_than(right));

    case TokenType::TT_LTE:
      return result.success(left->less_than_or_equal(right));

    case TokenType::TT_GTE:
      return result.success(left->greater_than_or_equal(right));

    case TokenType::TT_AND:
      return result.success(left->and_op(right));

    case TokenType::TT_OR:
      return result.success(left->or_op(right));

    default:
      throw std::invalid_argument("Invalid binary operator: " + node.op_tok.to_string_type());
  }
}

RTResult Interpreter::visit_var_assign(VarAssignNode node)
{
  RTResult result = RTResult();

  std::string var_name = node.var_name.value;
  std::shared_ptr<Value> value = result.register_result(visit(node.value));

  symbol_table->set(var_name, value);

  return result.success(value);
}

RTResult Interpreter::visit_var_reassign(VarReAssignNode node)
{
  RTResult result = RTResult();

  std::string var_name = node.var_name.value;
  std::shared_ptr<Value> value = result.register_result(visit(node.value));

  if (!symbol_table->contains(var_name))
  {
    result.failure(std::make_shared<RTError>("Variable '" + var_name + "' is not defined", node.start, node.end));
  }

  symbol_table->set(var_name, value);
  return result.success(value);
}

RTResult Interpreter::visit_var_access(VarAccessNode node)
{
  RTResult result = RTResult();

  std::string var_name = node.var_name.value;
  std::shared_ptr<Value> value = symbol_table->get(var_name);

  if (value == nullptr)
  {
    return result.failure(std::make_shared<RTError>("Variable '" + var_name + "' is not defined", node.start, node.end));
  }

  return result.success(value);
}

RTResult Interpreter::visit_call(CallNode node)
{
  RTResult result = RTResult();

  std::shared_ptr<Value> func_name = result.register_result(visit(node.func_name));
  std::vector<std::shared_ptr<Value>> args = {};

  for (std::shared_ptr<Node> arg_node : node.args)
  {
    args.push_back(result.register_result(visit(arg_node)));
  }

  std::shared_ptr<Value> return_value;

  if (func_name->type == ValueType::FUNCTION)
  {
    Function func = dynamic_cast<Function&>(*func_name);
    return_value = result.register_result(func.execute(args));
  }
  else if (func_name->type == ValueType::BUILTIN_FUNCTION)
  {
    BuiltInFunction func = dynamic_cast<BuiltInFunction&>(*func_name);
    return_value = result.register_result(func.execute(args));
  }
  else
  {
    return result.failure(std::make_shared<RTError>("Variable '" + func_name->to_string() + "' is not function", node.func_name->start, node.func_name->end));
  }

  if (result.should_return()) return result;

  return result.success(return_value);
}

RTResult Interpreter::visit_return(ReturnNode node)
{
  RTResult result = RTResult();
  std::shared_ptr<Value> value = std::make_shared<Null>(node.start, node.end, symbol_table);

  if (node.node)
  {
    value = result.register_result(visit(node.node));
    if (result.should_return()) return result;
  }

  return result.success_return(value);
}

RTResult Interpreter::visit_if(IfNode node)
{
  RTResult result = RTResult();

  std::shared_ptr<Value> condition = result.register_result(visit(node.if_cond));

  if (condition->is_true())
  {
    std::shared_ptr<Value> value = result.register_result(visit(node.if_body));
    if (result.should_return()) return result;

    return result.success(value);
  }
  else if (node.else_body != nullptr)
  {
    std::shared_ptr<Value> value = result.register_result(visit(node.else_body));
    if (result.should_return()) return result;

    return result.success(value);
  }

  return result.success(std::make_shared<Null>(node.start, node.end, symbol_table));
}

RTResult Interpreter::visit(std::shared_ptr<Node> node)
{
  switch (node->type)
  {
    case NodeType::NUMBER:
      return visit_number(dynamic_cast<NumberNode&>(*node));

    case NodeType::STRING:
      return visit_string(dynamic_cast<StringNode&>(*node));

    case NodeType::BOOLEAN:
      return visit_boolean(dynamic_cast<BooleanNode&>(*node));

    case NodeType::LIST:
      return visit_list(dynamic_cast<ListNode&>(*node));

    case NodeType::NULL_NODE:
      return visit_null(dynamic_cast<NullNode&>(*node));

    case NodeType::BINARY_OPERATION:
      return visit_binary_op(dynamic_cast<BinaryOpNode&>(*node));

    case NodeType::UNARY_OPERATION:
      return visit_unary_op(dynamic_cast<UnaryOpNode&>(*node));

    case NodeType::VAR_ASSIGN:
      return visit_var_assign(dynamic_cast<VarAssignNode&>(*node));

    case NodeType::VAR_REASSIGN:
      return visit_var_reassign(dynamic_cast<VarReAssignNode&>(*node));

    case NodeType::VAR_ACCESS:
      return visit_var_access(dynamic_cast<VarAccessNode&>(*node));

    case NodeType::CALL:
      return visit_call(dynamic_cast<CallNode&>(*node));

    case NodeType::RETURN:
      return visit_return(dynamic_cast<ReturnNode&>(*node));

    case NodeType::IF:
      return visit_if(dynamic_cast<IfNode&>(*node));

    default:
      throw std::invalid_argument("Invalid node type: " + node->to_string(1));
  }
}