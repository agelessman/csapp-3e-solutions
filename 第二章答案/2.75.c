/*
    这个问题需要一步一步的进行推导
    T2Uw(x)我们把这种写法称为补码转无符号数，那么很容易得出：
    (2^w表示2的w次方，为什么当x<0时是这个结果呢，
    其实，补码的负数就是把原来w-1之后的位的结果减去了最高一位的值，最高位的值就是2^w)
    if x < 0  => x + 2^w
    if x > 0  => x

    上边的公式很简单，但在使用的时候还要做判断，显然很不科学，我们可以认为T2Uw(x)是一个函数
    接下来就想办法推导出一个表达式来

    这里省略了一系列的推导过程，得出了这样一个结果"
    T2Uw(X)= X + X(w-1)2^w

    大家看看这个式子跟上边的那个作用一样，x的w-1位就是他的最高位，如果该位的值是1，那么就相当于
    x<0的情况，否则就是另一种情况

    我们假设x`表示x的无符号值
    X` = X + X(w-1)2^w

    我们假设y`表示x的无符号值
    Y` = Y + Y(w-1)2^w

    那么X` * Y` = (X + X(w-1)2^w) * (Y + Y(w-1)2^w)
    如果要把这个计算式展开会很麻烦，我们可以进一步抽象
    设a = X(w-1)2^w, b= Y(w-1)2^w
    则： X` * Y` = X*Y + X*b + Y*a + a*b

    我们假定有这样一个函数，他的功能是取出无符号数的最高位uh(),因此上边的式子变形为：
    uh(X` * Y`) = uh(X*Y + X*b + Y*a + a*b)
                = uh(X*Y) + uh(X*b) + uh(Y*a) + uh(a*b)

    那么X * b 也就是X*b= X*Y(w-1)2^w 他的最高位的值就是X*Y(w-1)2^w / 2^w => X*Y(w-1)
    那么Y * a 也就是Y*a= Y*X(w-1)2^w 他的最高位的值就是Y*X(w-1)2^w / 2^w => Y*X(w-1)
    那么a * b 也就是a*b= X(w-1)2^w * Y(w-1)2^w 他 / 2^w => 0

    ===> uh(X` * Y`) = uh(X*Y) + X*Y(w-1) + Y*X(w-1)

    上边推理的核心思想就是 无符号X`的补码表示：X + X(w-1)2^w 求高位的/ 2^w 操作
*/

/*
 * unsigned-high-prod.c
 */
#include <stdio.h>
#include <assert.h>
#include <inttypes.h>

int signed_high_prod(int x, int y) {
  int64_t mul = (int64_t) x * y;
  return mul >> 32;
}

unsigned unsigned_high_prod(unsigned x, unsigned y) {
  /* TODO calculations */
  int sig_x = x >> 31;
  int sig_y = y >> 31;
  int signed_prod = signed_high_prod(x, y);
  return signed_prod + x * sig_y + y * sig_x;
}

/* a theorically correct version to test unsigned_high_prod func */
unsigned another_unsigned_high_prod(unsigned x, unsigned y) {
  uint64_t mul = (uint64_t) x * y;
  return mul >> 32;
}

int main(int argc, char* argv[]) {
  unsigned x = 0x12345678;
  unsigned y = 0xFFFFFFFF;

  assert(another_unsigned_high_prod(x, y) == unsigned_high_prod(x, y));
  return 0;
}