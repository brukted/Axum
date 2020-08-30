#include "BooleanParam.h"
#include "EnumParam.h"
#include "Float2Param.h"
#include "Float3Param.h"
#include "Float4Param.h"
#include "FloatParam.h"
#include "Integer2Param.h"
#include "Integer3Param.h"
#include "Integer4Param.h"
#include "IntegerParam.h"
#include "Param.h"
#include "ParamCollection.h"
#include "ProxyParam.h"
#include "TextParam.h"
#include <list>
#include <vector>

/**
 * @brief Adds a method to pass parameters easily by bundling them into a
 * param* list.
 *
 */
#define LIST_PARAMETERS(...)                                                   \
public:                                                                        \
  virtual std::vector<Axum::Parameter::Param *> Params() {                     \
    std::vector<Axum::Parameter::Param *> params = {__VA_ARGS__};              \
    return params;                                                             \
  }

/**
 * @brief Adds a method to pass parameters easily by bundling them into a param*
 * list and merging with the base class's params.
 *
 */
#define ADD_PARAMTERS(parent, ...)                                             \
public:                                                                        \
  std::vector<Axum::Parameter::Param *> Params() override {                    \
    std::vector<Axum::Parameter::Param *> params = this->parent::Params();     \
    std::vector<Axum::Parameter::Param *> ThisParams = {__VA_ARGS__};          \
    std::vector<Axum::Parameter::Param *> merged;                              \
    merged.reserve(params.size() + ThisParams.size());                         \
    merged.insert(merged.end(), params.begin(), params.end());                 \
    merged.insert(merged.end(), ThisParams.begin(), ThisParams.end());         \
    return merged;                                                             \
  }
