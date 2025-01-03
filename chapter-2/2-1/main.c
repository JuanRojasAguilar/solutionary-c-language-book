/* Code to determine the ranges of char, short, int and long. */
#include <stdio.h>
#include <limits.h>

int main(void)
{
  printf("char range: %d ~ %d, memory: %d bytes\n", CHAR_MIN, CHAR_MAX, CHAR_BIT);
  printf("int range: %d ~ %d, memory: %lu bytes\n", INT_MIN, INT_MAX, sizeof(int) * 8);
  printf("uint range: 0 ~ %u\n", UINT_MAX);

  return 0;
}
