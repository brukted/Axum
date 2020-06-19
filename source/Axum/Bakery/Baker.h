/**
 * Project Material Lab
 * @author Bruk Tedla
 */

#ifndef _BAKER_H
#define _BAKER_H
#include "Parameter/ParamCollection.h"

namespace Axum {
namespace Bakery {

class Baker {
public:
  /**
   * The list of the baker's personal parameters.
   */
  Parameter::ParamCollection mParams;

  /**
   * @param *BakeryParms
   */
  void bake(Parameter::ParamCollection *BakeryParms);
};
} // namespace Bakery
} // namespace Axum
#endif //_BAKER_H
