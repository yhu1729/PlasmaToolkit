#include "pt/config.h"
#include "pt/core/context.h"
#include "pt/core/macro.h"
#include "pt/test/check.h"
#include "pt/test/expect.h"
#include "pt/test/unit.h"

void
test_local(void) {
  pt_context target;
  pt_expect(PT_TAG_SUCCESS, pt_acquire(&target, PT_TAG_NETWORK_LOCAL));
  pt_check(!(target->active));
  pt_check(!(target->interface.local->active));
  pt_check_same(target->interface.local->rank, 0);
  pt_check_same(target->interface.local->size, 0);
  pt_release(target);
  pt_check_ok();
}

void
test_mpi(void) {
  pt_context target;
  pt_expect(PT_TAG_SUCCESS, pt_acquire(&target, PT_TAG_NETWORK_MPI));
  pt_check(!(target->active));
  pt_check(!(target->interface.mpi->active));
  pt_check_same(target->interface.mpi->rank, 0);
  pt_check_same(target->interface.mpi->size, 0);
  pt_release(target);
  pt_check_ok();
}

#ifdef PT_USE_NCCL
void
test_nccl(void) {
  pt_context target;
  pt_expect(PT_TAG_SUCCESS, pt_acquire(&target, PT_TAG_NETWORK_NCCL));
  pt_check(!(target->active));
  pt_check(!(target->interface.nccl->active));
  pt_check_same(target->interface.nccl->rank, 0);
  pt_check_same(target->interface.nccl->size, 0);
  pt_release(target);
  pt_check_ok();
}
#endif

#ifndef PT_USE_NCCL
PT_TEST_LIST(
  {test_local, "Acquire local context"}, {test_mpi, "Acquire MPI context"});
#else
PT_TEST_LIST(
  {test_local, "Acquire local context"}, {test_mpi, "Acquire MPI context"},
  {test_nccl, "Acquire NCCL context"});
#endif

PT_TEST_UNIT_MAIN
