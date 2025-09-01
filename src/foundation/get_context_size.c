#include "pt/foundation/context.h"

pt_error
pt_get_context_size(pt_context target, size_t size[1]) {
  pt_context_interface interface = _PT_GET_CONTEXT_INTERFACE(target);

  return interface->get_size(target, size);
}
