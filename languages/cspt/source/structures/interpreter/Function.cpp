#include "Function.hpp"

Function::Function(std::string _name, Position _start, Position _end, std::shared_ptr<Node> _body_node, std::vector<std::string> _arg_names, bool _should_auto_return, SymbolTable* _symbol_table)
: Value(ValueType::FUNCTION, _start, _end), SymbolValue(ValueType::FUNCTION, _start, _end), BaseFunction(ValueType::FUNCTION, _name, _start, _end, _symbol_table), body_node(_body_node), arg_names(_arg_names), should_auto_return(_should_auto_return) {}

RTResult Function::execute(std::vector<std::shared_ptr<Value>> args)
{
  RTResult result = RTResult();
  SymbolTable exec_symbol_table = generate_new_symbol_table();
  Interpreter interpreter = Interpreter(&exec_symbol_table);

  check_args(arg_names, args, &exec_symbol_table);
  std::shared_ptr<Value> value = result.register_result(interpreter.visit(body_node));

  if (result.should_return() && result.return_value == nullptr)
  {
    return result;
  }

  std::shared_ptr<Value> return_value;

  if (should_auto_return)
  {
    return_value = value;
  }
  else if (result.return_value != nullptr)
  {
    return_value = result.return_value;
  }
  else
  {
    return_value = std::make_shared<Null>(start, end, symbol_table);
  }

  return result.success(return_value);
}

bool Function::is_true()
{
  return true;
}

std::shared_ptr<Value> Function::to_positive() {
  throw std::runtime_error("Function '" + name + "' does not support this operation");
}

std::shared_ptr<Value> Function::to_negative() {
  throw std::runtime_error("Function '" + name + "' does not support this operation");
}

std::shared_ptr<Value> Function::to_not() {
  throw std::runtime_error("Function '" + name + "' does not support this operation");
}

std::shared_ptr<Value> Function::add(std::shared_ptr<Value> other) {
  throw std::runtime_error("Function '" + name + "' does not support this operation");
}

std::shared_ptr<Value> Function::subtract(std::shared_ptr<Value> other) {
  throw std::runtime_error("Function '" + name + "' does not support this operation");
}

std::shared_ptr<Value> Function::multiply(std::shared_ptr<Value> other) {
  throw std::runtime_error("Function '" + name + "' does not support this operation");
}

std::shared_ptr<Value> Function::divide(std::shared_ptr<Value> other) {
  throw std::runtime_error("Function '" + name + "' does not support this operation");
}

std::shared_ptr<Value> Function::modulo(std::shared_ptr<Value> other) {
  throw std::runtime_error("Function '" + name + "' does not support this operation");
}

std::shared_ptr<Value> Function::power(std::shared_ptr<Value> other) {
  throw std::runtime_error("Function '" + name + "' does not support this operation");
}

std::shared_ptr<Value> Function::equal(std::shared_ptr<Value> other) {
  throw std::runtime_error("Function '" + name + "' does not support this operation");
}

std::shared_ptr<Value> Function::not_equal(std::shared_ptr<Value> other) {
  throw std::runtime_error("Function '" + name + "' does not support this operation");
}

std::shared_ptr<Value> Function::greater_than(std::shared_ptr<Value> other) {
  throw std::runtime_error("Function '" + name + "' does not support this operation");
}

std::shared_ptr<Value> Function::less_than(std::shared_ptr<Value> other) {
  throw std::runtime_error("Function '" + name + "' does not support this operation");
}

std::shared_ptr<Value> Function::greater_than_or_equal(std::shared_ptr<Value> other) {
  throw std::runtime_error("Function '" + name + "' does not support this operation");
}

std::shared_ptr<Value> Function::less_than_or_equal(std::shared_ptr<Value> other) {
  throw std::runtime_error("Function '" + name + "' does not support this operation");
}

std::shared_ptr<Value> Function::and_op(std::shared_ptr<Value> other) {
  throw std::runtime_error("Function '" + name + "' does not support this operation");
}

std::shared_ptr<Value> Function::or_op(std::shared_ptr<Value> other) {
  throw std::runtime_error("Function '" + name + "' does not support this operation");
}

std::string Function::to_string() {
  return "<function " + name + ">";
}

Function Function::copy() {
  return Function(name, start, end, body_node, arg_names, should_auto_return, symbol_table);
}