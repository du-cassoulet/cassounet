#pragma once

#include <string>
#include "../Position.hpp"

enum class NodeType
{
  UNKNOWN,
  NUMBER,
  STRING,
  BOOLEAN,
  NULL_NODE,
  BINARY_OPERATION,
  UNARY_OPERATION,
  VAR_ASSIGN,
  VAR_REASSIGN,
  VAR_ACCESS,
  CALL,
  RETURN,
  LIST,
  IF
};

struct Node
{
  NodeType type;
  Position start;
  Position end;

  Node(NodeType _type, const Position& _start, const Position& _end);
  
  virtual std::string to_string(int depth = 0) = 0;
};