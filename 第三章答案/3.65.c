我们先假设M为4，我们假设矩阵A为：

1  2   3  4
5  6   7  8
9  10  11 12
13 14  15 16

那么在用函数transpose处理之后，矩阵变成了
1  5  9  13
2  6  10 14
3  7  11 15
4  8  12 16

可以看出对矩阵沿着对角线进行了转换。我们继续看汇编代码
下边的汇编代码只是函数中内循环中的代码

.L6:
movq (%rdx), %rcx       // %rcx = A[i][j]
movq (%rax), %rsi       // %rsi = A[j][i]
movq %rsi, (%rdx)       // A[i][j] = A[j][i]
movq %rcx, (%rax)       // A[j][i] = A[i][j]
addq $8, %rdx           // %rdx += 8
addq $120, %rax         // %rax += 120
cmpq %rdi, %rax         //
jne .L6                 //

我们很容易就发现，指向A[i][j]的寄存器为%rdx,指向A[j][i]的寄存器为%rax

求M最关键的是找出%rax寄存器移动的规律，因为%rdx也就是A[i][j] + 8 就表示右移一位
而%rax则要移动M * 8位
因此M = 120 / 8 = 15

上边的寄存器%rdi应该放的就是i == j时的A[i][j]的地址