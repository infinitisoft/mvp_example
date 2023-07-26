run: mvp
	${QEMU_BIN} -cpu rv64,x-v=true,x-k=true,vlen=512,elen=32,vext_spec=v1.0 ./mvp
	
mvp: main.c mvp.S makefile
	${LLVM_INSTALL}/bin/clang --sysroot=${SYSROOT} --gcc-toolchain=${GCC_TOOLCHAIN} --target=riscv64 -march=rv64gcv -O -lm main.c mvp.S -o mvp
