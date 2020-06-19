/**
 * Project Material Lab
 * @author Bruk Tedla
 */

#ifndef _BAKERY_H
#define _BAKERY_H

#include "Baker.h"
#include "Parameter/ParamCollection.h"
#include <vector>

namespace Axum::Bakery {

class Bakery {
public:
  Parameter::ParamCollection Parms;
  std::vector<Baker> Bakers;

  /**
   * Calls bake on all bakers.
   */
  void Bake();

  /**
   * @param baker
   */
  void AddBaker(Baker baker);
};

} // namespace Axum
#endif //_BAKERY_H
