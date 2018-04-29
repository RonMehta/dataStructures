//#include "stdafx.h"
#include <stdlib.h>
#include <stdio.h>

#define MAX_SIZE 10
int A[MAX_SIZE];
int top = -1;

void Push(int x){
	if (top == MAX_SIZE-1) { 
		printf("stack Overflow");
		return;
	}
	A[++top] = x;
}

void Pop(){
	if(top == -1){
		printf("no elements to pop");
		return;
	}
	top--;
}

int Top(){
	return A[top];
}

int IsEmpty()
{	
	if (top == -1)
		return 1;
	else
		return 0;
}

void Print()
{
	int i;
	printf("Stack: ");

	for(i=0; i<=top; i++){
		printf("%d ", A[i]);
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




