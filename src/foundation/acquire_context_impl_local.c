#include "pt/foundation/context.h"
#include "pt/foundation/error.h"
#include "pt/foundation/memory.h"

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

pt_error
pt_acquire_context_impl_local(pt_context target[1]) {
  pt_context_local context;
  pt_invoke(pt_malloc(&context, sizeof *context));

  context->interface.context.type = PT_TAG_LOCAL;
  context->interface.context.id = 0;
  context->interface.set_id = _pt_context_set_id;
  context->interface.get_id = _pt_context_get_id;
  context->interface.get_size = _pt_context_get_size;

  *target = &(context->interface.context);

  return PT_TAG_SUCCESS;
}
