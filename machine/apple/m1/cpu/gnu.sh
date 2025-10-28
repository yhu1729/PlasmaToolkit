# compiler
export CC=/opt/homebrew/bin/gcc-15

# sanitizer
export LSAN_OPTIONS=suppressions=$PT_HOME/machine/apple/m1/cpu/lsan.txt

# config
export PT_PROCESSOR_HOST="apple"
export PT_PROCESSOR_DEVICE="none"
export PT_COMPILER_HOST="gnu"
export PT_COMPILER_DEVICE="none"
