//#include "stdafx.h"
//check for balanced parantheses using stack
#include <iostream>
#include <stack>
using namespace std;

struct Node{

	int data;
	Node* next;
};

void ReverseString(char c[], int size)
{
	
	stack <char> list;
	
	for(int i=0; i<size;i++)	//big O(n)
	{
		list.push(c[i]);
	}

	for (int i = 0; i < size;i++) {	//Big O(n)
	
		c[i] = list.top();
		list.pop();
	}
}

void ReverseList(Node * head){	//reverse a linked list using stack

	stack<Node *> list;

	Node* temp = head;

	while(temp != NULL){
		list.push(temp);
		temp = temp->next;
	}

	temp = list.top();
	head = temp;
	list.pop();
	while(!list.empty()){
		temp->next = list.top();
		list.pop();
		temp = temp->next;
	}
	temp->next = NULL;

}

bool balance(char c[], int size){

	stack<char> s;

	for(int i=0 ;i<size;i++){
	
		if (c[i] == '(' || c[i] == '{' || c[i] == '['){
		
			s.push(c[i]);
		}
		else if(c[i] == ')' || c[i] == '}' || c[i] == ']'){
		
			if (s.empty()) return false;
			char temp = s.top();

			if ((temp == '(' && c[i] == ')') || (temp == '{' && c[i] == '}') || (temp == '[' && c[i] == ']'))
				s.pop();
			else
				return false;

		}

	}

	return s.empty() ? true:false;

}

int main()
{
	char c[51];
	printf("Enter a string: ");
	gets_s(c);
	bool isBal = balance(c, strlen(c));
	ReverseString(c,strlen(c));
	printf("Output is =%s", c);
	return 0;
}




