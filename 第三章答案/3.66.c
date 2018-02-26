首先我们写出汇编代码的注释：

n in %rdi, A in %rsi, j in %rdx

sum_col:
    leaq 1(,%rdi,4), %r8        // %r8 = 1 + 4n
    leaq (%rdi,%rdi,2), %rax    // %rax = 3n
    movq %rax, %rdi             // %rdi = 3n
    testq %rax, %rax            // 3n & 3n
    jle .L4                     // if <= 0 .L4
    salq $3, %r8                // %r8 = (1 + 4n) << 3
    leaq (%rsi,%rdx,8), %rcx    // %rcx = 8j + A
    movl $0, %eax               // %rax = 0
    movl $0, %edx               // %rdx = 0
   .L3:
    addq (%rcx), %rax           // %rax += *%rcx
    addq $1, %rdx               // %rdx += 1
    addq %r8, %rcx              // %rcx += (1 + 4n) << 3
    cmpq %rdi, %rdx             // %rdx : 3n
    jne .L3
    rep; ret
   .L4:
    movl $0, %eax               // %rax = 0
    ret


很明显，.L3上边的代码都是为循环准备数据的

如果n = 0 那么就直接返回result = 0

然后初始化局部变量%rdx保存i的值，%rax保存result的值，%rcx保存每一行j的地址，
然后进入循环体.L3

由%rdx : 3n可以看出打破循环的条件是 i == 3n 推导出：NR(n) = 3n

由%rcx += (1 + 4n) << 3可以看出，%rcx每次都移动了一行的宽度，也就是NC(n) = (1 + 4n) << 3

答案是：
NR(n) = 3n
NC(n) = (1 + 4n) << 3


