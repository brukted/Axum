/**
 * Project Material Lab
 * @author Bruk Tedla
 */


#include "PreferenceManager.h"
#include "boost/lexical_cast.hpp"

/**
 * PreferenceManager implementation
 */

    void PreferenceManager::Startup(){
        this->load(PREF_FILE_NAME);
    }

    void PreferenceManager::Shutdown(){

    }

    void PreferenceManager::save(){
        this->save(PREF_FILE_NAME);
    }

    void PreferenceManager::save(const std::string filename){
        pt::write_json(filename,this->tree);
    }
    void PreferenceManager::load(const std::string filename){
        try{
            pt::read_json(filename,this->tree);
        }
        //handle exception that will be thrown if the file does not exist
        //set the property tree to blank tree
        catch(std::exception){
            this->tree = pt::ptree();
        }
    }

    /**
     *@param path relative path to put the preference e.g: bakery.useGPU
     *@param value value of the prefence to put 
    **/
    template<typename T>
    void PreferenceManager::putPreference(std::string path,T value){
        this->tree.put(path,value);
    }
    /**
     *@param path relative path to put the preference e.g: 3dview.HDRIpaths
     *@param values values of the prefence to put 
    **/
    template<typename T>
    void PreferenceManager::putPreferenceArray(std::string path,std::vector<T> values){
        BOOST_FOREACH(const std::string &name,values)
        this->tree.add(path+".item",name);
    }
    /**
     *@param path relative path to put the preference e.g: bakery.useGPU
     *@param defaultValue value to return if the preference doesn't exist
     *@return value of the preference
    **/
    template<typename T>
    T PreferenceManager::getPreference(std::string path,T defaultValue){
        return this->tree.get<T>(path,defaultValue);
    }
    /**
     *@param path relative path to put the preference e.g: 3dview.HDRIpaths
     *@param return array of values of the preference
     *@throw (May be)exception if the preference does not exist
    **/
    template<typename T>
    std::vector<T> PreferenceManager::getPreferenceArray(std::string path){
        std::vector<T> values;
        BOOST_FOREACH(pt::ptree::value_type &v,this->tree.get_child(path)){
            values.insert(boost::lexical_cast<T>(&v.second.data()));
        }
        return values;
    }