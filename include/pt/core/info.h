#pragma once

typedef struct pt_info_t pt_info;
struct pt_info_t {
  pt_info* parent;
  int depth;
  const char* function;
  const char* file;
  int line;
};

#define PT_INFO(_handle, _parent) \
  pt_info _handle = { \
    (_parent), ((_parent) ? ((_parent)->depth + 1) : 0), __func__, __FILE__, \
    __LINE__, \
  }

#define PT_INFO_TOP(_handle) PT_INFO(_handle, (pt_info*)NULL)

void pt_print_info(pt_info* target);
