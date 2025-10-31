# module
module restore
module load nvhpc/24.5

export CUDA_HOME=$NVHPC_ROOT/cuda
export CPATH=$NVHPC_ROOT/comm_libs/mpi/include:$CPATH
export LD_LIBRARY_PATH=$NVHPC_ROOT/comm_libs/mpi/lib:$LD_LIBRARY_PATH

# compiler
export CC=mpicc
export CXX=mpicxx

# sanitizer
export LSAN_OPTIONS=suppressions=$PT_HOME/machine/mit/engaging/gpu/lsan.txt

# config
export PT_PROCESSOR_HOST="intel"
export PT_PROCESSOR_DEVICE="nvidia"
export PT_COMPILER_HOST="nvhpc"
export PT_COMPILER_DEVICE="nvhpc"
