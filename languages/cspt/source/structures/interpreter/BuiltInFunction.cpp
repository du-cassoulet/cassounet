#include "BuiltInFunction.hpp"

BuiltInFunction::BuiltInFunction(std::string _name, Position _start, Position _end, SymbolTable* _symbol_table)
: Value(ValueType::BUILTIN_FUNCTION, _start, _end), SymbolValue(ValueType::BUILTIN_FUNCTION, _start, _end), BaseFunction(ValueType::BUILTIN_FUNCTION, _name, _start, _end, _symbol_table) {}

RTResult BuiltInFunction::execute(std::vector<std::shared_ptr<Value>> args)
{
  RTResult result = RTResult();
  SymbolTable exec_symbol_table = generate_new_symbol_table();


  if (name == "log")
  {
    check_args({"value"}, args, &exec_symbol_table);
    std::shared_ptr<Value> return_value = result.register_result(log(&exec_symbol_table));
    if (result.should_return()) return result;
    return result.success(return_value);
  }
  else
  {
    throw std::runtime_error("BuiltInFunction '" + name + "' does not support this operation");
  }

  return result;
}

RTResult BuiltInFunction::log(SymbolTable* symbol_table)
{
  RTResult result = RTResult();
  std::shared_ptr<Value> value = symbol_table->get("value");

  std::cout << value->to_string() << std::endl;

  return result.success(std::make_shared<Null>(start, end));
}

std::shared_ptr<Value> BuiltInFunction::to_positive() {
  throw std::runtime_error("BuiltInFunction '" + name + "' does not support this operation");
}

std::shared_ptr<Value> BuiltInFunction::to_negative() {
  throw std::runtime_error("BuiltInFunction '" + name + "' does not support this operation");
}

std::shared_ptr<Value> BuiltInFunction::to_not() {
  throw std::runtime_error("BuiltInFunction '" + name + "' does not support this operation");
}

std::shared_ptr<Value> BuiltInFunction::add(std::shared_ptr<Value> other) {
  throw std::runtime_error("BuiltInFunction '" + name + "' does not support this operation");
}

std::shared_ptr<Value> BuiltInFunction::subtract(std::shared_ptr<Value> other) {
  throw std::runtime_error("BuiltInFunction '" + name + "' does not support this operation");
}

std::shared_ptr<Value> BuiltInFunction::multiply(std::shared_ptr<Value> other) {
  throw std::runtime_error("BuiltInFunction '" + name + "' does not support this operation");
}

std::shared_ptr<Value> BuiltInFunction::divide(std::shared_ptr<Value> other) {
  throw std::runtime_error("BuiltInFunction '" + name + "' does not support this operation");
}

std::shared_ptr<Value> BuiltInFunction::modulo(std::shared_ptr<Value> other) {
  throw std::runtime_error("BuiltInFunction '" + name + "' does not support this operation");
}

std::shared_ptr<Value> BuiltInFunction::power(std::shared_ptr<Value> other) {
  throw std::runtime_error("BuiltInFunction '" + name + "' does not support this operation");
}

std::shared_ptr<Value> BuiltInFunction::equal(std::shared_ptr<Value> other) {
  throw std::runtime_error("BuiltInFunction '" + name + "' does not support this operation");
}

std::shared_ptr<Value> BuiltInFunction::not_equal(std::shared_ptr<Value> other) {
  throw std::runtime_error("BuiltInFunction '" + name + "' does not support this operation");
}

std::shared_ptr<Value> BuiltInFunction::greater_than(std::shared_ptr<Value> other) {
  throw std::runtime_error("BuiltInFunction '" + name + "' does not support this operation");
}

std::shared_ptr<Value> BuiltInFunction::less_than(std::shared_ptr<Value> other) {
  throw std::runtime_error("BuiltInFunction '" + name + "' does not support this operation");
}

std::shared_ptr<Value> BuiltInFunction::greater_than_or_equal(std::shared_ptr<Value> other) {
  throw std::runtime_error("BuiltInFunction '" + name + "' does not support this operation");
}

std::shared_ptr<Value> BuiltInFunction::less_than_or_equal(std::shared_ptr<Value> other) {
  throw std::runtime_error("BuiltInFunction '" + name + "' does not support this operation");
}

std::shared_ptr<Value> BuiltInFunction::and_op(std::shared_ptr<Value> other) {
  throw std::runtime_error("BuiltInFunction '" + name + "' does not support this operation");
}

std::shared_ptr<Value> BuiltInFunction::or_op(std::shared_ptr<Value> other) {
  throw std::runtime_error("BuiltInFunction '" + name + "' does not support this operation");
}

std::string BuiltInFunction::to_string() {
  return "<built-in function " + name + ">";
}

BuiltInFunction BuiltInFunction::copy() {
  return BuiltInFunction(name, start, end, symbol_table);
}