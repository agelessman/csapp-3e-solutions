
A:
0
8
0
8

B:
e1最多需要16个字节
e2最多需要16个字节
因此 总共需要16个字节

C:
up in %rdi
proc:
    movq 8(%rdi), %rax      // %rax = *(8 + up) 取出偏移量为8的地址
    movq (%rax), %rdx       // %rdx = *%rax 取出该地址中的值
    movq (%rdx), %rdx       // 取出指针指向的值
    subq 8(%rax), %rdx      // 用该值减去 *(%rax + 8)
    movq %rdx, (%rdi)       //
    ret

一般来说 如果一个寄存器，比如说%rax 在下边的使用中用到了(%rax),我们就认定该寄存器保存的值为指针

movq 8(%rdi), %rax  %rax保存了up偏移量为8的指针值，在该函数中偏移量为8还是指针的只能是e2的next
==> %rax = up -> e2.next

movq (%rax), %rdx %rdx 同样保存的是指针，对(%rax)取值得到的是up下一个unio的指针
==> %rdx = *(up -> e2.next)

movq (%rdx), %rdx  这行代码过后，%rdx就不再是指针了，是一个值，但运行之前，%rdx是个指针
==> %rdx = *(*(up -> e2.next) -> e2.p)

subq 8(%rax), %rdx  我们知道%rax是个指针 指向next +8后
==> 8(%rax) = *(up -> e2.next) -> e1.y

答案：
up -> e2.x = *(*(up -> e2.next) -> e2.p) - *(up -> e2.next) -> e1.y;