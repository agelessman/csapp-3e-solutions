
/*

    根据提示：
    x = 2^64 * x_h + x_l (x_h表示x的高64位，x_l表示x的低64位)
    y = 2^64 * y_h + y_l (y_h表示y的高64位，y_l表示x的低64位)

    x * y = (2^64 * x_h + x_l) * (2^64 * y_h + y_l)
          = 2^64 * x_h * 2^64 * y_h + 2^64 * x_h * y_l + x_l * 2^64 * y_h + x_l * y_l

    在上边这个表达式中2^64 * x_h * 2^64 * y_h明显已经越界，因此舍去，
    x * y = 2^64(x_h * y_l + x_l * y_h) + (x_l * y_l)

    上边的公式很重要，它表达的就是x*y的乘积的样式，根据p = 2^64 *p_h + p_l 再结合上边的公式
    我们得出的结论是：
    2^64(x_h * y_l + x_l * y_h) + (x_l * y_l) = 2^64 *p_h + p_l
    那么2^64 *p_h = 2^64(x_h * y_l + x_l * y_h) + (x_l * y_l) - p_l
    p_h = (x_h * y_l + x_l * y_h) + (x_l * y_l)/2^64 - p_l/2^64

    (x_l * y_l)/2^64 表示相乘后右移64位正好是他们相乘后的高64位的值
    p_l/2^64 则为0

    因此我们就把任务简化了，我们接下来看汇编

    dest in %rdi, x in %rsi, y in %rdx

    stroe_prod:
    movq %rdx, %rax         // %rax = y, 此时y_l = %rax
    cqto                    // 该命令的作用是把%rax中的符号位扩展到%rdx中,此时y_h = %rdx
    movq %rsi, %rcx         // 这行命令的作用是配合下一行获取x高64位的值
    sarq $63, %rcx          // 获取x的高64的值x_h = %rcx
    imulq %rax, %rcx        // 计算y_l * x_h = %rax * %rcx
    imulq %rsi, %rdx        // 计算y_h * x_l = %rdx * %rsi
    addq %rdx, %rcx         // 计算x_h * y_l + x_l * y_h的值
    mulq %rsi               // 该命令是计算%rax * %rsi的值，也就是x_l * y_l的值
    addq %rcx, %rdx         // 根据上边我们得出的结论，进行相加处理

*/