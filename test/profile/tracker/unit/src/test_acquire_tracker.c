#include "pt/profile/tracker.h"
#include "pt/test/check.h"
#include "pt/test/expect.h"
#include "pt/test/unit.h"

void
test_single(void) {
  pt_tracker target;
  pt_expect(PT_TAG_SUCCESS, pt_acquire_tracker(&target, "test", 1));
  pt_check_same(target->name, "test");
  pt_check(!(target->active));
  pt_check_same(target->timer->name, "test");
  pt_check(!(target->timer->active));
  pt_check_same(target->port_capacity, 1);
  pt_check_same(target->port_size, 0);
  pt_release_tracker(target);
}

PT_TEST_LIST({test_single, "Acquire a single tracker"});

PT_TEST_UNIT_MAIN
