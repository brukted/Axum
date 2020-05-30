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
    AX_LOG_EDITOR_TRACE(fmt::format("Loading preferences from {}", preferencesPath))
    load();
}

void PreferenceManager::Shutdown()
{
    AX_LOG_EDITOR_TRACE(fmt::format("Writing preferences to {}", preferencesPath))
    save();
}

void PreferenceManager::save()
{
    std::ofstream ofs{preferencesPath};
    pt::write_json(ofs, this->tree);
}

void PreferenceManager::load()
{
    try
    {
        std::ifstream ifs{preferencesPath};
        pt::read_json(ifs, this->tree);
    }
    //handle exception that will be thrown if the file does not exist
    //set the property tree to blank tree
    catch (boost::property_tree::json_parser_error e)
    {
        //TODO: Initialize ptree to default preferences as this will happen on the very first run.
        AX_LOG_EDITOR_ERROR("Can't load preferences.")
        this->tree = pt::ptree();
    }
}
