/* htoi : hex to decimal */
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <math.h>

#define MAXLEN 9

static char num[MAXLEN];

void get_num();
int parse_num();
int htoi(int i);

int main(void)
{
  get_num();
  int result = parse_num();
  printf("%d\n", result);
  return 0;
}

void get_num()
{
  int i = 0;
  int c;

  while (i < (MAXLEN - 1) && (c = getchar()) != EOF && c != '\n')
  {
    num[i] = c;
    ++i;
  }
  num[i] = '\0';
}

int parse_num()
{
  if (num[0] == '0')
  {
    if (num[1] == 'x' || num[1] == 'X')
    {
      return htoi(2);
    }
    else
    {
      return htoi(1);
    }
  }
  else
  {
    return htoi(0);
  }
}

int htoi(int i)
{
  int count = 0;
  int rep = strlen(num) - 1;
  int j = 0;

  while (rep >= i && num[rep] != '\0' && num[rep] != '\n')
  {
    printf("%d\n", num[rep]);
    if (toupper(num[rep]) > 64 && toupper(num[rep]) < 71)
    {
      count += (toupper(num[rep]) - 55) * pow(16, j);
    }
    else
    {
      count += (toupper(num[rep]) - 48) * pow(16,j);
    }
    --rep;
    ++j;
  }
  return count;
}
