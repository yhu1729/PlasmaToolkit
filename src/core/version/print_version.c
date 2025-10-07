#include "pt/core/version.h"
#include <stdio.h>

void
pt_print_version(bool full) {
  if (full) {
    printf(
      "PlasmaToolkit v%d.%d.%d\n", PT_VERSION_MAJOR, PT_VERSION_MINOR,
      PT_VERSION_PATCH);
  } else {
    printf("%d.%d.%d\n", PT_VERSION_MAJOR, PT_VERSION_MINOR, PT_VERSION_PATCH);
  }
}
