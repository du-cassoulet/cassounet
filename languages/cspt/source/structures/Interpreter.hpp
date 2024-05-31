#pragma once

#include <string>
#include <memory>

#include "RTResult.hpp"
#include "SymbolTable.hpp"
#include "nodes/Node.hpp"
#include "interpreter/Value.hpp"
#include "interpreter/Number.hpp"
#include "interpreter/String.hpp"
#include "interpreter/Boolean.hpp"
#include "interpreter/List.hpp"
#include "interpreter/Null.hpp"
#include "interpreter/SymbolValue.hpp"
#include "interpreter/Function.hpp"
#include "interpreter/BuiltInFunction.hpp"
#include "nodes/NumberNode.hpp"
#include "nodes/StringNode.hpp"
#include "nodes/BooleanNode.hpp"
#include "nodes/NullNode.hpp"
#include "nodes/BinaryOpNode.hpp"
#include "nodes/UnaryOpNode.hpp"
#include "nodes/VarAssignNode.hpp"
#include "nodes/VarReAssignNode.hpp"
#include "nodes/VarAccessNode.hpp"
#include "nodes/CallNode.hpp"
#include "nodes/NullNode.hpp"
#include "nodes/ReturnNode.hpp"
#include "nodes/ListNode.hpp"
#include "nodes/IfNode.hpp"

struct Interpreter
{
private:
  RTResult visit_number(NumberNode node);
  RTResult visit_string(StringNode node);
  RTResult visit_boolean(BooleanNode node);
  RTResult visit_null(NullNode node);
  RTResult visit_binary_op(BinaryOpNode node);
  RTResult visit_unary_op(UnaryOpNode node);
  RTResult visit_var_assign(VarAssignNode node);
  RTResult visit_var_reassign(VarReAssignNode node);
  RTResult visit_var_access(VarAccessNode node);
  RTResult visit_call(CallNode node);
  RTResult visit_return(ReturnNode node);
  RTResult visit_list(ListNode node);
  RTResult visit_if(IfNode node);

public:
  SymbolTable* symbol_table;

  Interpreter(SymbolTable* _symbol_table);

  std::shared_ptr<Node> node;
  RTResult visit(std::shared_ptr<Node> node);
};