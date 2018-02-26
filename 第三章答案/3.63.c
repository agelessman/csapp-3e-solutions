
/*
    sub $0x3c, %rsi     // %rsi = n - 60
    cmp $0x5, %rsi      // 比较%rsi ： 5
    ja 4005c3           // 大于就跳转
    jmpq *0x4006f8(,%rsi,8)     // 这一行的目的是直接在跳转表中获取地址然后跳转

    // 因此下边这些汇编代码就是对应跳转表中的地址

    4005a1对应的index为0和2：
    lea 0x0(,%rdi,8), %rax      // result = 8x

    4005c3对应的index为1，也就是case 1，通过观察，它用的就是default的指令
    所以case 1 在switch中是缺失的

    4005aa对应的index为3：
    mov %rdi,%rax       // result = x
    sar $0x3,%rax       // result >>= 3
    也就是result = x / 8

    4005b2对应的index为4:
    mov %rdi,%rax       // result = x
    shl $0x4,%rax       // result <<= 4
    sub %rdi,%rax       // result -= x
    mov %rax,%rdi       // x = result
    也就是result = x * 15; x = result

    4005bf对应的index为5:
    imul %rdi,%rdi      // x *= x

    lea 0x4b(%rdi), %rax    // result = 75 + x

   经过上边的分析，就很容易得出结论了，但是别忘了要把index加上60

*/

long switch_prob(long x, long n) {
    long result = x;
    switch(n) {
        case 60:
        case 62:
            result = 8 * x;
            break;
        case 63:
            result = x / 8;
            break;
        case 64:
            result = 15 * x;
            x = result;
        case 65:
            x *= x;
        default:
            result = 75 + x;
    }
    return result;
}