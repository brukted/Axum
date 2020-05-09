/**
 * Project Material Lab
 * @author Bruk Tedla
 */

#ifndef _GUIINFO_H
#define _GUIINFO_H

#include "boost/serialization/access.hpp"
#include "boost/serialization/version.hpp"
#include "boost/serialization/split_member.hpp"
class GUIInfo
{
public:
	int X = 0;
	int Y = 0;
	bool isHidden = false;
	//serialization
private:
	friend class boost::serialization::access;
	template <class Archive>
	void save(Archive &ar, const unsigned int version) const
	{
		ar &X;
		ar &Y;
		ar &isHidden;
	}
	template <class Archive>
	void load(Archive &ar, const unsigned int version)
	{
		ar &X;
		ar &Y;
		ar &isHidden;
	}
	BOOST_SERIALIZATION_SPLIT_MEMBER()
public:
	GUIInfo();
};
BOOST_CLASS_VERSION(GUIInfo, 1)
#endif //_GUIINFO_H
