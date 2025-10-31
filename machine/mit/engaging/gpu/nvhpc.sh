# module
module restore
module load nvhpc/24.5

export CUDA_HOME=/orcd/software/community/001/rocky8/nvhpc/2024_245/Linux_x86_64/24.5/cuda
export LD_LIBRARY_PATH=/orcd/software/community/001/rocky8/nvhpc/2024_245/Linux_x86_64/24.5/comm_libs/mpi/lib:$LD_LIBRARY_PATH

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
