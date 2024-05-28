#pragma once

#include <string>
#include "../Position.hpp"

enum class NodeType
{
  Unknown,
  Number,
  String,
  BinaryOperation,
  UnaryOperation
};

struct Node
{
  NodeType type = NodeType::Unknown;
  Position start;
  Position end;

  Node(const Position& _start, const Position& _end);
  
  virtual std::string to_string(int depth = 0) = 0;
};