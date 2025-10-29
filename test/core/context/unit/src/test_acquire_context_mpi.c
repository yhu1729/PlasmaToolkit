#include "pt/config.h"
#include "pt/core/context/mpi.h"
#include "pt/core/macro.h"
#include "pt/test/check.h"
#include "pt/test/expect.h"
#include "pt/test/unit.h"

void
test_root(void) {
  pt_context target;
  pt_expect(PT_TAG_SUCCESS, pt_acquire(&target, PT_TAG_MPI));
  pt_check(target->type == PT_TAG_MPI);
  pt_check(!(target->active));
  pt_check(!(target->interface.mpi->active));
  pt_check_same(target->interface.mpi->rank, 0);
  pt_check_same(target->interface.mpi->size, 0);
  pt_release(target);
  pt_check_ok();
}

PT_TEST_LIST({test_root, "Acquire MPI context"});

PT_TEST_UNIT_MAIN
