#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#pragma warning (disable:4996)

struct Book {
	char b[150];
	struct Book* next;
};
void push(struct Book** head_ref, char new_data[150]) {
	struct Book* new_node = (struct Book*)malloc(sizeof(struct Book));
	strcpy(new_node->b, new_data);
	new_node->next = *head_ref;
	*head_ref = new_node;
	return;
}
void append(struct Book** head_ref, char new_data[150]) {
	struct Book* new_node = (struct Book*)malloc(sizeof(struct Book));
	strcpy(new_node->b, new_data);
	new_node->next = 0;
	if (*head_ref == NULL) {
		*head_ref = new_node;
		return;
	}
	struct Book* last = *head_ref;
	while (last->next != 0) {
		last = last->next;
	}
	last->next = new_node;
	return;
}
void deletefromleft(struct Book** head)
{
	struct Book* dlt = NULL;
	dlt = *head;
	*head = (*head)->next;
	free(dlt);
	return;
}
void printlist(struct Book* head) {
	while (head != 0) {
		printf("%s\n", head->b);
		head = head->next;
	}
}
int main() {
	struct Book* head = NULL;
	int counter;
	scanf("%d", &counter);
	getchar();
	char nb[150];
	for (int i = 0;i < counter;i++) {
		fgets(nb, 150, stdin);
		nb[strlen(nb) - 1] = '\0';
		append(&head, nb);
	}
	char op[11];
	while (1)
	{
		scanf("%s", op);
		getchar();
		if (strcmp(op, "DeleteLeft") == 0) {
			counter--;
			deletefromleft(&head);
		}
		if (strcmp(op, "AddLeft") == 0) {
			counter++;
			fgets(nb, 150, stdin);
			nb[strlen(nb) - 1] = '\0';
			push(&head, nb);
		}
		if (strcmp(op, "AddRight") == 0) {
			counter++;
			fgets(nb, 150, stdin);
			nb[strlen(nb) - 1] = '\0';
			append(&head, nb);
		}
		if (strcmp(op, "Exit") == 0) {
			printf("%d\n", counter);
			printlist(head);
			return 0;
		}
	}
}