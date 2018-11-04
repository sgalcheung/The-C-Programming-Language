#include <stdio.h>
#define MAXLINE 1000	/* maximum input line size */

int getline(char line[], int maxline);
void reverse(char s[]);

/* reverse input lines, a line at a time */
main()
{
	char line[MAXLINE];	/* current input line */

	while (getline(line, MAXLINE) > 0)
	{
		reverse(line);
		printf("%s", line);
	}

	getchar();
	return 0;
}
/* reverse: reverse string s */
void reverse(char s[])
{
	int i, j;
	char temp;

	i = 0;
	while (s[i] != '\0')		/* find the end of stirng s */
		++i;
	--i;						/* back off from '\0' */
	if (s[i] == '\n')
		--i;					/* leave newline in place */
	j = 0;						/* beginning of new string s */
	while (j < i)
	{
		temp = s[j];
		s[j] = s[i];			/* swap the characters */
		s[i] = temp;
		--i;
		++j;
	}
}
/* getline: read a line into s, return length */
int getline(char s[], int lim)
{
	int c, i, j;

	j = 0;
	for (i = 0; (c = getchar()) != EOF && c != '\n'; ++i)
		if (i < lim - 2)
		{
			s[j] = c;	/* line still in boundaries */
			++j;
		}
	if (c == '\n')
	{
		s[j] = c;
		++j;
		++i;
	}
	s[j] = '\0';
	return i;
}