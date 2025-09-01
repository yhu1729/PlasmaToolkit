#include "pt/foundation/context.h"

static pt_error
_pt_context_set_id(pt_context target, const size_t id) {
  target->id = id;

  return PT_TAG_SUCCESS;
}

static pt_error
_pt_context_get_id(pt_context target, size_t id[1]) {
  *id = target->id;

  return PT_TAG_SUCCESS;
}

static pt_error
_pt_context_get_size([[maybe_unused]] pt_context target, size_t size[1]) {
  *size = 1;

  return PT_TAG_SUCCESS;
}

pt_context
pt_acquire_context_impl_local(void) {
  struct _pt_context_local_t* c = malloc(sizeof *c);

  c->interface.context.type = PT_TAG_LOCAL;
  c->interface.context.id = 0;
  c->interface.set_id = _pt_context_set_id;
  c->interface.get_id = _pt_context_get_id;
  c->interface.get_size = _pt_context_get_size;

  return &(c->interface.context);
}
