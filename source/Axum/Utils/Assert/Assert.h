/**
 * Project Material Lab
 * @author Bruk Tedla
 */

#ifndef __ASSERT_H__
#define __ASSERT_H__

#include "Utils/Log/Log.h"
#include <boost/preprocessor/stringize.hpp>
#include <boost/preprocessor/variadic.hpp>

#define AX_CORE_ASSERT_MSG(expression, msg)                                    \
  if ((expression) == 0) {                                                     \
    AX_LOG_CORE_ERROR(msg)                                                     \
  }

#define AX_CORE_ASSERT(expression)                                             \
  if ((expression) == 0) {                                                     \
    AX_LOG_CORE_ERROR("Assertion {} failed.", BOOST_PP_STRINGIZE(expression))  \
  }

#define AX_EDITOR_ASSERT_MSG(expression, msg)                                  \
  if ((expression) == 0) {                                                     \
    AX_LOG_EDITOR_ERROR(msg)                                                   \
  }

#define AX_EDITOR_ASSERT(expression)                                           \
  if ((expression) == 0) {                                                     \
    AX_LOG_EDITOR_ERROR("Assertion {} failed.",                                \
                        BOOST_PP_STRINGIZE(expression))                        \
  }

#endif // __ASSERT_H__