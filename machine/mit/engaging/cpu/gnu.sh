# module
module restore

# compiler
export CC=gcc

# sanitizer
export LSAN_OPTIONS=suppressions=$PT_HOME/machine/mit/engaging/cpu/lsan.txt

# config
export PT_PROCESSOR_HOST="amd"
export PT_PROCESSOR_DEVICE="none"
export PT_COMPILER_HOST="gnu"
export PT_COMPILER_DEVICE="none"
