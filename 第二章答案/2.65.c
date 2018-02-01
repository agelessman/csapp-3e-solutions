// 该题目要求，只要二进制书中1的个数为奇数，就返回1，否则返回0


#include <stdio.h>
/* Return 1 when x contains an odd nuimber of 1s, 0 otherwise.
   Assume w = 32.
*/
int odd_ones(unsigned x) {
    // 这是第一层的处理，对某一位i而言，通过右移了一位，我们就获取到了i前边的那一位，把他们异或后，
    // 得到的位的值为0或者1，1就表示和前边的一位中有奇数个1，0表示有偶数个1.
    x ^= (x >> 1);

    // 经过上边的处理后呢，x中每一位的值的意义就不同了，他表示该位和它前边的位1的个数是奇数还是偶数
    //  此时我们再右移2位，就获得了i前边的前边的值j，这个值j表示j和前边一位1的个数是奇数还是偶数
    //  异或后，的值就便是到j前边，一共四位1的个数是奇数还是偶数
    x ^= (x >> 2);

    // 后面的都是按照上边的原理依次类推的

    x ^= (x >> 4);
    x ^= (x >> 8);
    x ^= (x >> 16);
    return x & 1;
}

int main(void) {
    int result = odd_ones((unsigned)5);
    printf("The result of 5: %d \n", result);

    int result1 = odd_ones((unsigned)7);
    printf("The result of 3: %d \n", result1);
}