#include <stdio.h>

#define MAXLEN 1000

void get_line(char word[]);
void reverse_line(char word[], int count);

int main(void)
{
  char line[MAXLEN];

  get_line(line);
  puts(line);

  return 0;
}

void get_line(char word[])
{
  int idx;
  int c;

  idx = 0;
  while (idx < (MAXLEN - 1) && (c = getchar()) != EOF && c != '\n' && c != '\0')
  {
    word[idx] = c;
    ++idx;
  }

  word[idx] = '\0';
  reverse_line(word, idx);
}

void reverse_line(char word[], int count)
{
  int idx;

  count -= 1;

  idx = 0;
  while (idx <= (count >> 1))
  {
    printf("%s the letter, %d the try\n", &word[count - idx], idx);
    word[idx] = word[count - idx] ^ word[idx];
    word[count - idx] = word[idx] ^ word[count - idx];
    word[idx] = word[count - idx] ^ word[idx];

    ++idx;
  }
  word[count + 1] = '\0';
}
