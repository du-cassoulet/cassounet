#include "List.hpp"

List::List(std::vector<std::shared_ptr<Value>> _values, Position _start, Position _end, Context* _context)
: Value(ValueType::LIST, _start, _end), values(_values)
{
  set_context(_context);
}

bool List::is_true()
{
  return values.size() != 0;
}

RTResult List::to_positive()
{
  return RTResult().failure(std::make_shared<RTError>(
    "Cannot convert a list to a number",
    start,
    end
  ));
}

RTResult List::to_negative()
{
  return RTResult().failure(std::make_shared<RTError>(
    "Cannot convert a list to a number",
    start,
    end
  ));
}

RTResult List::to_not()
{
  return RTResult().success(std::make_shared<Boolean>(values.size() == 0, start, end, context));
}

RTResult List::add(std::shared_ptr<Value> other)
{
  values.push_back(other);
  return RTResult().success(std::make_shared<List>(values, start, end, context));
}

RTResult List::subtract(std::shared_ptr<Value> other)
{
  RTResult result = RTResult();

  if (other->type != ValueType::NUMBER)
  {
    return result.failure(std::make_shared<RTError>(
      "Expected number",
      start,
      end
    ));
  }

  Number number = dynamic_cast<Number&>(*other);

  if (number.value < 0 || number.value >= values.size())
  {
    return result.failure(std::make_shared<RTError>(
      "Index out of bounds",
      start,
      end
    ));
  }

  values.erase(values.begin() + number.value);
  return result.success(std::make_shared<List>(values, start, end, context));
}

RTResult List::multiply(std::shared_ptr<Value> other)
{
  RTResult result = RTResult();

  if (other->type != ValueType::NUMBER)
  {
    return result.failure(std::make_shared<RTError>(
      "Expected number",
      start,
      end
    ));
  }

  Number number = dynamic_cast<Number&>(*other);

  if (number.value < 0)
  {
    return result.failure(std::make_shared<RTError>(
      "Cannot multiply a list by a negative number",
      start,
      end
    ));
  }

  std::vector<std::shared_ptr<Value>> new_values;

  for (int i = 0; i < number.value; i++)
  {
    for (int j = 0; j < values.size(); j++)
    {
      new_values.push_back(values[j]);
    }
  }

  return result.success(std::make_shared<List>(new_values, start, end, context));
}

RTResult List::divide(std::shared_ptr<Value> other)
{
  return RTResult().failure(std::make_shared<RTError>("Cannot divide a list", start, end));
}

RTResult List::modulo(std::shared_ptr<Value> other)
{
  return RTResult().failure(std::make_shared<RTError>("Cannot modulo a list", start, end));
}

RTResult List::power(std::shared_ptr<Value> other)
{
  return RTResult().failure(std::make_shared<RTError>("Cannot power a list", start, end));
}

RTResult List::equal(std::shared_ptr<Value> other)
{
  return RTResult().success(std::make_shared<Boolean>(values == dynamic_cast<List&>(*other).values, start, end, context));
}

RTResult List::not_equal(std::shared_ptr<Value> other)
{
  return RTResult().success(std::make_shared<Boolean>(values != dynamic_cast<List&>(*other).values, start, end, context));
}

RTResult List::greater_than(std::shared_ptr<Value> other)
{
  return RTResult().failure(std::make_shared<RTError>("Cannot compare a list", start, end));
}

RTResult List::less_than(std::shared_ptr<Value> other)
{
  return RTResult().failure(std::make_shared<RTError>("Cannot compare a list", start, end));
}

RTResult List::greater_than_or_equal(std::shared_ptr<Value> other)
{
  return RTResult().failure(std::make_shared<RTError>("Cannot compare a list", start, end));
}

RTResult List::less_than_or_equal(std::shared_ptr<Value> other)
{
  return RTResult().failure(std::make_shared<RTError>("Cannot compare a list", start, end));
}

RTResult List::and_op(std::shared_ptr<Value> other)
{
  return RTResult().success(std::make_shared<Boolean>(is_true() && other->is_true(), start, end, context));
}

RTResult List::or_op(std::shared_ptr<Value> other)
{
  return RTResult().success(std::make_shared<Boolean>(is_true() || other->is_true(), start, end, context));
}

std::string List::to_string(int depth)
{
  depth++;
  std::string res = "";
  int size = values.size();

  if (size == 0)
  {
    return util::color::colorize("[] (empty)", util::color::black);
  }

  res += util::color::colorize("[\n", util::color::black);

  for (int i = 0; i < values.size(); i++)
  {
    res += std::string(2 * depth, ' ') +
      util::color::colorize(std::to_string(i), util::color::yellow) +
      util::color::colorize(":", util::color::black) +
      " " +
      values[i]->to_string(depth) +
      util::color::colorize(",", util::color::black) +
      "\n";
  }

  res += std::string(2 * (depth - 1), ' ') +
    util::color::colorize("] (" + std::to_string(size) + " element" + (size > 1 ? "s" : "") + ")", util::color::black);

  return res;
}