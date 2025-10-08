#include "pt/config.h"
#include "pt/core/context.h"
#include "pt/test/check.h"
#include "pt/test/unit.h"

void
test_root(void) {
  pt_context target;
  pt_safe_invoke(pt_acquire_context(&target, PT_TAG_MPI));
  pt_check(target->type == PT_TAG_MPI);
  pt_check(!(target->active));
  pt_check(!(target->interface.mpi->active));
  pt_check_equal(target->interface.mpi->rank, 0, 0);
  pt_check_equal(target->interface.mpi->size, 0, 0);
  pt_release_context(target);
}

PT_TEST_LIST({test_root, "Acquire MPI context"});

PT_TEST_UNIT_MAIN
