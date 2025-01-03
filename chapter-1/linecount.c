#include <stdio.h>

#define MAXLINE 1000

int max_line_len;
char line[MAXLINE];
char longest[MAXLINE];

int get_line(void);
void copy(void);

int main(void)
{
    int curr_line_len = 0;

    while ((curr_line_len = get_line()) > 0)
    {
        if (curr_line_len > max_line_len)
        {
            max_line_len = curr_line_len;
            copy();
        }
    }

    if (max_line_len > 0)
    {
        printf("%s\n", longest);
    }
    return 0;
}

int get_line()
{
    int c, i;
    extern char line[];

    for (i = 0; i < (MAXLINE - 1) && (c = getchar()) != EOF && c != '\n'; ++i)
    {
        line[i] = c;
    }

    if (c == '\n')
    {
        line[i] = c;
        ++i;
    }

    line[i] = '\0';
    return i;
}

void copy()
{
    int i = 0;

    while ((longest[i] = line[i]) != '\0')
    {
        ++i;
    }
}
