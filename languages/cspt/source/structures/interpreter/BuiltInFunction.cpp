#include "BuiltInFunction.hpp"

BuiltInFunction::BuiltInFunction(std::string _name, Position _start, Position _end, Context* _context)
: Value(ValueType::BUILTIN_FUNCTION, _start, _end), BaseFunction(ValueType::BUILTIN_FUNCTION, _name, _start, _end)
{
  context = _context;
}

BuiltInFunction::BuiltInFunction(std::string _name, Context* _context)
: Value(ValueType::BUILTIN_FUNCTION, Position(), Position()), BaseFunction(ValueType::BUILTIN_FUNCTION, _name, Position(), Position())
{
  context = _context;
}

RTResult BuiltInFunction::execute(std::vector<std::shared_ptr<Value>> args)
{
  RTResult result = RTResult();
  Context exec_context = generate_new_context();

  std::shared_ptr<Value> return_value = nullptr;

  if (name == "log")
  {
    result.register_result(check_args({"value"}, args, &exec_context));
    if (result.should_return()) return result;

    return_value = result.register_result(log(&exec_context));
    if (result.should_return()) return result;
  } 
  else if (name == "ask")
  {
    result.register_result(check_args({"value"}, args, &exec_context));
    if (result.should_return()) return result;

    return_value = result.register_result(ask(&exec_context));
    if (result.should_return()) return result;
  }

  if (return_value == nullptr)
  {
    return result.failure(std::make_shared<RTError>(
      "Built-in function '" + name + "' is not defined",
      start,
      end
    ));
  }

  return result.success(return_value);
}

RTResult BuiltInFunction::log(Context* context)
{
  RTResult result = RTResult();
  std::shared_ptr<Value> value = context->symbol_table->get("value"); 

  std::cout << value->to_string() << std::endl;

  return result.success(std::make_shared<Null>(start, end, context));
}

RTResult BuiltInFunction::ask(Context* context)
{
  RTResult result = RTResult();
  std::shared_ptr<Value> value = context->symbol_table->get("value"); 

  if (value->type != ValueType::STRING)
  {
    return result.failure(std::make_shared<RTError>(
      "Expected string",
      start,
      end
    ));
  }

  String content = dynamic_cast<String&>(*value);

  std::string input;
  std::cout << content.value;
  getline(std::cin, input, '\n');


  return result.success(std::make_shared<String>(input, start, end, context));
}

bool BuiltInFunction::is_true()
{
  return true;
}

std::shared_ptr<Value> BuiltInFunction::to_positive()
{
  throw std::runtime_error("BuiltInFunction '" + name + "' does not support this operation");
}

std::shared_ptr<Value> BuiltInFunction::to_negative()
{
  throw std::runtime_error("BuiltInFunction '" + name + "' does not support this operation");
}

std::shared_ptr<Value> BuiltInFunction::to_not()
{
  throw std::runtime_error("BuiltInFunction '" + name + "' does not support this operation");
}

std::shared_ptr<Value> BuiltInFunction::add(std::shared_ptr<Value> other)
{
  throw std::runtime_error("BuiltInFunction '" + name + "' does not support this operation");
}

std::shared_ptr<Value> BuiltInFunction::subtract(std::shared_ptr<Value> other)
{
  throw std::runtime_error("BuiltInFunction '" + name + "' does not support this operation");
}

std::shared_ptr<Value> BuiltInFunction::multiply(std::shared_ptr<Value> other)
{
  throw std::runtime_error("BuiltInFunction '" + name + "' does not support this operation");
}

std::shared_ptr<Value> BuiltInFunction::divide(std::shared_ptr<Value> other)
{
  throw std::runtime_error("BuiltInFunction '" + name + "' does not support this operation");
}

std::shared_ptr<Value> BuiltInFunction::modulo(std::shared_ptr<Value> other)
{
  throw std::runtime_error("BuiltInFunction '" + name + "' does not support this operation");
}

std::shared_ptr<Value> BuiltInFunction::power(std::shared_ptr<Value> other)
{
  throw std::runtime_error("BuiltInFunction '" + name + "' does not support this operation");
}

std::shared_ptr<Value> BuiltInFunction::equal(std::shared_ptr<Value> other)
{
  throw std::runtime_error("BuiltInFunction '" + name + "' does not support this operation");
}

std::shared_ptr<Value> BuiltInFunction::not_equal(std::shared_ptr<Value> other)
{
  throw std::runtime_error("BuiltInFunction '" + name + "' does not support this operation");
}

std::shared_ptr<Value> BuiltInFunction::greater_than(std::shared_ptr<Value> other)
{
  throw std::runtime_error("BuiltInFunction '" + name + "' does not support this operation");
}

std::shared_ptr<Value> BuiltInFunction::less_than(std::shared_ptr<Value> other)
{
  throw std::runtime_error("BuiltInFunction '" + name + "' does not support this operation");
}

std::shared_ptr<Value> BuiltInFunction::greater_than_or_equal(std::shared_ptr<Value> other)
{
  throw std::runtime_error("BuiltInFunction '" + name + "' does not support this operation");
}

std::shared_ptr<Value> BuiltInFunction::less_than_or_equal(std::shared_ptr<Value> other)
{
  throw std::runtime_error("BuiltInFunction '" + name + "' does not support this operation");
}

std::shared_ptr<Value> BuiltInFunction::and_op(std::shared_ptr<Value> other)
{
  throw std::runtime_error("BuiltInFunction '" + name + "' does not support this operation");
}

std::shared_ptr<Value> BuiltInFunction::or_op(std::shared_ptr<Value> other)
{
  throw std::runtime_error("BuiltInFunction '" + name + "' does not support this operation");
}

std::string BuiltInFunction::to_string()
{
  return "<built-in function " + name + ">";
}

BuiltInFunction BuiltInFunction::copy()
{
  return BuiltInFunction(name, start, end, context);
}