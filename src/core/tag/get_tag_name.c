#include "pt/core/tag.h"

const char*
pt_get_tag_name(const pt_tag target) {
#define _PT_EXPAND(_tag, _message, _value) \
  case _tag: \
    return _message;

  switch (target) { _PT_TAG_LIST(_PT_EXPAND) }

#undef _PT_EXPAND

  return "Unknown";
}
