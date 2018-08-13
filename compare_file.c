#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define MAX 25

int main(void)
{
	char * longest;
	char * current;
	char * temp;

	int longest_size = 0;
	int ch;
	int pos_in_word = 0;

	longest = (char *) malloc(MAX * sizeof(char));
	current = (char *) malloc(MAX * sizeof(char));

	while ((ch = getchar()) != EOF)
	{
		if (isalpha(ch))
		{
			*(current + pos_in_word++) = ch;
		}
		else if (pos_in_word > 0)
		{
			if (pos_in_word > longest_size)
			{
				longest_size = pos_in_word;
				temp = longest;
				longest = current;
				current = temp;
			}
			pos_in_word = 0;
		}
	}
	*(longest + longest_size) = '\0';
	printf("%d characters in longest word: %s\n",longest_size, longest);
	free(longest);
	free(current);

	return 0;
}
