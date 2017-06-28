#include <stdio.h>
#include <string.h>
#include<ctype.h>
int main()
{

	char text[1000];
	char noviy[1000];
	char *a[1000], *pov[1000];
	char* t;
	int i = 0, j, k, sk, pov_count[1000], h = 0, d, f, r;
	printf("Enter the sentence:\n");
	gets_s(text);
	printf("\n");
	t = strtok(text, " ");
	while (t != NULL) {
		a[i] = t;
		t = (strtok(NULL, " "));
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
		if (pov_count[j] >= w)
			q = j;
	}
	printf("Repeated word:%s", pov[q]);
	printf("\n");
	return 0;
}