#include "Interpreter.hpp"

Interpreter::Interpreter(SymbolTable* _symbol_table)
: symbol_table(_symbol_table) {}

std::shared_ptr<Value> Interpreter::visit_number(NumberNode node)
{
  Number value = Number(std::stod(node.value_tok.value));
  return std::make_shared<Number>(value);
}

std::shared_ptr<Value> Interpreter::visit_string(StringNode node)
{
  String value = String(node.value_tok.value);
  return std::make_shared<String>(value);
}

std::shared_ptr<Value> Interpreter::visit_boolean(BooleanNode node)
{
  Boolean value = Boolean(node.value_tok.value == "true");
  return std::make_shared<Boolean>(value);
}

std::shared_ptr<Value> Interpreter::visit_unary_op(UnaryOpNode node)
{
  std::shared_ptr<Value> operand = visit(node.operand);
  TokenType op_type = node.op_tok.type;

  switch (op_type)
  {
    case TokenType::TT_PLUS:
      operand->to_positive();
      return operand;

    case TokenType::TT_MINUS:
      operand->to_negative();
      return operand;

    case TokenType::TT_NOT:
      operand->to_not();
      return operand;

    default:
      throw std::invalid_argument("Invalid unary operator: " + node.op_tok.to_string_type());
  }
}

std::shared_ptr<Value> Interpreter::visit_binary_op(BinaryOpNode node)
{
  std::shared_ptr<Value> left = visit(node.left);
  std::shared_ptr<Value> right = visit(node.right);
  TokenType op_type = node.op_tok.type;

  switch (op_type)
  {
    case TokenType::TT_PLUS:
      left->add(right);
      return left;

    case TokenType::TT_MINUS:
      left->subtract(right);
      return left;

    case TokenType::TT_MUL:
      left->multiply(right);
      return left;

    case TokenType::TT_DIV:
      left->divide(right);
      return left;

    case TokenType::TT_POW:
      left->power(right);
      return left;

    case TokenType::TT_EQUALS:
      left->equal(right);
      return left;

    case TokenType::TT_NEQUALS:
      left->not_equal(right);
      return left;

    case TokenType::TT_LT:
      left->less_than(right);
      return left;

    case TokenType::TT_GT:
      left->greater_than(right);
      return left;

    case TokenType::TT_LTE:
      left->less_than_or_equal(right);
      return left;

    case TokenType::TT_GTE:
      left->greater_than_or_equal(right);
      return left;

    case TokenType::TT_AND:
      left->and_op(right);
      return left;

    case TokenType::TT_OR:
      left->or_op(right);
      return left;

    default:
      throw std::invalid_argument("Invalid binary operator: " + node.op_tok.to_string_type());
  }
}

std::shared_ptr<Value> Interpreter::visit_var_assign(VarAssignNode node)
{
  std::string var_name = node.var_name.value;
  std::shared_ptr<Value> value = visit(node.value);

  symbol_table->set(var_name, value);

  return value;
}

std::shared_ptr<Value> Interpreter::visit_var_reassign(VarReAssignNode node)
{
  std::string var_name = node.var_name.value;
  std::shared_ptr<Value> value = visit(node.value);

  if (!symbol_table->contains(var_name))
  {
    throw std::invalid_argument("Variable '" + var_name + "' is not defined");
  }

  symbol_table->set(var_name, value);
  return value;
}

std::shared_ptr<Value> Interpreter::visit_var_access(VarAccessNode node)
{
  std::string var_name = node.var_name.value;
  std::shared_ptr<Value> value = symbol_table->get(var_name);

  if (value == nullptr)
  {
    throw std::invalid_argument("Variable '" + var_name + "' is not defined");
  }

  return value;
}

std::shared_ptr<Value> Interpreter::visit_call(CallNode node)
{
  
}

std::shared_ptr<Value> Interpreter::visit(std::shared_ptr<Node> node)
{
  switch (node->type)
  {
    case NodeType::NUMBER:
      return visit_number(dynamic_cast<NumberNode&>(*node));

    case NodeType::STRING:
      return visit_string(dynamic_cast<StringNode&>(*node));

    case NodeType::BOOLEAN:
      return visit_boolean(dynamic_cast<BooleanNode&>(*node));

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
      throw visit_call(dynamic_cast<CallNode&>(*node));

    default:
      throw std::invalid_argument("Invalid node type: " + node->to_string(1));
  }
}