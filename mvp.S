    # void mvp_instr(float *a, float *b, float *c, int m, int n)
    
    .globl mvp_instr
mvp_instr:
    mvp a2, a0, a1
    addi a3, a3, -128
    bnez a3, mvp_instr
    ret
