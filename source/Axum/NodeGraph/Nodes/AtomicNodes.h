/**
 * Project Material Lab
 * @author Bruk Tedla
 */

#ifndef _ATOMICNODES_H
#define _ATOMICNODES_H

#include "MaterialNode.h"

/**
 * All Atomic nodes are defined here
 **/
namespace Axum::NodeGraph::Material {

class BlurNode : public MaterialNode {};

class TextureNode : public MaterialNode {};
class CurveNode : public MaterialNode {};
class DirectionalWrapNode : public MaterialNode {};
class EmbossNode : public MaterialNode {};
class GradientDynamicNode : public MaterialNode {};
class HSLNode : public MaterialNode {};
class InputColorNode : public MaterialNode {};
class NormalNode : public MaterialNode {};
class ShaderNode : public MaterialNode {};
class SVGNode : public MaterialNode {};
class TextNode : public MaterialNode {};
class SolidColorNode : public MaterialNode {};
class BlendNode : public MaterialNode {};
class ChannelShuffleNode : public MaterialNode {};
class DirectionalBlurNode : public MaterialNode {};
class DistanceNode : public MaterialNode {};
class FxMapNode : public MaterialNode {};
class GradientNode : public MaterialNode {};
class InputGrayscaleNode : public MaterialNode {};
class LevelsNode : public MaterialNode {};
class OutputNode : public MaterialNode {};
class SharpenNode : public MaterialNode {};
class Transform2DNode : public MaterialNode {};
class WrapNode : public MaterialNode {};

} // namespace Axum::NodeGraph::Material
#endif //_ATOMICNODES_H
