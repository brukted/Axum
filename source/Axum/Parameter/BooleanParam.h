/**
 * Project Material Lab
 * @author Bruk Tedla
 */


#ifndef _BOOLEANPARAM_H
#define _BOOLEANPARAM_H

#include "Param.h"
#include "boost/serialization/access.hpp"
#include "boost/serialization/split_member.hpp"
#include "boost/serialization/version.hpp"

class BooleanParam: public Param {
private:
bool value;
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
BOOST_CLASS_VERSION(BooleanParam,1)
#endif //_BOOLEANPARAM_H
