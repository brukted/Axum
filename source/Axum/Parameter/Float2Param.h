/**
 * Project Material Lab
 * @author Bruk Tedla
 */


#ifndef _FLOAT2PARAM_H
#define _FLOAT2PARAM_H

#include "Param.h"
#include "boost/serialization/access.hpp"
#include "boost/serialization/array.hpp"
#include "boost/serialization/split_member.hpp"
#include "boost/serialization/version.hpp"


class Float2Param: public Param {
friend class boost::serialization::access;
private:
	float value[2];
private:
template<class Archive>
void save(Archive & ar, const unsigned int version) const
{
	ar &boost::serialization::base_object<Param>(*this);
	ar &value;
}

template<class Archive>
void load(Archive & ar, const unsigned int version)
{
	ar &boost::serialization::base_object<Param>(*this);
	ar &value;
}
BOOST_SERIALIZATION_SPLIT_MEMBER()
};
BOOST_CLASS_VERSION(Float2Param,1)
#endif //_FLOAT2PARAM_H
