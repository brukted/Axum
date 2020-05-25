/**
 * Project Material Lab
 * @author Bruk Tedla
 */

#ifndef _RESOURCE_H
#define _RESOURCE_H

#include <string>
#include "../UI/Widgets/ExplorerItemUI.h"
#include "../Parameter/ParamCollection.h"
#include "boost/serialization/access.hpp"
#include "boost/serialization/split_member.hpp"
#include "boost/serialization/string.hpp"
#include "boost/serialization/version.hpp"
#include "boost/serialization/vector.hpp"
#include "../Parameter/TextParam.h"
#include "../Parameter/EnumParam.h"
#include "../Parameter/BooleanParam.h"
#include <boost/filesystem.hpp>

class Resource
{
	friend class boost::serialization::access;
	enum ResourceType
	{
		Linked,
		Embedded
	};
	enum PathType
	{
		Relative,
		Absolute
	};

public:
	Resource();
	ResourceType mType = ResourceType::Linked;
	unsigned int uid;

	/**
	 * @brief Location of the resource including the filename and extension.
	 * 
	 */
	std::string mPath;
	ParamCollection mParams;
	ParamCollection attributes{mParams.GenerateUid(), "Attributes"};
	TextParam name{attributes.GenerateUid(), "Name", "unknown"};
	TextParam description{attributes.GenerateUid(), "Description", ""};
	TextParam category{attributes.GenerateUid(), "category", ""};
	TextParam label{attributes.GenerateUid(), "Label", ""};
	TextParam author{attributes.GenerateUid(), "Author", ""};
	TextParam authorUrl{attributes.GenerateUid(), "Author URL", ""};
	TextParam tags{attributes.GenerateUid(), "Tags", ""};
	BooleanParam showInManager{attributes.GenerateUid(), "Show in library", true};
	EnumParam pathType{attributes.GenerateUid(), "Path type", std::map<int, std::string>{{PathType::Relative, "Relative"}, {PathType::Absolute, "Absolute"}}, PathType::Absolute};

	/**
 	* @brief Opens the resource in the appropriate editor.
 	*/
	virtual void Open();

	/**
	 * @brief Returns a UI to display the resource the UI is an instance odf ExplorerItemUI or child of it.
	 * 
	 * @return ExplorerItemUI 
	 */
	ExplorerItemUI GetUI();

	void setPath(char const *);

	/**
	 * @brief Makes the path type to relative and the path relative to @param pkgPath.
	 * This method has no effect if the resource is embedded.
	 * 
	 * @param pkgPath Absolute path of the package this resource is located 
	 */
	void makeRelative(std::string &pkgPath);

	/** @brief Makes the path type to absolute and the path absolute to @param pkgPath.
	 * This method has no effect if the resource is embedded.
	 * 
	 * @param pkgPath Absolute path of the package this resource is located 
	 */
	void makeAbsolute(std::string &pkgPath);

private:
	template <class Archive>
	void save(Archive &ar, const unsigned int version) const
	{
		ar &mType, &uid, &mPath, &name, &description, &category, &label, &author, &authorUrl, &tags, &showInManager, &pathType;
		ar &mParams, &attributes;
	}

	template <class Archive>
	void load(Archive &ar, const unsigned int version)
	{
		ar &mType, &uid, &mPath, &name, &description, &category, &label, &author, &authorUrl, &tags, &showInManager, &pathType;
		ar &mParams, &attributes;
	}
	BOOST_SERIALIZATION_SPLIT_MEMBER()
};
BOOST_CLASS_VERSION(Resource, 1)
#endif //_RESOURCE_H
