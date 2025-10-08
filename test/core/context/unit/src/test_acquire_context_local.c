#include "pt/config.h"
#include "pt/core/context.h"
#include "pt/test/check.h"
#include "pt/test/unit.h"

void
test_local(void) {
  pt_context target;
  pt_safe_invoke(pt_acquire(&target, PT_TAG_LOCAL));
  pt_check(target->type == PT_TAG_LOCAL);
  pt_check(!(target->active));
  pt_check(!(target->interface.local->active));
  pt_check_equal(target->interface.local->rank, 0, 0);
  pt_check_equal(target->interface.local->size, 0, 0);
  pt_release(target);
}

PT_TEST_LIST({test_local, "Acquire local context"});

PT_TEST_UNIT_MAIN
