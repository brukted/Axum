/**
 * Project Material Lab
 * @author Bruk Tedla
 */

#ifndef _PARAM_H
#define _PARAM_H

#include <string>
#include <vector>
#include "../UI/Widgets/ParamUI.h"
#include "boost/serialization/access.hpp"
#include "boost/serialization/string.hpp"
#include "boost/serialization/split_member.hpp"
#include "boost/serialization/vector.hpp"
#include "boost/serialization/version.hpp"

enum UIType
{
	Slider,
	Angle,
	Color
};
class Param
{
	friend class boost::serialization::access;

protected:
	std::string Name;
	unsigned int uid;
	UIType mUIType;
	std::vector<UIType> SupportedTypes;

public:
	/**
 * Displays the data to the ui.
 */
	virtual ParamUI GetEditUI();

	virtual ParamUI GetDisplayUI();

private:
	template <class Archive>
	void save(Archive &ar, const unsigned int version) const
	{
		ar &uid;
		ar &Name;
		ar &mUIType;
	}

	template <class Archive>
	void load(Archive &ar, const unsigned int version)
	{
		ar &uid;
		ar &Name;
		ar &mUIType;
	}
	BOOST_SERIALIZATION_SPLIT_MEMBER()
};
BOOST_CLASS_VERSION(Param, 1)
#endif //_PARAM_H
