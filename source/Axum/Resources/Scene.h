/**
 * Project Material Lab
 * @author Bruk Tedla
 */

#ifndef _SCENE_H
#define _SCENE_H

#include <vector>
#include "Resource.h"
#include "boost/serialization/access.hpp"
#include "boost/serialization/array.hpp"
#include "boost/serialization/base_object.hpp"
#include "boost/serialization/split_member.hpp"
#include "boost/serialization/vector.hpp"
#include "boost/serialization/version.hpp"

class Mesh
{
public:
	std::vector<float[3]> Vertices;
	std::vector<float[3]> Normals;
	std::vector<unsigned int> Indices;
	std::vector<Mesh> SubMeshs;
	int MaterialId;

private:
	bool NeedUpdate = true;
	template <class Archive>
	void save(Archive &ar, const unsigned int version) const
	{
		ar &Vertices;
		ar &Normals;
		ar &Indices;
		ar &SubMeshs;
		ar &MaterialId;
	}
	template <class Archive>
	void load(Archive &ar, const unsigned int version)
	{
		ar &Vertices;
		ar &Normals;
		ar &Indices;
		ar &SubMeshs;
		ar &MaterialId;
	}
	BOOST_SERIALIZATION_SPLIT_MEMBER()
};
BOOST_CLASS_VERSION(Mesh, 1)

class Scene : public Resource
{
	friend class boost::serialization::access;

public:
	std::vector<Mesh> meshs;

private:
	template <class Archive>
	void save(Archive &ar, const unsigned int version) const
	{
		ar &boost::serialization::base_object<Resource>(*this);
		ar &meshs;
	}

	template <class Archive>
	void load(Archive &ar, const unsigned int version)
	{
		ar &boost::serialization::base_object<Resource>(*this);
		ar &meshs;
	}
	BOOST_SERIALIZATION_SPLIT_MEMBER()
};
BOOST_CLASS_VERSION(Scene, 1)
#endif //_SCENE_H
