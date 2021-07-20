//   BY   : Shapour Discover
//   DATE : 2021-03-09
//   TIME : 00:38

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#pragma warning(disable:4996)

char* passage;

int main() {
	int countOfspams;
	scanf("%d", &countOfspams);
	char spams[1000];
	scanf("%s", spams);
	getchar();
	char spam[100][100];
	passage = (char*)malloc(1200 * sizeof(char));
	fgets(passage, 1200, stdin);
	passage[strlen(passage) - 1] = '\0';
	passage = (char*)realloc(passage, (strlen(passage) + 1) * sizeof(char));
	char* tok;
	const char sep[3] = ",";
	int i = 0;
	tok = strtok(spams, sep);
	while (tok != NULL) {
		strcpy(spam[i], tok);
		tok = strtok(0, sep);
		i++;
	}
	for (int i = 0; i < countOfspams; i++) {
		char* sub;//ali spam good alireza spam mamad
		sub = strstr(passage, spam[i]);
		int j;
		while (sub != NULL) {
			passage = (char*)realloc(passage, (sizeof(char) * (strlen(passage) + strlen(spam[i]) + 1)));
			for (j = strlen(passage); j < (strlen(passage) + strlen(spam[i]) + 1); j++) {
				passage[j] = '\0';
			}
			for (j = strlen(passage) - 1; &passage[j] != sub + strlen(spam[i]) - 1; j--) {
				passage[j + strlen(spam[i])] = passage[j];
			}
			for (int k = 0; k < (strlen(spam[i]) * 2); k++) {
				sub[k] = '*';
			}
			sub = strstr(passage, spam[i]);
		}
	}
	printf("%s", passage);
	return 0;
}