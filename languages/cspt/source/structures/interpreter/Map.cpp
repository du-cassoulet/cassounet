#include "Map.hpp"

Map::Map(std::map<std::string, std::shared_ptr<Value>> _values, Position _start, Position _end, Context* _context)
: Value(ValueType::MAP, _start, _end), values(_values)
{
  set_context(_context);
}

bool Map::is_true()
{
  return values.size() != 0;
}

RTResult Map::to_positive()
{
  return RTResult().failure(std::make_shared<RTError>(
    "Cannot convert a map to a number",
    start,
    end
  ));
}

RTResult Map::to_negative()
{
  return RTResult().failure(std::make_shared<RTError>(
    "Cannot convert a map to a number",
    start,
    end
  ));
}

RTResult Map::to_not()
{
  return RTResult().success(std::make_shared<Boolean>(values.size() == 0, start, end, context));
}

RTResult Map::add(std::shared_ptr<Value> other)
{
  return RTResult().failure(std::make_shared<RTError>(
    "Cannot add to a map",
    start,
    end
  ));
}

RTResult Map::subtract(std::shared_ptr<Value> other)
{
  return RTResult().failure(std::make_shared<RTError>(
    "Cannot subtract from a map",
    start,
    end
  ));
}

RTResult Map::multiply(std::shared_ptr<Value> other)
{
  return RTResult().failure(std::make_shared<RTError>(
    "Cannot multiply a map",
    start,
    end
  ));
}

RTResult Map::divide(std::shared_ptr<Value> other)
{
  return RTResult().failure(std::make_shared<RTError>(
    "Cannot divide a map",
    start,
    end
  ));
}

RTResult Map::modulo(std::shared_ptr<Value> other)
{
  return RTResult().failure(std::make_shared<RTError>(
    "Cannot modulo a map",
    start,
    end
  ));
}

RTResult Map::power(std::shared_ptr<Value> other)
{
  return RTResult().failure(std::make_shared<RTError>(
    "Cannot power a map",
    start,
    end
  ));
}

RTResult Map::equal(std::shared_ptr<Value> other)
{
  return RTResult().success(std::make_shared<Boolean>(
    values == dynamic_cast<Map&>(*other).values,
    start,
    end,
    context
  ));
}

RTResult Map::not_equal(std::shared_ptr<Value> other)
{
  return RTResult().success(std::make_shared<Boolean>(
    values != dynamic_cast<Map&>(*other).values,
    start,
    end,
    context
  ));
}

RTResult Map::greater_than(std::shared_ptr<Value> other)
{
  return RTResult().failure(std::make_shared<RTError>(
    "Cannot compare a map",
    start,
    end
  ));
}

RTResult Map::less_than(std::shared_ptr<Value> other)
{
  return RTResult().failure(std::make_shared<RTError>(
    "Cannot compare a map",
    start,
    end
  ));
}

RTResult Map::greater_than_or_equal(std::shared_ptr<Value> other)
{
  return RTResult().failure(std::make_shared<RTError>(
    "Cannot compare a map",
    start,
    end
  ));
}

RTResult Map::less_than_or_equal(std::shared_ptr<Value> other)
{
  return RTResult().failure(std::make_shared<RTError>(
    "Cannot compare a map",
    start,
    end
  ));
}

RTResult Map::and_op(std::shared_ptr<Value> other)
{
  return RTResult().success(std::make_shared<Boolean>(
    is_true() && other->is_true(),
    start,
    end,
    context
  ));
}

RTResult Map::or_op(std::shared_ptr<Value> other)
{
  return RTResult().success(std::make_shared<Boolean>(
    is_true() || other->is_true(),
    start,
    end,
    context
  ));
}

std::string Map::to_string(int depth)
{
  depth++;
  std::string res = "";
  int size = values.size();

  if (size == 0)
  {
    return util::color::colorize("{} (empty)", util::color::black);
  }

  res += util::color::colorize("{\n", util::color::black);

  for (auto& [key, value] : values)
  {
    res += std::string(2 * depth, ' ') +
      util::color::colorize("\"" + key + "\"", util::color::green) +
      " " +
      util::color::colorize("=>", util::color::black) +
      " " +
      value->to_string(depth) +
      util::color::colorize(", ", util::color::black) +
      "\n";
  }

  res += std::string(2 * (depth - 1), ' ') +
    util::color::colorize("} (" + std::to_string(size) + " element" + (size > 1 ? "s" : "") + ")", util::color::black);
  
  return res;
}