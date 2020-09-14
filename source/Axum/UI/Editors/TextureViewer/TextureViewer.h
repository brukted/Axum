/**
 * Project Material Lab
 * @author Bruk Tedla
 */

#ifndef _TEXTURE_VIEWER_H
#define _TEXTURE_VIEWER_H

#include "../Editor.h"
#define _(text) text

namespace Axum::UI {
namespace Editor {

class TextureViewer : public Editor {
private:
  float zoom = 1;

public:
  TextureViewer();
  void draw() override;
};

} // namespace Editor
} // namespace Axum::UI
#endif //_TEXTURE_VIEWER_H
