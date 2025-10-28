# compiler
export CC=mpicc
export CXX=mpicxx
export CUDACXX=nvcc

# sanitizer
export LSAN_OPTIONS=suppressions=$PT_HOME/machine/mit/engaging/gpu/lsan.txt

# config
export PT_PROCESSOR_HOST="intel"
export PT_PROCESSOR_DEVICE="nvidia"
export PT_COMPILER_HOST="nvhpc"
export PT_COMPILER_DEVICE="nvhpc"
