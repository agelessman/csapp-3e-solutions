/*
    我们先写出汇编的注释：
    x in %rdi, n in %esi
    loop:
    movl %esi, %ecx         // %ecx = n
    movl $1, %edx           // %edx = 1
    movl $0, %eax           // %eax = 0
    jmp .L2                 // 跳转到L2
    .L3:
    movq %rdi, %r8          // %r8 = x
    andq %rdx, %r8          // %r8 &= %rdx
    orq %r8, %rax           // %rax |= %r8
    salq %c1, %rdx          // %rdx <<= %cl
    .L2:
    testq %rdx, %rdx        // %rdx & %rdx
    jne .L3                 // if != jump to .L3

    根据.L2我们可以得出的结论是如果%rdx的值为0 就继续循环

    .L3中做了什么事呢？
    我们知道%rdx的初始值为1,返回值%rax的值为0，那么.L3中的解释为：
    1. x &= %rdx
    2. %rax |= x
    3. %rdx << n的低8位的值，也是为了保护位移


    通过分析，我们就可以得出结论，该函数的目的是得出x中n的倍数的位掩码
    答案：
    A:
    x --> %rdi
    n --> %esi
    result --> %rax
    mask --> %rdx

    B:
    result = 0
    mask = 1

    C:
    mask != 0

    D:
    mask <<= n

    E:
    result |= (x & mask)

    F:
    如下函数

*/

long loop(long x, int n) {
    long result = 0;
    long mask;
    for (mask = 1; mask != 0; mask = mask << n) {
        result |= (x & mask);
    }
    return result;
}