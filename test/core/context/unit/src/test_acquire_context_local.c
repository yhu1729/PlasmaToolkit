#include "pt/core/context/local.h"
#include "pt/test/check.h"
#include "pt/test/expect.h"
#include "pt/test/unit.h"

void
test_local(void) {
  pt_context_local target;
  pt_expect(PT_TAG_SUCCESS, pt_acquire_context_local(&target));
  pt_check(!(target->active));
  pt_check_same(target->rank, 0);
  pt_check_same(target->size, 0);
  pt_release_context_local(target);

  pt_check_ok();
}

PT_TEST_LIST({test_local, "Acquire local context"});

PT_TEST_UNIT_MAIN
