/**
 * Project Material Lab
 * @author Bruk Tedla
 */

#ifndef _LOGICNODES_H_
#define _LOGICNODES_H_

#include "LogicNode.h"

/**
 * All basic function nodes are defined here
 **/
namespace Axum::NodeGraph::Logic {

class AbsNode : public LogicNode {};
class AddNode : public LogicNode {};
class AndNode : public LogicNode {};
class ArcTan2Node : public LogicNode {};
class BoolNode : public LogicNode {};
class CartNode : public LogicNode {};
class CeilNode : public LogicNode {};
class CosNode : public LogicNode {};
class DivNode : public LogicNode {};
class DotNode : public LogicNode {};
class EqualNode : public LogicNode {};
class ExpoNode : public LogicNode {};
class FloatNode : public LogicNode {};
class Float2Node : public LogicNode {};
class Float3Node : public LogicNode {};
class Float4Node : public LogicNode {};
class FloorNode : public LogicNode {};
class GBoolNode : public LogicNode {};
class GFloatNode : public LogicNode {};
class GFloat2Node : public LogicNode {};
class GFloat3Node : public LogicNode {};
class GFloat4Node : public LogicNode {};
class GintNode : public LogicNode {};
class Gint2Node : public LogicNode {};
class Gint3Node : public LogicNode {};
class Gint4Node : public LogicNode {};
class GstrNode : public LogicNode {};
class GreaterNode : public LogicNode {};
class GreOrEqlNode : public LogicNode {};
class IfElseNode : public LogicNode {};
class IntNode : public LogicNode {};
class Int2Node : public LogicNode {};
class Int3Node : public LogicNode {};
class Int4Node : public LogicNode {};
class LerpNode : public LogicNode {};
class LogNode : public LogicNode {};
class Log2Node : public LogicNode {};
class LessNode : public LogicNode {};
class LessOrEqlNode : public LogicNode {};
class MaxNode : public LogicNode {};
class MinNode : public LogicNode {};
class ModNode : public LogicNode {};
class MultipleNode : public LogicNode {};
class NegationNode : public LogicNode {};
class NotNode : public LogicNode {};
class NotEqlNode : public LogicNode {};
class OrNode : public LogicNode {};
class Pow2Node : public LogicNode {};
class RandNode : public LogicNode {};
class SampColNode : public LogicNode {};
class SampGryNode : public LogicNode {};
class ScalarMultipleNode : public LogicNode {};
class SeqNode : public LogicNode {};
class SetNode : public LogicNode {};
class SinNode : public LogicNode {};
class SqrRootNode : public LogicNode {};
class StrNode : public LogicNode {};
class SubNode : public LogicNode {};
class SwizFloat1Node : public LogicNode {};
class SwizFloat2Node : public LogicNode {};
class SwizFloat3Node : public LogicNode {};
class SwizFloat4Node : public LogicNode {};
class SwizInt1Node : public LogicNode {};
class SwizInt2Node : public LogicNode {};
class SwizInt3Node : public LogicNode {};
class SwizInt4Node : public LogicNode {};
class TanNode : public LogicNode {};
class ToFloat1Node : public LogicNode {};
class ToFloat2Node : public LogicNode {};
class ToFloat3Node : public LogicNode {};
class ToFloat4Node : public LogicNode {};
class ToInt1Node : public LogicNode {};
class ToInt2Node : public LogicNode {};
class ToInt3Node : public LogicNode {};
class ToInt4Node : public LogicNode {};

} // namespace Axum::NodeGraph::Logic
#endif //_LOGICNODES_H_
