/**
 * Project Material Lab
 * @author Bruk Tedla
 */

#ifndef _ENUMPARAM_H
#define _ENUMPARAM_H

#include "Param.h"
#include <map>
#include <string>
#include "boost/serialization/access.hpp"
#include "boost/serialization/map.hpp"
#include "boost/serialization/split_member.hpp"
#include "boost/serialization/version.hpp"

class EnumParam : public Param
{
	friend class boost::serialization::access;

public:
	/**
	 * @brief Construct a new Enum Param object
	 * 
	 * @param _uid Unique id of the parameter.
	 * @param _name Name of the parameter.
	 * @param _enums Map of possible values.
	 * @param _value Default value for the parameter.
	 */
	EnumParam(unsigned int _uid, std::string &_name, std::map<int, std::string> _enums, int _value);

	/**
	 * @brief Construct a new Enum Param object
	 * 
	 * @param _uid Unique id of the parameter.
	 * @param _name Name of the parameter.
	 * @param _enums Map of possible values.
	 * @param _value Default value for the parameter.
	 */
	EnumParam(unsigned int _uid, const char *_name, std::map<int, std::string> _enums, int _value);

private:
	EnumParam(){};

	std::map<int, std::string> enums;
	
	int value;

public:
	int SetValue() const;

	int GetValue() const;

	void SetValue(int key);

	std::string &ToString(int key);

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
BOOST_CLASS_VERSION(EnumParam, 1)
#endif //_ENUMPARAM_H
