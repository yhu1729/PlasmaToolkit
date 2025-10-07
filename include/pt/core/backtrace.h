#pragma once

typedef struct pt_backtrace_t pt_backtrace;
struct pt_backtrace_t {
  pt_backtrace* parent;
  int depth;
  const char* function;
  const char* file;
  int line;
};

#define PT_BACKTRACE(_handle, _parent) \
  pt_backtrace _handle = { \
    (_parent), ((_parent) ? ((_parent)->depth + 1) : 0), __func__, __FILE__, \
    __LINE__, \
  }

#define PT_BACKTRACE_TOP(_handle) PT_BACKTRACE(_handle, (pt_backtrace*)NULL)

void pt_print_backtrace(pt_backtrace* target);
