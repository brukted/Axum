/**
 * Project Material Lab
 * @author Bruk Tedla
 */


#ifndef _FLOATPARAM_H
#define _FLOATPARAM_H

#include "Param.h"
#include "boost/serialization/access.hpp"
#include "boost/serialization/split_member.hpp"
#include "boost/serialization/version.hpp"


class FloatParam: public Param {
friend class boost::serialization::access;
private:
float value;

public:
float GetValue() const ;

void SetValue(float value);

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
BOOST_CLASS_VERSION(FloatParam,1)
#endif //_FLOATPARAM_H
