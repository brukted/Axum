/**
 * Project Material Lab
 * @author Bruk Tedla
 */

#ifndef _LOGICSOCKET_H_
#define _LOGICSOCKET_H_

#include "../InputSocket.h"

namespace Axum {
namespace NodeGraph::Logic {

enum class DataType {
  boolean,
  float1,
  float2,
  float3,
  float4,
  int1,
  int2,
  int3,
  int4,
  text
};

class LogicInSocket : public InputSocket {
private:
  DataType type = DataType::int1;

public:
  DataType GetType() const;

  void SetType(DataType _type);
};
} // namespace NodeGraph::Logic
} // namespace Axum
#endif //_LOGICSOCKET_H_
