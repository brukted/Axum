/**
 * Project Material Lab
 * @author Bruk Tedla
 */

#ifndef _PREFERENCEMANAGER_H
#define _PREFERENCEMANAGER_H

#define PREF_FILE_NAME "placeholder"

#include <string>
#include <vector>
#include <exception>
#include "boost/property_tree/ptree.hpp"
#include "boost/property_tree/json_parser.hpp"
#include "boost/foreach.hpp"
#include <boost/lexical_cast.hpp>

namespace pt = boost::property_tree;

class PreferenceManager
{
public:
    static PreferenceManager &getInstance()
    {
        static PreferenceManager instance;
        return instance;
    }

private:
    pt::ptree tree;
    void load(const std::string filename);
    void save(const std::string filename);
    PreferenceManager(){};
    ~PreferenceManager(){};

public:
    PreferenceManager(PreferenceManager const &) = delete;
    void operator=(PreferenceManager const &) = delete;
    void Startup();

    void Shutdown();

    void save();
    /**
     *@param path relative path to put the preference e.g: bakery.useGPU
     *@param value value of the prefence to put 
    **/
    template <typename T>
    void putPreference(std::string path, T value)
    {
        this->tree.put(path, value);
    }
    /**
     *@param path relative path to put the preference e.g: 3dview.HDRIpaths
     *@param values values of the prefence to put 
    **/
    template <typename T>
    void putPreferenceArray(std::string path, std::vector<T> values)
    {
        BOOST_FOREACH (const std::string &name, values)
            this->tree.add(path + ".item", name);
    }
    /**
     *@param path relative path to put the preference e.g: bakery.useGPU
     *@param defaultValue value to return if the preference doesn't exist
     *@return value of the preference
    **/
    template <typename T>
    T getPreference(std::string path, T defaultValue)
    {
        return this->tree.get<T>(path, defaultValue);
    }
    /**
     *@param path relative path to put the preference e.g: 3dview.HDRIpaths
     *@param return array of values of the preference
     *@throw (May be)exception if the preference does not exist
    **/
    template <typename T>
    std::vector<T> getPreferenceArray(std::string path)
    {
        std::vector<T> values;
        BOOST_FOREACH (pt::ptree::value_type &v, this->tree.get_child(path))
        {
            values.insert(boost::lexical_cast<T>(&v.second.data()));
        }
        return values;
    }
};

#endif //_PREFERENCEMANAGER_H
