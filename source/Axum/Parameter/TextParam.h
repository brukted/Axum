/**
 * Project Material Lab
 * @author Bruk Tedla
 */

#ifndef _TEXTPARAM_H
#define _TEXTPARAM_H

#include <string>
#include "Param.h"
#include "boost/serialization/access.hpp"
#include "boost/serialization/split_member.hpp"
#include "boost/serialization/string.hpp"
#include "boost/serialization/version.hpp"

class TextParam : public Param
{
	friend class boost::serialization::access;

private:
	std::string value;

public:
	TextParam(unsigned int _uid, std::string &_name, std::string &_value);

	TextParam(unsigned int _uid, const char *_name, const char *_value);

	std::string &GetValue();

	void SetValue(std::string &value);

	void setValue(const char *name);

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
BOOST_CLASS_VERSION(TextParam, 1)
#endif //_TEXTPARAM_H
