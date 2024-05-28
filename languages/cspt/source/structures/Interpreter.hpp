#pragma once

#include <string>
#include <memory>

#include "SymbolTable.hpp"
#include "nodes/Node.hpp"
#include "interpreter/Value.hpp"
#include "interpreter/Number.hpp"
#include "interpreter/String.hpp"
#include "interpreter/Boolean.hpp"
#include "nodes/NumberNode.hpp"
#include "nodes/StringNode.hpp"
#include "nodes/BooleanNode.hpp"
#include "nodes/BinaryOpNode.hpp"
#include "nodes/UnaryOpNode.hpp"
#include "nodes/VarAssignNode.hpp"
#include "nodes/VarReAssignNode.hpp"
#include "nodes/VarAccessNode.hpp"
#include "nodes/CallNode.hpp"

struct Interpreter
{
private:
  std::shared_ptr<Value> visit_number(NumberNode node);
  std::shared_ptr<Value> visit_string(StringNode node);
  std::shared_ptr<Value> visit_boolean(BooleanNode node);
  std::shared_ptr<Value> visit_binary_op(BinaryOpNode node);
  std::shared_ptr<Value> visit_unary_op(UnaryOpNode node);
  std::shared_ptr<Value> visit_var_assign(VarAssignNode node);
  std::shared_ptr<Value> visit_var_reassign(VarReAssignNode node);
  std::shared_ptr<Value> visit_var_access(VarAccessNode node);
  std::shared_ptr<Value> visit_call(CallNode node);

public:
  SymbolTable* symbol_table;

  Interpreter(SymbolTable* _symbol_table);

  std::shared_ptr<Node> node;
  std::shared_ptr<Value> visit(std::shared_ptr<Node> node);
};