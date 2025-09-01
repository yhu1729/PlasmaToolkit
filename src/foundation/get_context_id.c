#include "pt/foundation/context.h"

pt_error
pt_get_context_id(pt_context target, size_t id[1]) {
  pt_context_interface interface = _PT_GET_CONTEXT_INTERFACE(target);

  return interface->get_id(target, id);
}
