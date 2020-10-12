/**
 * Project Material Lab
 * @author Bruk Tedla
 */

#ifndef _AXUM_UI_EDITORS_TEXTURE_VIEWER_H
#define _AXUM_UI_EDITORS_TEXTURE_VIEWER_H

#include "../Editor.h"
#include "IO/ImageIO.h"
#include "ResourceTypes/ImageTexture.h"
#include "Utils/Log/Log.h"
#include "Utils/Translation/Translation.h"
#include <algorithm>
#include <glbinding/gl43core/gl.h>
#include <glbinding/glbinding.h>
#include <math.h>

namespace Axum::UI {
namespace Editor {
constexpr float MAX_ZOOM = 10.f;
constexpr float MIN_ZOOM = 0.05f;
class TextureViewer : public Editor {
private:
  float zoom = 1;
  float panning = 0;
  static gl::GLuint gridTextureID;
  static int imageWidth;
  static int imageHeight;
  static gl::GLuint mTextureID;
  static bool isImageTexture;
  void drawToolBar();

public:
  TextureViewer();
  void draw() override;
  static void openImageTexture(ResourceType::ImageTexture *texture);
  static void openGPUTexture(gl::GLuint textureId, int width, int height);
};

} // namespace Editor
} // namespace Axum::UI
#endif //_AXUM_UI_EDITORS_TEXTURE_VIEWER_H
