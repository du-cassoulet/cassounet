#include "String.hpp"

String::String(std::string _value, Position _start, Position _end, Context* _context)
: Value(ValueType::STRING, _start, _end), value(_value)
{
  set_context(_context);
}

bool String::is_true()
{
  return value != "";
}

RTResult String::to_positive()
{
  return RTResult().failure(std::make_shared<RTError>("Cannot convert string to positive", start, end));
}

RTResult String::to_negative()
{
  return RTResult().failure(std::make_shared<RTError>("Cannot convert string to negative", start, end));
}

RTResult String::to_not()
{
  return RTResult().success(std::make_shared<Boolean>(value == "", start, end, context));
}

RTResult String::add(std::shared_ptr<Value> other)
{
  RTResult result = RTResult();

  if (other->type != ValueType::STRING)
  {
    return result.failure(std::make_shared<RTError>(
      "Expected string",
      start,
      end
    ));
  }

  String string = dynamic_cast<String&>(*other);
  
  return result.success(std::make_shared<String>(value + string.value, start, end, context));
}

RTResult String::subtract(std::shared_ptr<Value> other)
{
  return RTResult().failure(std::make_shared<RTError>("Cannot subtract string", start, end));
}

RTResult String::multiply(std::shared_ptr<Value> other)
{
  return RTResult().failure(std::make_shared<RTError>("Cannot multiply string", start, end));
}

RTResult String::divide(std::shared_ptr<Value> other)
{
  return RTResult().failure(std::make_shared<RTError>("Cannot divide string", start, end));
}

RTResult String::modulo(std::shared_ptr<Value> other)
{
  return RTResult().failure(std::make_shared<RTError>("Cannot modulo string", start, end));
}

RTResult String::power(std::shared_ptr<Value> other)
{
  return RTResult().failure(std::make_shared<RTError>("Cannot power string", start, end));
}

RTResult String::equal(std::shared_ptr<Value> other)
{
  RTResult result = RTResult();

  if (other->type != ValueType::STRING)
  {
    return result.failure(std::make_shared<RTError>(
      "Expected string",
      start,
      end
    ));
  }

  String string = dynamic_cast<String&>(*other);
  return result.success(std::make_shared<Boolean>(value == string.value, start, end, context));
}

RTResult String::not_equal(std::shared_ptr<Value> other)
{
  RTResult result = RTResult();

  if (other->type != ValueType::STRING)
  {
    return result.failure(std::make_shared<RTError>(
      "Expected string",
      start,
      end
    ));
  }

  String string = dynamic_cast<String&>(*other);
  return result.success(std::make_shared<Boolean>(value != string.value, start, end, context));
}

RTResult String::greater_than(std::shared_ptr<Value> other)
{
  return RTResult().failure(std::make_shared<RTError>("Cannot compare string", start, end));
}

RTResult String::less_than(std::shared_ptr<Value> other)
{
  return RTResult().failure(std::make_shared<RTError>("Cannot compare string", start, end));
}

RTResult String::greater_than_or_equal(std::shared_ptr<Value> other)
{
  return RTResult().failure(std::make_shared<RTError>("Cannot compare string", start, end));
}

RTResult String::less_than_or_equal(std::shared_ptr<Value> other)
{
  return RTResult().failure(std::make_shared<RTError>("Cannot compare string", start, end));
}

RTResult String::and_op(std::shared_ptr<Value> other)
{
  return RTResult().success(std::make_shared<Boolean>(is_true() && other->is_true(), start, end, context));
}

RTResult String::or_op(std::shared_ptr<Value> other)
{
  return RTResult().success(std::make_shared<Boolean>(is_true() || other->is_true(), start, end, context));
}

std::string String::to_string(int depth)
{
  if (depth > 0) return util::color::colorize("\"" + value + "\"", util::color::green);
  return value;
}