/*
 * x in %rdi, y in %rsi, z in %rdx
 * subq %rdx, %rsi      // y - z ==> y
 * imulq %rsi, %rdi     // x * y ==> x
 * movq %rsi, %rax      // y ==> %rax
 * salq $63, %rax       // << 63
 * sarq $63, %rax       // >> 63
 * xorq %rdi, %rax      // 这个时候的%rdi已经是x*y ^ %rax
 * 因此可以得出结论 (x*y) ^ ((y-z) << 63 >> 63)
 */
long decode2(long x, long y, long z) {
    return (x * y) ^ ((y - z) << 63 >> 63);
}