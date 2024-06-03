#include "Boolean.hpp"

Boolean::Boolean(bool _value, Position _start, Position _end, Context* _context)
: Value(ValueType::BOOLEAN, _start, _end), value(_value)
{
  set_context(_context);
}

bool Boolean::is_true()
{
  return value;
}

RTResult Boolean::to_positive()
{
  return RTResult().failure(std::make_shared<RTError>("Cannot convert boolean to positive", start, end));
}

RTResult Boolean::to_negative()
{
  return RTResult().failure(std::make_shared<RTError>("Cannot convert boolean to negative", start, end));
}

RTResult Boolean::to_not()
{
  return RTResult().success(std::make_shared<Boolean>(!value, start, end, context));
}

RTResult Boolean::add(std::shared_ptr<Value> other)
{
  return RTResult().failure(std::make_shared<RTError>("Cannot add boolean", start, end));
}

RTResult Boolean::subtract(std::shared_ptr<Value> other)
{
  return RTResult().failure(std::make_shared<RTError>("Cannot subtract boolean", start, end));
}

RTResult Boolean::multiply(std::shared_ptr<Value> other)
{
  return RTResult().failure(std::make_shared<RTError>("Cannot multiply boolean", start, end));
}

RTResult Boolean::divide(std::shared_ptr<Value> other)
{
  return RTResult().failure(std::make_shared<RTError>("Cannot divide boolean", start, end));
}

RTResult Boolean::modulo(std::shared_ptr<Value> other)
{
  return RTResult().failure(std::make_shared<RTError>("Cannot modulo boolean", start, end));
}

RTResult Boolean::power(std::shared_ptr<Value> other)
{
  return RTResult().failure(std::make_shared<RTError>("Cannot power boolean", start, end));
}

RTResult Boolean::equal(std::shared_ptr<Value> other)
{
  RTResult result = RTResult();

  if (other->type != ValueType::BOOLEAN)
  {
    return result.failure(std::make_shared<RTError>(
      "Expected boolean",
      start,
      end,
      context
    ));
  }

  Boolean boolean = dynamic_cast<Boolean&>(*other);
  return result.success(std::make_shared<Boolean>(value == boolean.value, start, end, context));
}

RTResult Boolean::not_equal(std::shared_ptr<Value> other)
{
  RTResult result = RTResult();

  if (other->type != ValueType::BOOLEAN)
  {
    return result.failure(std::make_shared<RTError>(
      "Expected boolean",
      start,
      end
    ));
  }

  Boolean boolean = dynamic_cast<Boolean&>(*other);
  return result.success(std::make_shared<Boolean>(value != boolean.value, start, end, context));
}

RTResult Boolean::greater_than(std::shared_ptr<Value> other)
{
  return RTResult().failure(std::make_shared<RTError>("Cannot compare boolean", start, end));
}

RTResult Boolean::less_than(std::shared_ptr<Value> other)
{
  return RTResult().failure(std::make_shared<RTError>("Cannot compare boolean", start, end));
}

RTResult Boolean::greater_than_or_equal(std::shared_ptr<Value> other)
{
  return RTResult().failure(std::make_shared<RTError>("Cannot compare boolean", start, end));
}

RTResult Boolean::less_than_or_equal(std::shared_ptr<Value> other)
{
  return RTResult().failure(std::make_shared<RTError>("Cannot compare boolean", start, end));
}

RTResult Boolean::and_op(std::shared_ptr<Value> other)
{
  return RTResult().success(std::make_shared<Boolean>(value && other->is_true(), start, end, context));
}

RTResult Boolean::or_op(std::shared_ptr<Value> other)
{
  return RTResult().success(std::make_shared<Boolean>(value || other->is_true(), start, end, context));
}

std::string Boolean::to_string(int depth)
{
  return util::color::colorize(value ? "true" : "false", util::color::yellow);
}