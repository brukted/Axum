/**
 * Project Material Lab
 * @author Bruk Tedla
 */


#ifndef _GRAPHPARAM_H
#define _GRAPHPARAM_H

#include "Param.h"
#include "ParamCollection.h"
#include "boost/serialization/access.hpp"
#include "boost/serialization/split_member.hpp"
#include "boost/serialization/version.hpp"

class GraphParam:public ParamCollection {

friend class boost::serialization::access;

private:
template<class Archive>
void save(Archive & ar, const unsigned int version) const
{
	ar &boost::serialization::base_object<ParamCollection>(*this);
}

template<class Archive>
void load(Archive & ar, const unsigned int version)
{
	ar &boost::serialization::base_object<ParamCollection>(*this);
}
BOOST_SERIALIZATION_SPLIT_MEMBER()
};
BOOST_CLASS_VERSION(GraphParam,1)

#endif //_GRAPHPARAM_H
