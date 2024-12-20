#include <stdio.h>

#define MAXLEN 100

void get_word(char target[], int len);
void trim(char word[], char target[]);

int main(int argc, char **argv)
{
  char line[MAXLEN];
  char response[MAXLEN];

  get_word(line, MAXLEN);
  trim(line, response);

  printf("%s\n", response);

  return 0;
}

void get_word(char target[], int len) {
  int c, idx;

  for(idx = 0; idx < (len - 1) && (c = getchar()) != EOF && c != '\n'; ++idx) {
    target[idx] = c;
  }

  target[idx] = '\n';
  ++idx;
  target[idx] = '\0';
}

void trim(char word[], char res[]) {
  int i, ri = 0;

  while (word[i] != EOF) {
    if (word[i] != ' ') {
      res[ri] = word[i];
      ++ri;
    }
    ++i;
  }
}
