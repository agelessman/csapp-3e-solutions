
i in %rdi, bp in %rsi
test:
    mov 0x120(%rsi), %ecx           // %rcx = *(288 + bp)
    add (%rsi), %ecx                // %rcx = *(288 + bp) + *bp
    lea (%rdi,%rdi,4), %rax         // %rax = 5 * i
    lea (%rsi,%rax,8), %rax         // %rax = 5 * i * 8 + bp
    mov 0x8(%rax), %rdx             // %rdx = *((5 * i * 8 + bp) + 8)
    movslq %ecx, %rcx
    mov %rcx, 0x10(%rax,%rdx,8)     // &(16 + %rax + 8 * %rdx) = %rcx
    retq


由 %rdx = (5 * i * 8 + bp) + 8 可以推导出 a_struct a[CNT] 每个元素占40个字节，first占8个字节
==>
CNT = (288 - 8) / 40 ==> CNT = 7

本题重点理解%rax 和 %rdx中保存的是什么的值，
%rax中保存的是ap的值，而%rdx中保存的是ap->idx的值，理解了这一层接下来就简单了

说明ap->idx保存的是8字节的值，根据 &(16 + %rax + 8 * %rdx) = %rcx 可以得出idx应该是结构体的第一个变量long idx

如果结构体占用了40个字节 ， 那么数组x应该占用 40 - 8 也就是32个字节，每个元素占8个，可以容纳4个元素

typedef struct {
    long idx;
    long x[4];
}a_struct;


这个题目最重要的地方是理解mov 0x8(%rax), %rdx 这段代码，它是求ap->idx的值。
