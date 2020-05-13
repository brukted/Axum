/**
 * Project Material Lab
 * @author Bruk Tedla
 */

#ifndef _PARAMCOLLECTION_H
#define _PARAMCOLLECTION_H

#include <vector>
#include "Param.h"
#include "boost/serialization/access.hpp"
#include "boost/serialization/split_member.hpp"
#include "boost/serialization/vector.hpp"
#include "boost/serialization/version.hpp"

class ParamCollection : public Param
{
	friend class boost::serialization::access;

protected:
	std::vector<Param> Params;

public:
	/**
 * @param uid unique identifer of the parameter
 * @return a pointer to a sub parameter
 * 
 */
	Param &GetParameter(unsigned int uid);

	/**
 * @param Parameter
 */
	void AddParameter(Param Parameter);

private:
	template <class Archive>
	void save(Archive &ar, const unsigned int version) const
	{
		ar &boost::serialization::base_object<Param>(*this);
		ar &Params;
	}

	template <class Archive>
	void load(Archive &ar, const unsigned int version)
	{
		ar &boost::serialization::base_object<Param>(*this);
		ar &Params;
	}
	BOOST_SERIALIZATION_SPLIT_MEMBER()
};
BOOST_CLASS_VERSION(ParamCollection, 1)
#endif //_PARAMCOLLECTION_H
