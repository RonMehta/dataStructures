//#include "stdafx.h"
#include <stdlib.h>
#include <stdio.h>

struct Node {

	int data;
	struct Node* next;
	struct Node* prev;

};


void InsertAtHead(int data);
void InsertAtTail(int data);
void Print();
void ReversePrint();
//void Print();
//void PrintR(struct Node * h);
//void InsertAtNthPos(int data, int n);
//void Reverse();
//void ReverseL();
//void ReversePrintR(struct Node * h);
//void ReverseR(struct Node* h);

struct Node * head;
int main()
{
	head = NULL;
	//int n=0, i, x=0;
	//printf("How many no to be inserted? ");
	//scanf_s("%d",& n);

	//for(i=1;i<=n;i++){
	//	printf("Enter the no \n");
	//	scanf_s(" %d", &x);
	//	InsertAtBegining(x);
	//	Print();
	//}

	//InsertAtNthPos(111, 2);
	//InsertAtNthPos(121, 1);
	//InsertAtNthPos(121, 4);
	//Print();


	InsertAtHead(1);	Print();	ReversePrint();
	InsertAtHead(2);	Print();	ReversePrint();
	InsertAtHead(3);	Print();	ReversePrint();
	InsertAtHead(4);	Print();	ReversePrint();
	InsertAtHead(5);	Print();	ReversePrint();
	InsertAtTail(6);	Print();	ReversePrint();

	return 0;
}

void InsertAtHead(int data){

	struct Node* newHead = (struct Node*) malloc(sizeof(struct Node));
	newHead->data = data;
	newHead->next = head;
	newHead->prev = NULL;
	if(head)
		head->prev = newHead;
	head = newHead;
}

void InsertAtTail(int data) {

	struct Node* newTail = (struct Node*) malloc(sizeof(struct Node));
	newTail->data = data;
	newTail->prev = NULL;
	newTail->next = NULL;

	struct Node* temp = head;
	if (temp == NULL)
	{
		head = newTail;
		return;
	}
	while (temp->next != NULL)
	{
		temp = temp->next;
	}

	temp->next = newTail;
	newTail->prev = temp;

}

void Print() {

	struct Node * temp = head;

	if (temp == NULL) return;
	printf("Forwad: ");
	while(temp != NULL){
	
		
		printf("%d", temp->data);
		temp = temp->next;
	
	}
	printf("\n");
}

void ReversePrint(){

	struct Node *temp = head;
	if (temp == NULL) return;

	while(temp->next != NULL){
	
		temp = temp->next;

	}

	printf("Reverse is: ");
	while(temp != NULL){
	
		printf("%d", temp->data);
		temp = temp->prev;
	}
	printf("\n");

}


