//   BY   : Shapour Discover
//   DATE : 2021-03-09
//   TIME : 21:39

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#pragma warning(disable:4996)

typedef struct Node {
	int data;
	struct Node* next;
}Node;

void reversed(Node** head) {
	Node* rear = NULL;
	Node* temp = *head;
	Node* front = NULL;
	while (temp != NULL) {
		front = temp->next;
		temp->next = rear;
		rear = temp;
		temp = front;
	}
	*head = rear;
}
Node* CreateNode(int Data) {
	Node* temp = (Node*)malloc(sizeof(Node));
	temp->data = Data;
	temp->next = NULL;
	return temp;
}
void PrintNode(Node* node) {
	printf("Your data = %d\n", node->data);
}
void PrintLinkedList(Node* head) {
	Node* temp = head;
	if (temp == NULL) {
		printf("List is empty :((\n");
		return;
	}
	else {
		int i = 0;
		while (temp != NULL) {
			i++;
			printf("%d.The data is %d\n", i, temp->data);
			temp = temp->next;
		}
	}
}
void ReversePrint(Node* head) {
	reversed(&head);
	Node* temp = head;
	if (temp == NULL) {
		printf("List is empty :((\n");
		return;
	}
	else {
		int i = 0;
		while (temp != NULL) {
			i++;
			printf("%d.The date is %d\n", i, temp->data);
			temp = temp->next;
		}
	}
	reversed(&head);
}
void push_front(Node** head, int data) {
	Node* temp = (Node*)malloc(sizeof(Node));
	temp->data = data;
	temp->next = *head;
	*head = temp;
}
void push_back(Node** head, int data) {
	Node* temp = *head;
	while (temp->next != NULL) {
		temp = temp->next;
	}
	Node* tmp = (Node*)malloc(sizeof(Node));
	tmp->data = data;
	tmp->next = NULL;
	temp->next = tmp;
}
void pop_front(Node** head) {
	Node* temp = *head;
	*head = (*head)->next;
	free(temp);
}
void pop_back(Node** head) {
	Node* temp = *head;
	while (temp->next != NULL) {
		temp = temp->next;
	}
	Node* tail = temp;
	Node* prev = NULL;
	temp = NULL;
	for (temp = *head; temp->next != NULL; temp = temp->next)
		prev = temp;
	prev->next = NULL;
	tail = prev;
	free(temp);
}
void insert(Node** head, int index, int Data) {
	Node* before = *head;
	Node* after = *head;
	Node* temp = (Node*)malloc(sizeof(Node));
	temp->data = Data;
	for (int i = 0;i < index - 1;i++) {
		before = before->next;
	}
	for (int i = 0;i < index;i++) {
		after = after->next;
	}
	before->next = temp;
	temp->next = after;
}
void delete(Node** head, int index) {
	Node* before = *head;
	Node* temp = *head;
	for (int i = 0;i < index - 1;i++) {
		before = before->next;
	}
	for (int i = 0;i < index;i++) {
		temp = temp->next;
	}
	before->next = temp->next;
	free(temp);
}
int search(Node** head, int Data) {
	Node* tmp = *head;
	int counter = 0;
	while (tmp != NULL) {
		tmp = tmp->next;
		counter++;
	}
	Node* temp = *head;
	for (int i = 0;i < counter;i++) {
		if (temp->data == Data) {
			return i;
		}
		temp = temp->next;
	}
	return -1;
}
void swap(Node** head, int index1, int index2) {
	Node* node_1 = *head;
	Node* node_2 = *head;
	for (int i = 0;i < index1;i++) {
		node_1 = node_1->next;
	}
	for (int i = 0;i < index2;i++) {
		node_2 = node_2->next;
	}
	int temp = node_1->data;
	node_1->data = node_2->data;
	node_2->data = temp;
}

int main() {
	Node* head = NULL, * temp = NULL;
	int optionNumber, Data, index, counter;
	do {
		puts(" what do you want to do ? (enter number of option)");
		puts(" 1.Build a new node");
		puts(" 2.Print DATA of a node");
		puts(" 3.Print whole linked list");
		puts(" 4.Print Reverse linked list");
		puts(" 5.Push_Front");
		puts(" 6.Push_Back");
		puts(" 7.Pop_Front");
		puts(" 8.Pop_Back");
		puts(" 9.Insert a Node");
		puts(" 10.Delete a Node");
		puts(" 11.Search");
		puts(" 12.Swap two Nodes");
		puts(" 13.Reverse whole linked list");
		puts(" 0.exit\n");
		printf("Input:");
		scanf("%d", &optionNumber);
		if (optionNumber == 1) {
			printf(" Enter your Number:");
			scanf("%d", &Data);
			if (head == NULL) {
				head = CreateNode(Data);
			}
			else {
				temp = CreateNode(Data);
			}
		}
		else if (optionNumber == 2) {
			Node* tmp = head;
			counter = 0;
			while (tmp != NULL) {
				tmp = tmp->next;
				counter++;
			}
			printf("Enter index(indexes starts from 0):");
			scanf("%d", &index);
			tmp = head;
			if (index < counter) {
				for (int i = 0;i < index;i++) {
					tmp = tmp->next;
				}
				PrintNode(tmp);
			}
			else {
				printf("Index not found.\n");
			}
		}
		else if (optionNumber == 3) {
			PrintLinkedList(head);
		}
		else if (optionNumber == 4) {
			ReversePrint(head);
		}
		else if (optionNumber == 5) {
			printf("Enter your Number:");
			scanf("%d", &Data);
			push_front(&head, Data);
		}
		else if (optionNumber == 6) {
			printf("Enter your Number:");
			scanf("%d", &Data);
			push_back(&head, Data);
		}
		else if (optionNumber == 7) {
			pop_front(&head);
		}
		else if (optionNumber == 8) {
			pop_back(&head);
		}
		else if (optionNumber == 9) {
			Node* tmp = head;
			counter = 0;
			while (tmp != NULL) {
				tmp = tmp->next;
				counter++;
			}
			printf(" Enter your Number:");
			scanf("%d", &Data);
			printf("Enter index(indexes starts from 0):");
			scanf("%d", &index);
			if (index < counter) {
				insert(&head, index, Data);
			}
			else {
				printf("Index not found.\n");
			}
		}
		else if (optionNumber == 10) {
			Node* tmp = head;
			counter = 0;
			while (tmp != NULL) {
				tmp = tmp->next;
				counter++;
			}
			printf("Enter index(indexes starts from 0):");
			scanf("%d", &index);
			if (index < counter) {
				delete(&head, index);
			}
			else {
				printf("Index not found.\n");
			}
		}
		else if (optionNumber == 11) {
			printf("Enter Number:");
			scanf("%d", &Data);
			printf("Your Number is in Index %d\n", search(&head, Data));
		}
		else if (optionNumber == 12) {
			Node* tmp = head;
			counter = 0;
			while (tmp != NULL) {
				tmp = tmp->next;
				counter++;
			}
			printf("Enter index 1  and  index 2(indexes starts from 0):");
			scanf("%d%d", &index, &Data);
			if (index < counter && Data < counter) {
				swap(&head, index, Data);
			}
			else {
				printf("Index not found.\n");
			}
		}
		else if (optionNumber == 13) {
			reversed(&head);
		}
	} while (optionNumber != 0);
	return 0;
}