/**
 * Project Material Lab
 * @author Bruk Tedla
 */

#ifndef _FLOAT3PARAM_H
#define _FLOAT3PARAM_H

#include "Param.h"
#include "boost/serialization/access.hpp"
#include "boost/serialization/array.hpp"
#include "boost/serialization/split_member.hpp"
#include "boost/serialization/version.hpp"

class Float3Param : public Param
{
	friend class boost::serialization::access;

private:
	std::array<float, 3> value;

public:
	std::array<float, 3> GetValue() const;

	void SetValue(std::array<float, 3>);

private:
	template <class Archive>
	void save(Archive &ar, const unsigned int version) const
	{
		ar &boost::serialization::base_object<Param>(*this);
		ar &value;
	}

	template <class Archive>
	void load(Archive &ar, const unsigned int version)
	{
		ar &boost::serialization::base_object<Param>(*this);
		ar &value;
	}
	BOOST_SERIALIZATION_SPLIT_MEMBER()
};
BOOST_CLASS_VERSION(Float3Param, 1)
#endif //_FLOAT3PARAM_H
