//#include "stdafx.h"
#include <stdlib.h>
#include <stdio.h>

struct Node{

	int data;
	struct Node* next;
};

struct Node* top = NULL;

void Push(int x) {
	
	struct Node* newNode = (struct Node*) malloc(sizeof(struct Node));
	newNode->data = x;
	newNode->next = top;
	top = newNode;
}

void Pop() {
	if(top == NULL)
	{
		printf("empty stack");
		return;
	}

	struct Node* oldTop = top;
	top = top->next;
	free(oldTop);
}

int Top() {
	return top->data;
}

int IsEmpty()
{
	if (top == NULL)
		return 1;
	else
		return 0;
}

void Print()
{
	int i;
	printf("Stack: ");
	struct Node* temp = top;
	while(temp != NULL) {
		printf("%d ", temp->data);
		temp = temp->next;
	}
	printf("\n");

}

int main()
{
	Push(2);	Print();
	Push(3);	Print();
	Push(5);	Print();
	Push(6);	Print();
	Push(1);	Print();
	Pop();	Print();
	Push(2);	Print();
	return 0;
}




