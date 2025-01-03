#include <stdio.h>
#include <string.h>

#define MAXLEN 100

void get_word(char target[]);
void trim(char word[]);

int main(void)
{
  char line[MAXLEN];

  get_word(line);
  trim(line);
  puts(line);

  return 0;
}

void get_word(char target[]) {
  int c, idx;

  for(idx = 0; idx < (MAXLEN - 1) && (c = getchar()) != EOF && c != '\n'; ++idx) {
    target[idx] = c;
  }

  if (idx == MAXLEN - 1) {
    fprintf(stderr, "Warning: Input stopped at %d characters", MAXLEN - 1);
  }

  target[idx] = '\0';
}

void trim(char word[]) {
  int idx = 0, res_idx = 0;
  char res[MAXLEN];

  while (word[idx] != '\0') {
    if (word[idx] != ' ' && word[idx] != '\t') {
      res[res_idx] = word[idx];
      ++res_idx;
    }
    ++idx;
  }
  res[res_idx] = '\0';
  strcpy(word, res);
}
