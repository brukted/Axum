/**
 * Project Material Lab
 * @author Bruk Tedla
 */

#ifndef _VIEWPORT_H
#define _VIEWPORT_H

#include "../Editor.h"

namespace Axum::UI {
namespace Editor {

class Viewport : public Editor {
public:
  Viewport();
  void draw() override;
};

} // namespace Editor
} // namespace Axum::UI
#endif //_VIEWPORT_H
