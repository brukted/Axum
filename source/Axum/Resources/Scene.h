/**
 * Project Material Lab
 * @author Bruk Tedla
 */


#ifndef _SCENE_H
#define _SCENE_H

#include<vector>
#include "Resource.h"


class Scene: public Resource {
public:
	class Mesh {
	public: 
		std::vector<float[3]> Vertices;
		std::vector<float[3]> Normals;
		std::vector<unsigned int> Indices;
		std::vector<Mesh> SubMeshs;
		int MaterialId;
	};
	std::vector<Mesh> meshs;
};

#endif //_SCENE_H
