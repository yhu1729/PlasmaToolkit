# compiler
export CC=/opt/homebrew/opt/llvm/bin/clang
export FC=/opt/homebrew/bin/flang

# sanitizer
export LSAN_OPTIONS=suppressions=$(pwd)/tool/lsan/arm64/darwin.txt

# config
export PT_PROCESSOR_HOST="Apple"
export PT_PROCESSOR_DEVICE="None"
export PT_COMPILER_HOST="LLVM"
export PT_COMPILER_DEVICE="None"
