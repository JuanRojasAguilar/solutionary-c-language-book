#include <stdio.h>
#include <string.h>

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

void get_line(char word[]) {
  int idx, c;

  for (idx = 0; idx < (MAXLEN - 1) && (c = getchar()) != EOF && c != '\n' && c != '\0'; ++idx) {
    word[idx] = c;
  }

  word[idx] = '\0';
  reverse_line(word, idx);
}

void reverse_line(char word[], int count) {
  int rev_idx = 0;
  char rev[count];

  count -= 1;

  while (count != -1) {

    rev[rev_idx] = word[count];
    ++rev_idx;
    --count;
  }
  rev[rev_idx] = '\0';
  strcpy(word, rev);
}
