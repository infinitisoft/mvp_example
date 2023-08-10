run: mvp mvp++
	${QEMU_BIN} ./mvp

#${QEMU_BIN} -cpu rv64,x-v=true,x-k=true,vlen=512,elen=32,vext_spec=v1.0 ./mvp
	
mvp: main.c mvp.S makefile
	${LLVM_INSTALL}/bin/clang --sysroot=${SYSROOT} --gcc-toolchain=${GCC_TOOLCHAIN} --target=riscv64 -march=rv64gc -O -lm main.c mvp.S -o mvp

mvp++: main.c mvp.S makefile
	${LLVM_INSTALL}/bin/clang++ --sysroot=${SYSROOT} --gcc-toolchain=${GCC_TOOLCHAIN} --target=riscv64 -march=rv64gcv -O -lm main.cpp mvp.S -o mvp++ -I /home/lhuang/riscv-install/riscv64-unknown-elf/include/c++/12.2.0/riscv64-unknown-elf
