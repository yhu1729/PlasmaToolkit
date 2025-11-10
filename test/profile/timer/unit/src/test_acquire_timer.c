#include "pt/profile/timer.h"
#include "pt/test/check.h"
#include "pt/test/expect.h"
#include "pt/test/unit.h"

void
test_single(void) {
  pt_timer target;
  pt_expect(PT_TAG_SUCCESS, pt_acquire_timer(&target, "test"));
  pt_check_same(target->name, "test");
  pt_check(!(target->active));
  pt_release_timer(target);
}

void
test_multiple(void) {
  pt_timer target[3];
  pt_expect(PT_TAG_SUCCESS, pt_acquire_timer(target + 0, "test 0"));
  pt_expect(PT_TAG_SUCCESS, pt_acquire_timer(target + 1, "test 1"));
  pt_expect(PT_TAG_SUCCESS, pt_acquire_timer(target + 2, "test 2"));
  pt_check(!(target[0]->active));
  pt_check(!(target[1]->active));
  pt_check(!(target[2]->active));
  pt_check_same(target[0]->name, "test 0");
  pt_check_same(target[1]->name, "test 1");
  pt_check_same(target[2]->name, "test 2");
  pt_release_timer(target[0]);
  pt_release_timer(target[1]);
  pt_release_timer(target[2]);
}

PT_TEST_LIST(
  {test_single, "Acquire a single timer"},
  {test_multiple, "Acquire multiple timers"});

PT_TEST_UNIT_MAIN
