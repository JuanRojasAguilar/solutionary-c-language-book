#include <stdio.h>
#include <string.h>

#define MAXLEN 100

void get_word(char target[]);
void trim(char word[]);

int main(int argc, char **argv)
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
  int i = 0, ri = 0;
  char res[MAXLEN];

  while (word[i] != '\0') {
    if (word[i] != ' ' && word[i] != '\t') {
      res[ri] = word[i];
      ++ri;
    }
    ++i;
  }
  res[ri] = '\0';
  strcpy(word, res);
}
