# MVP Example on RISC-V with the Matrix Instruction Extension

It is a simple test code to test the matrix instruction extension we defined for RISC-V. 

## How to test it? 

* Setup the following 4 environment variables.
```
export LLVM_INSTALL =  {YOUR_RISCV_LLVM_INSTALL_DIRECTORY}
export SYSROOT = "{YOUR RISCV GNU TOOLCHAIN DIRECTORY}/riscv64-unknown-elf"
export GCC_TOOLCHAIN = {YOUR RISCV GNU TOOLCHAIN DIRECTORY}
export QEMU_BIN = "{YOUR QEMU BIN DIRECTORY}/qemu-riscv64"
```

* Run the program.
  
Just 'make' will build and run the program.

You make also run it using `$QEMU_BIN ./mvp`
