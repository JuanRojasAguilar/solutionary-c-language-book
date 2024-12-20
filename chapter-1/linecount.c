#include <stdio.h>

#define MAXLINE 1000

int get_line(char line[], int maxline);
void copy(char to[], char from[]);

int main()
{
    int curr_line_len;
    int max_line_len;
    char line[MAXLINE];
    char longest[MAXLINE];

    max_line_len = curr_line_len = 0;
    while ((curr_line_len = get_line(line, MAXLINE)) > 0)
    {
        if (curr_line_len > max_line_len)
        {
            max_line_len = curr_line_len;
            copy(longest, line);
        }
    }

    if (max_line_len > 0)
    {
        printf("%s\n", longest);
    }
    return 0;
}

int get_line(char line[], int lim)
{
    int character, i;

    for (i = 0; i < (lim - 1) && (character = getchar()) != EOF && character != '\n'; ++i)
    {
        line[i] = character;
    }

    if (character == '\n')
    {
        line[i] = character;
        ++i;
    }

    line[i] = '\0';
    return i;
}

void copy(char to[], char from[])
{
    int i;

    i = 0;
    while ((to[i] = from[i]) != '\0')
    {
        ++i;
    }
}
