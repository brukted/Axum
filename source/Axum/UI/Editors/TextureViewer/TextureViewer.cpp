/**
 * Project Material Lab
 * @author Bruk Tedla
 */

#include "TextureViewer.h"

/**
 * TextureViewer implementation
 */

namespace Axum::UI::Editor {
int TextureViewer::imageWidth;
int TextureViewer::imageHeight;
gl::GLuint TextureViewer::mTextureID = 0;
bool TextureViewer::isImageTexture = false;
gl::GLuint TextureViewer::gridTextureID = 0;

TextureViewer::TextureViewer() {}

void TextureViewer::drawToolBar() {}

void TextureViewer::draw() {
  static const auto &io = ImGui::GetIO();
  if (!ImGui::Begin(_("Texture viewer"), 0,
                    ImGuiWindowFlags_NoScrollWithMouse |
                        ImGuiWindowFlags_NoScrollbar)) {
    ImGui::End();
    return;
  }
  if (ImGui::IsMouseDown(ImGuiMouseButton_Middle) && ImGui::IsWindowFocused() &&
      ImGui::IsWindowHovered()) {
    auto const mouseDelta = io.MouseDelta;
    auto const windowSize = ImGui::GetWindowSize();
    ImVec2 deltaScroll = {mouseDelta.x, mouseDelta.y};
    ImGui::SetScrollX(ImGui::GetScrollX() + deltaScroll.x);
    ImGui::SetScrollY(ImGui::GetScrollY() + deltaScroll.y);
  }
  if (io.MouseWheel && ImGui::IsWindowFocused() && ImGui::IsWindowHovered()) {
    zoom = std::clamp((zoom + (io.MouseWheel * 0.1f)), MIN_ZOOM, MAX_ZOOM);
  }
  {
    // TODO: Make more centered
    // FIXME: GetContentRegionAvail is not the true size of the window's
    //  content region
    ImVec2 cursorPos = {0, 0};
    auto availSpace = ImGui::GetContentRegionAvail();
    cursorPos.x = (availSpace.x - (imageWidth * zoom)) / 2;
    cursorPos.y = (availSpace.y - (imageHeight * zoom)) / 2;
    ImGui::SetCursorPos(cursorPos);
  }
  if (mTextureID != 0)
    ImGui::Image((ImTextureID)mTextureID,
                 {zoom * imageWidth, zoom * imageHeight});
  drawToolBar();
  ImGui::End();
}

void TextureViewer::openImageTexture(ResourceType::ImageTexture *texture) {
  if (isImageTexture)
    gl::glDeleteTextures(1, &mTextureID);
  isImageTexture = true;
  gl::glGenTextures(1, &mTextureID);
  gl::glBindTexture(gl::GL_TEXTURE_2D, mTextureID);
  gl::glTexParameteri(gl::GL_TEXTURE_2D, gl::GL_TEXTURE_WRAP_S,
                      gl::GL_CLAMP_TO_EDGE);
  gl::glTexParameteri(gl::GL_TEXTURE_2D, gl::GL_TEXTURE_WRAP_T,
                      gl::GL_CLAMP_TO_EDGE);
  gl::glTexParameteri(gl::GL_TEXTURE_2D, gl::GL_TEXTURE_MIN_FILTER,
                      gl::GL_NEAREST);
  gl::glTexParameteri(gl::GL_TEXTURE_2D, gl::GL_TEXTURE_MAG_FILTER,
                      gl::GL_NEAREST);
  // TODO: Support different channel combinations
  gl::glTexImage2D(gl::GL_TEXTURE_2D, 0, gl::GL_RGBA8, texture->width,
                   texture->height, 0, gl::GL_RGBA, gl::GL_UNSIGNED_BYTE,
                   texture->data.data());
  imageWidth = texture->width;
  imageHeight = texture->height;
}

void TextureViewer::openGPUTexture(gl::GLuint textureId, int width,
                                   int height) {
  if (isImageTexture)
    gl::glDeleteTextures(1, &mTextureID);
  isImageTexture = false;
  mTextureID = textureId;
  imageWidth = width;
  imageHeight = height;
}

} // namespace Axum::UI::Editor