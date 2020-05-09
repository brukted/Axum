/**
 * Project Material Lab
 * @author Bruk Tedla
 */

#include "PreferenceManager.h"
#include "boost/lexical_cast.hpp"

/**
 * PreferenceManager implementation
 */

void PreferenceManager::Startup()
{
    this->load(PREF_FILE_NAME);
}

void PreferenceManager::Shutdown()
{
}

void PreferenceManager::save()
{
    this->save(PREF_FILE_NAME);
}

void PreferenceManager::save(const std::string filename)
{
    pt::write_json(filename, this->tree);
}
void PreferenceManager::load(const std::string filename)
{
    try
    {
        pt::read_json(filename, this->tree);
    }
    //handle exception that will be thrown if the file does not exist
    //set the property tree to blank tree
    catch (std::exception)
    {
        this->tree = pt::ptree();
    }
}
