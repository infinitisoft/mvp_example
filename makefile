run: mvp
	${QEMU_BIN} ./mvp
	
mvp: main.c mvp.S makefile
	${LLVM_INSTALL}/bin/clang --sysroot=${SYSROOT} --gcc-toolchain=${GCC_TOOLCHAIN} --target=riscv64 -march=rv64gc -O -lm main.c mvp.S -o mvp
