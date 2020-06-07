/**
 * Project Material Lab
 * @author Bruk Tedla
 */

#ifndef _3DVIEW_H
#define _3DVIEW_H

#include "../Editors/Editor.h"
#include "../../NodeGraph/MaterialGraph.h"
#include "../../Resources/Scene.h"

class _3DView : public Editor
{
private:
  /**
   * @brief Pointer to the current active scene.
   * 
   */
  Scene *scene;

public:
  /**
   * @brief Displays the scene with the graph's material.
   * 
   * @param graph 
   */
  void Display(MaterialGraph *graph);

  /**
   * @brief Changes the current active scene to @param scene
   * 
   * @param scene 
   */
  void UpdateScene(Scene *scene);

  /**
   * @brief Renders the scene with the update
   * 
   */
  void Update();
};

#endif //_3DVIEW_H
