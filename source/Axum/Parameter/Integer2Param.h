/**
 * Project Material Lab
 * @author Bruk Tedla
 */


#ifndef _INTEGER2PARAM_H
#define _INTEGER2PARAM_H

#include "Param.h"
#include "boost/serialization/access.hpp"
#include "boost/serialization/split_member.hpp"
#include "boost/serialization/array.hpp"
#include "boost/serialization/version.hpp"

class Integer2Param: public Param {
friend class boost::serialization::access;
private:
std::array<int,2> value;

public:
std::array<int,2> GetValue() const;

void SetValue(std::array<int,2>);

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
BOOST_CLASS_VERSION(Integer2Param,1)
#endif //_INTEGER2PARAM_H
