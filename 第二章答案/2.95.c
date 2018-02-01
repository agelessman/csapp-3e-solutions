/*
 * float-half.c
 */
#include <stdio.h>
#include <assert.h>

typedef unsigned float_bits;

float_bits float_half(float_bits f) {
  unsigned sig = f >> 31;
  unsigned rest = f & 0x7FFFFFFF;
  unsigned exp = f >> 23 & 0xFF;
  unsigned frac = f & 0x7FFFFF;

  int is_NAN_or_oo = (exp == 0xFF);
  if (is_NAN_or_oo) {
    return f;
  }

  /*
   * 这里就用到了向偶数取整的知识，在下边的注释中描述的很详细
   * 那么如何理解取整呢，我们假设这个被右移出去的位为a，那么a就有可能是1或者0，如果是0，那么我们
     就不需要取整，如果是1，我们可以这么想：1111.a 这个a如果是1，折算成小数就是0.5 因此是需要
     取整的，它前边的那一位如果是0，表示已经是偶数了，就舍弃a 如果是1，要向上取整，在未右移之前+1就可以了
   */

  /*
   * round to even, we care about last 2 bits of frac
   *
   * 00 => 0 just >>1
   * 01 => 0 (round to even) just >>1
   * 10 => 1 just >>1
   * 11 => 1 + 1 (round to even) just >>1 and plus 1
   */
  int addition = (frac & 0x3) == 0x3;

  if (exp == 0) {
    /* Denormalized */
    frac >>= 1;
    frac += addition;
  } else if (exp == 1) {
    /* Normalized to denormalized */
    rest >>= 1;
    rest += addition;
    exp = rest >> 23 & 0xFF;
    frac = rest & 0x7FFFFF;
  } else {
    /* Normalized */
    exp -= 1;
  }

  return sig << 31 | exp << 23 | frac;
}
