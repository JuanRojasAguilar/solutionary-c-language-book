#include <stdio.h>

#define MAXLEN 1000

void get_line();
void reverse_line(int count);

static char line[MAXLEN];

int main(void)
{
  get_line();
  puts(line);

  return 0;
}

void get_line()
{
  int idx;
  int c;

  idx = 0;
  while (idx < (MAXLEN - 1) && (c = getchar()) != EOF && c != '\n' && c != '\0')
  {
    line[idx] = c;
    ++idx;
  }

  if (idx == MAXLEN - 1) {
    fprintf(stderr, "It stopped at %d char", idx);
  }

  line[idx] = '\0';
  reverse_line(idx);
}

void reverse_line(int count)
{
  int idx;

  count -= 1;

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
