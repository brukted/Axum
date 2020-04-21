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

class PreferenceManager {
private:
    pt::ptree tree;
    void load(const std::string filename);
    void save(const std::string filename);
public:
    PreferenceManager(){};
    ~PreferenceManager(){};
    
    void Startup();

    void Shutdown();

    void save();
    /**
     *@param path relative path to put the preference e.g: bakery.useGPU
     *@param value value of the prefence to put 
    **/
    template<typename T>
    inline void putPreference(std::string path,T value);
    /**
     *@param path relative path to put the preference e.g: 3dview.HDRIpaths
     *@param values values of the prefence to put 
    **/
    template<typename T>
    inline void putPreferenceArray(std::string path,std::vector<T> values);
    /**
     *@param path relative path to put the preference e.g: bakery.useGPU
     *@return value of the preference
    **/
    template<typename T>
    inline T getPreference(std::string path,T defaultValue);
    /**
     *@param path relative path to put the preference e.g: 3dview.HDRIpaths
     *@param return array of values of the preference
    **/
    template<typename T>
    inline std::vector<T> getPreferenceArray(std::string path);
};

#endif //_PREFERENCEMANAGER_H
