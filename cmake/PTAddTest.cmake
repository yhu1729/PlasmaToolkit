function(pt_add_test)
  set(arg_one_value
    "NAME" "MODULE" "USE_MPI" "N_MPI_TASK" "USE_CUDA" "USE_ASAN"
  )
  set(arg_multi_value "LIB" "CUDA_KERNEL" "ENV_MOD" "LABEL")
  set(env_mod "")

  cmake_parse_arguments(
    PARSE_ARGV 0
    PT_TEST_ARG
    ""
    "${arg_one_value}"
    "${arg_multi_value}"
  )

  if(PT_TEST_ARG_USE_CUDA AND (NOT PT_USE_CUDA))
    return()
  endif()

  if(PT_TEST_ARG_USE_ASAN)
    list(APPEND env_mod ASAN_OPTIONS=set:detect_leaks=1)
  endif()

  set(_name_exe ${PT_TEST_ARG_NAME})
  set(_name_test ${PT_TEST_ARG_MODULE}/${_name_exe})
  add_executable(${_name_exe} test_${PT_TEST_ARG_NAME}.c)
  foreach(lib ${PT_TEST_ARG_LIB})
    target_link_libraries(${_name_exe} ${lib})
  endforeach()

  if(PT_TEST_ARG_CUDA_KERNEL AND PT_TEST_ARG_USE_CUDA AND PT_USE_CUDA)
    foreach(_name ${PT_TEST_ARG_CUDA_KERNEL})
      target_sources(${_name_exe} PRIVATE kernel_${_name})
    endforeach()
  endif()

  if(PT_TEST_ARG_USE_MPI)
    add_test(
      NAME ${_name_test}
      COMMAND
        ${MPIEXEC_EXECUTABLE}
        ${MPIEXEC_PREFLAGS}
        ${MPIEXEC_NUMPROC_FLAG} ${PT_TEST_ARG_N_MPI_TASK}
        ${MPIEXEC_POSTFLAGS}
        ./${_name_exe}
    )
  else()
    add_test(NAME ${_name_test} COMMAND ./${_name_exe})
  endif()

  if(PT_TEST_ARG_ENV_MOD)
    list(APPEND env_mod "${PT_TEST_ARG_ENV_MOD}")
  endif()
  set_tests_properties(
    ${_name_test}
    PROPERTIES
    ENVIRONMENT_MODIFICATION "${env_mod}"
  )

  set(test_label "")
  list(APPEND test_label module:${PT_TEST_ARG_MODULE})
  if(PT_TEST_ARG_LABEL)
    list(APPEND test_label "${PT_TEST_ARG_LABEL}")
  endif()
  set_tests_properties(${_name_test} PROPERTIES LABELS "${test_label}")
endfunction()
