设L为数组元素的大小,X_a表示数据的起始地址
&A[i][j][k] = X_a + L(i * S * T + j * T + k)

我们再进一步分析汇编代码：
i in %rdi, j in %rsi, k in %rdx, dest in %rcx

leaq (%rsi,%rsi,2), %rax        // %rax = 3j
leaq (%rsi,%rax,4), %rax        // %rax = 13j
movq %rdi, %rsi                 // %rsi = i
salq $6, %rsi                   // 结合上一条指令，%rsi = i << 6
addq %rsi, %rdi                 // %rdi = 65i
addq %rax, %rdi                 // %rdi = 65i + 13j
addq %rdi, %rdx                 // %rdx = 65i + 13j + k
movq A(,%rdx,8), %rax           // %rax = *(A + 8(65i + 13j + k))
movq %rax, (%rcx)               // *dest = *(A + 8(65i + 13j + k))
movl $3640, %eax                // %rax = 3640


使用A + 8(65i + 13j + k)和最上边的公式对比后发现：
L: 8
T: 13
S: 5

要求出R还必须用到3640这个值
R * T * S * L = 3640
R = 3640 / 8 / 13 / 5 = 7

R: 7