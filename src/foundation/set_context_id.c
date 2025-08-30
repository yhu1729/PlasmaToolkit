#include "pt/foundation/context.h"

pt_error
pt_set_context_id(pt_context target, const size_t id) {
  pt_context_interface interface = _PT_GET_CONTEXT_INTERFACE(target);

  return interface->set_id(target, id);
}
