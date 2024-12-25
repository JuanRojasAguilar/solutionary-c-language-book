#include <stdio.h>

#define MAXLEN 100

void get_word(char target[]);
void trim(char word[]);
void cpy_str(char dest[], char src[]);
void add_end_chr(char dest[], int idx);

int main(int argc, char **argv)
{
  char line[MAXLEN];

  get_word(line);
  trim(line);

  printf("%s\n", line);

  return 0;
}

void get_word(char target[]) {
  int c, idx;

  for(idx = 0; idx < (MAXLEN - 1) && (c = getchar()) != EOF && c != '\n'; ++idx) {
    target[idx] = c;
  }

  add_end_chr(target, idx);
}

void trim(char word[]) {
  int i = 0, ri = 0;
  char res[MAXLEN];

  while (word[i] != EOF && word[i] != '\n' && word[i] != '\0') {
    if (word[i] != ' ') {
      res[ri] = word[i];
      ++ri;
    }
    ++i;
  }
  add_end_chr(res, ri);
  cpy_str(word, res);
}

void cpy_str(char dest[], char src[]) {
  int i = 0;
  while (src[i] != '\0' && src[i] != '\n' && src[i] != EOF) {
    dest[i] = src[i];
    ++i;
  }
  add_end_chr(dest, i);
}

void add_end_chr(char dest[], int idx) {
  dest[idx] = '\n';
  ++idx;
  dest[idx] = '\0';
}
