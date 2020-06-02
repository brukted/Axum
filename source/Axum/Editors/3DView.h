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
public:
   /**
 * @param *graph
 */
   void Display(MaterialGraph *graph);

   /**
 * @param *scene
 */
   void UpdateScene(Scene *scene);

   void Update();
};

#endif //_3DVIEW_H
