/**
 * Project Material Lab
 * @author Bruk Tedla
 */


#ifndef _INTEGER3PARAM_H
#define _INTEGER3PARAM_H

#include "Param.h"
#include "boost/serialization/access.hpp"
#include "boost/serialization/split_member.hpp"
#include "boost/serialization/array.hpp"
#include "boost/serialization/version.hpp"

class Integer3Param: public Param {
friend class boost::serialization::access;
private:
std::array<int,3> value;

public:
std::array<int,3> GetValue() const;

void SetValue(std::array<int,3>);

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
BOOST_CLASS_VERSION(Integer3Param,1)
#endif //_INTEGER3PARAM_H
