#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include<ctype.h>
#include <locale.h>
#define MAX 1000  
int main()
{
	setlocale(LC_ALL, ("rus"));
	char text[MAX];
	char noviy[MAX];
	char *a[MAX], *pov[MAX];
	char* t;
	char sym[100] = ", . ! ? ";
	int i = 0, j, k, sk, pov_count[MAX], h = 0, d, f, r;
	printf("Введите текст(английский текст):\n");
	gets_s(text);
	for (r = 0; text[r] != 0; r++)
	{
		if (text[r] <= 'z' && text[r] >= 'a')
		{
			text[r] += 'A' - 'a';
		}
	}
	printf("\n");
	t = strtok(text, sym);
	while (t != NULL) {
		a[i] = t;
		t = (strtok(NULL, sym));
		i++;
	}
	for (j = 0; j<i; j++) {
		sk = 0;
		f = 0;
		for (k = 0; k<i; k++) {
			if (strcmp(a[j], a[k]) == 0) {
				sk++;
			}
		}
		for (d = 0; d<h; d++) {
			if (strcmp(a[j], pov[d]) == 0) {
				f++;
			}
		}
		if (sk>1 && f == 0) {
			pov[h] = a[j];
			pov_count[h] = sk;
			h++;
		}

	}
	int w = pov_count[0], q;
	for (j = 0; j<h; j++) {
		if (pov_count[j] >= w) {
			q = j;
		}
	}
	if (sk > 1)
	{
		printf("Слово, которое повторяется больше всего раз:%s", pov[q]);
	}
	else {
		printf("Нет повторяющихся слов\n");
		return 0;
	}
	printf("\n");
	return 0;
}