#include "ReturnNode.hpp"

ReturnNode::ReturnNode(std::shared_ptr<Node> _node)
: Node(NodeType::RETURN, _node->start, _node->end), node(_node) {}

std::string ReturnNode::to_string(int depth)
{
  return "ReturnNode(" + node->to_string() + ")";
}