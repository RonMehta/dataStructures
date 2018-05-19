//#include "..\stdafx.h"
#include <stdlib.h>
#include <stdio.h>

struct Node{

	int data;
	struct Node* next;

};


void InsertAtBegining(int x);
void Print();
void PrintR(struct Node * h);
void InsertAtNthPos(int data, int n);
void Reverse();
void ReverseL();
void ReversePrintR(struct Node * h);
void ReverseR(struct Node* h);
Node* Insert( Node *head, int data);


/*
Reverse a linked list and return pointer to the head
The input list will have at least one element
Node is defined as
struct Node
{
int data;
struct Node *next;
}
*/

Node* ReverseString(Node* head, Node *&node)
{
	// Complete this method
	if (!head)
		return NULL;
	if (head->next == NULL)
		node = head;
	else
	{
		Node* temp = ReverseString(head->next, node);
		if (temp)
		{
			temp->next = head;
			head->next = NULL;
			//head = temp;
		}
	}
	return head;
}
Node* ReverseL(Node* head)
{
	if (!head || !head->next)
		return head;
	Node* node = head;
	Node* temp = ReverseString(head, node);
	head = node;
	return head;
}

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

	head = Insert(head, 1);
	head = Insert(head, 2);
	head = Insert(head, 3);
	head = Insert(head, 4);
	
	Node* newNode = ReverseL(head);
	InsertAtBegining(1);
	InsertAtBegining(2);
	InsertAtBegining(3);
	InsertAtBegining(4);
	InsertAtBegining(5);
	Print();
	//PrintR(head);
	ReversePrintR(head);
	ReverseL();
	ReverseR(head);
	Print();
	return 0;
}

//struct Node* Insert(struct Node *&head, int data)
//{
//	// Complete this method
//
//	if (!head)
//	{
//		struct Node* newNode = (struct Node*) malloc(sizeof(struct Node));
//		newNode->data = data;
//		newNode->next = NULL;
//		head = newNode;
//		return head;
//	}
//	Insert(head->next, data);
//	return head;
//}

Node* Insert(Node *head, int data)
{
	// Complete this method
	Node* newNode = new Node;
	newNode->data = data;
	newNode->next = NULL;
	if (!head) {

		head = newNode;
		return head;
	}

	Node* temp = head;

	while (temp->next)
		temp = temp->next;

	temp->next = newNode;

	return head;
}

void Reverse()
{
	struct Node* priv,*current = head;
	priv = NULL;
	struct Node* nextNode;
	while(current != NULL){
		nextNode = current->next;
		current->next = priv;
		priv = current;
		current = nextNode;
	}

	head = priv;
}

void ReverseR(struct Node* h)	//using recursion
{

	if (h->next == NULL)
	{
		head = h;
		return;
	}
	ReverseR(h->next);
	struct Node* previous = h->next;
	previous->next = h;
	h->next = NULL;
	

}

void InsertAtBegining(int x){
	
	struct Node *temp = (struct Node*) malloc(sizeof(struct Node));
	temp->data = x;
	temp->next = head;
	head = temp;
	
}

void InsertAtNthPos(int data, int n) {

	struct Node *temp = (struct Node*) malloc(sizeof(struct Node));
	temp->data = data;
	temp->next = NULL;
	
	if(n==1){
		temp->next = head;
		head = temp;
		return;
	}

	struct Node *temp1=head;
	for (int i = 1; i < n-1; i++) {
		temp1 = temp1->next;
	}
	if (temp && temp1) {
		temp->next = temp1->next;
		temp1->next = temp;
	}

}

void Print(){

	struct Node *temp = head;
	printf("List is:");
	while (temp != NULL){
	
		printf(" %d", temp->data);
		temp = temp->next;
		
	}
	printf("\n");
}

void PrintR(struct Node * h)	//printuseing recursion
{
	if (h == NULL)
		return;	
		printf("%d ", h->data);
		PrintR(h->next);
	
		
}

void ReversePrintR(struct Node * h)	//print using recursion
{
	if (h == NULL)
		return;
	ReversePrintR(h->next);
	printf("%d ", h->data);


}

void Delete(int n){ //delete at nth position

	struct Node* temp1 = head;

	if(n==1)
	{
		head = head->next;
		free(temp1);
		return;
	}

	for (int i = 1; i < n - 1;i++)
		temp1 = temp1->next;

	struct Node* temp2 = temp1->next;
	temp1->next = temp2->next;
	free(temp2);


}

void ReverseL() { //redundant reverse

	struct Node* currentNode = head;
	struct Node* previousNode = NULL;
	struct Node* nextNode = head;

	


	while (currentNode != NULL) {
		nextNode = currentNode->next;
		currentNode->next = previousNode;
		previousNode = currentNode;
		currentNode = nextNode;
	}

	head = previousNode;

}