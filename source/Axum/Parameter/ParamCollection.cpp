/**
 * Project Material Lab
 * @author Bruk Tedla
 */

#include "ParamCollection.h"

/**
 * ParamCollection implementation
 *
 * List of parameters.
 */

namespace Axum::Parameter {

ParamCollection::ParamCollection(std::string ID, const char *_name,
                                 std::initializer_list<Param> params = {})
    : Param(ID, _name,"") {
  Params = params;
}

ParamCollection::ParamCollection(std::string ID, std::string &_name,
                                 std::initializer_list<Param> params = {})
    : Param(ID, _name,"") {
  Params = params;
}

Param &ParamCollection::FindParameter(std::string &ID) {
  for (auto &param : this->Params) {
    if ((param.ID == ID))
      return param;
  }
  AX_LOG_CORE_ERROR("Parameter collection ID : {} is requested a "
                    "non-existent parameter ID: {} .",
                    this->ID, ID)
  throw "Parameter doesn't exist";
}

Param &ParamCollection::FindParameter(const char * ID) {
  for (auto &param : this->Params) {
    if (strcmp(param.ID.c_str(),ID) == 0)
      return param;
  }
  AX_LOG_CORE_ERROR("Parameter collection ID : {} is requested a "
                    "non-existent parameter ID: {} .",
                    this->ID, ID)
  throw "Parameter doesn't exist";
}

void ParamCollection::AddParameter(Param parameter) {
  Params.push_back(parameter);
}

Gtk::Widget *ParamCollection::DrawDisplay() {
  AX_LOG_EDITOR_DEBUG("Drawing display widget for Param Collection {}", ID)
  auto box = new Gtk::Box();
  for (auto &param : Params) {
    AX_LOG_EDITOR_DEBUG("Drawing display widget for Param  {}", param.ID)
    auto widget = param.Draw();
    box->pack_end(*widget);
    AX_LOG_EDITOR_DEBUG("Finished Drawing display widget for Param {}",
                        param.ID)
  }
  AX_LOG_EDITOR_DEBUG("Finished Drawing display widget for Param Collection {}",
                      ID)
  return box;
}
} // namespace Axum::Parameter