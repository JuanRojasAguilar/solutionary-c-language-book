#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXLEN 1000

void get_line();
void reverse_line(int count);

char line[MAXLEN];

int main(void)
{
  get_line();
  reverse_line(strlen(line));
  printf("Reversed line: %s\n", line);
  return 0;
}

void get_line()
{
  int idx;
  int c;
  extern char line[];

  idx = 0;
  while (idx < (MAXLEN - 1) && (c = getchar()) != EOF && c != '\n')
  {
    line[idx] = c;
    ++idx;
  }

  if (idx == MAXLEN - 1) {
    fprintf(stderr, "It stopped at %d char", idx);
  }

  line[idx] = '\0';
}

void reverse_line(int count)
{
  int idx;
  extern char line[];

  --count;
  idx = 0;
  while (idx <= (count >> 1))
  {
    line[idx] = line[count - idx] ^ line[idx];
    line[count - idx] = line[idx] ^ line[count - idx];
    line[idx] = line[count - idx] ^ line[idx];

    ++idx;
  }
  line[count + 1] = '\0';
}
