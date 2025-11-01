#include "pt/core/context/mpi.h"
#include "pt/core/macro.h"
#include "pt/test/check.h"
#include "pt/test/expect.h"
#include "pt/test/unit.h"

void
test_root(void) {
  pt_context_mpi target;
  pt_expect(PT_TAG_SUCCESS, pt_acquire(&target));
  pt_check(!(target->active));
  pt_check_same(target->rank, 0);
  pt_check_same(target->size, 0);
  pt_release(target);

  pt_check_ok();
}

PT_TEST_LIST({test_root, "Acquire root MPI context"});

PT_TEST_UNIT_MAIN
