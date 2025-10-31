pt_add_test(
  NAME get_tag_name
  MODULE core/tag
  LIB PT::Test PT::Core
  USE_ASAN YES
  LABEL type:unit
)
