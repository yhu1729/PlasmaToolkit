# compiler
export CC=gcc
export FC=gfortran

# sanitizer
export LSAN_OPTIONS=suppressions=$(pwd)/tool/lsan/amd/rocky.txt

# config
export PT_PROCESSOR_HOST="AMD"
export PT_PROCESSOR_DEVICE="None"
export PT_COMPILER_HOST="GNU"
export PT_COMPILER_DEVICE="None"
