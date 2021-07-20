//   BY   : Shapour Discover
//   DATE : 2021-03-10
//   TIME : 13:14

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#pragma warning(disable:4996)

typedef struct Rational {
	int numerator;
	int denominator;
}Rational;

typedef struct Info {
	int type;
	union {
		Rational rat;
		int i_num;
		float f_num;
		char name[50];
	};
	struct Info* next;
}Info;

void push_back(Info** head, Info* tmp) {
	Info* temp = *head;
	while (temp->next != NULL) {
		temp = temp->next;
	}
	temp->next = tmp;
	tmp->next = NULL;
}
void CreateList() {
	Info* head = NULL;
	int option;
	do
	{
		Info* temp = (Info*)malloc(sizeof(Info));
		temp->next = NULL;
		puts(" what do you want to do ? (Enter number of option)");
		puts(" 1.Build a new node");
		puts(" 0.exit");
		printf("Input:");
		scanf("%d", &option);
		if (option == 1) {
			printf("what type you wanna save?\n(1.a Rational)\n(2.an Integer)\n(3.a Float)\n(4.a Name)\n");
			scanf("%d", &temp->type);
			getchar();
			if (temp->type == 1) {
				printf("Enter Numerator and Denominator:");
				scanf("%d%d", &temp->rat.numerator, &temp->rat.denominator);
			}
			else if (temp->type == 2) {
				printf("Enter an Integer number:");
				scanf("%d", &temp->i_num);
			}
			else if (temp->type == 3) {
				printf("Enter a FLoat number:");
				scanf("%f", &temp->f_num);
			}
			else if (temp->type == 4) {
				printf("Enter a Name:");
				fgets(temp->name, 50, stdin);
				temp->name[strlen(temp->name) - 1] = '\0';
			}
			if (head == NULL) {
				head = temp;
			}
			else {
				push_back(&head, temp);
			}
		}
	} while (option != 0);
}
int main() {
	CreateList();
	return 0;
}