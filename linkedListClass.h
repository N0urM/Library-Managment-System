	#include <stdio.h>
	#include <stdlib.h>
	#include "stdTypes.h"
	#include <stdbool.h>
	#include <string.h>


	typedef struct mynode Node;
	typedef struct mynode studentNode;

	struct mynode{
		u32 id;
		u32 age;
		char gender[10];
		char name[20];
		Node* ptr;
	};
	
struct studentData{
		u32 id;
		u32 age;
		char gender[10];
		char name[20];
};


	void appendNode(Node** head , Node** tail , studentNode* student){
		// allocate memory for new node
		Node* newNode =(Node*) malloc(sizeof(Node));
		// assign value 
		newNode->id = student->id ;
		newNode ->age = student ->age;
		strcpy (newNode ->gender , student->gender);
		strcpy(	newNode->name ,student->name);
		// if list is empty -> make new node as head and tail
		if (*head == NULL){
			newNode->ptr = NULL;
			*head = newNode;
			*tail = newNode;
		}
		
		else {
			(*tail)->ptr = newNode;
			*tail = newNode;
			(*tail)->ptr = NULL;
		}
		
	}
	void insertAtBegining (Node *head , Node *tail, studentNode* student){
		Node* newNode = (Node*) malloc (sizeof(Node));
		// assign value 
		newNode->id = student->id ;
		newNode ->age = student ->age;
		strcpy (newNode ->gender , student->gender);
		strcpy(	newNode->name , student->name);
		// List is empty
		if (head == NULL){
			newNode->ptr = NULL;
			head = newNode;
			tail = newNode;
		}
		else {
			newNode->ptr = head;
			head = newNode;
		}
	}
	void printNodes(Node *head){
		Node* temp = head;
		while (temp != NULL){
			printf("Node: %s\t" , temp->name);
			temp = temp->ptr;
		}
		printf("\n");
	}
	bool FindNode(Node *head , u32 id){
		Node* temp = head;
		// while not end of list and id not found
		while (temp!= NULL && id != temp->id)
		{
			temp=temp->ptr;
		}
		// if end of list
		if(temp == NULL){
			return 0 ; // id not found
		}
		return 1; // found id
	}
	void editNode(Node* head  , u32 id , studentNode* student){
		Node* temp = head;
		while (temp!= NULL && id != temp->id)
		{
			temp=temp->ptr;
		}
		if(temp == NULL){
			printf("ID not found\n");
			return  ;
		}
		// Edit only the one varibalie modified using initial conditions
		if(student->age != 0)
			temp->age = student->age;
		if(student->gender != "")
			strcpy (temp->gender , student->gender);
		if(student->id != 0)
			temp->id = student->id;
		if(student->name != "")
			strcpy(temp->name , student->name);
		
	}
	void countNodes(Node *head){

		Node* temp = head;
		u32 counter = 0;
		while (temp != NULL){
				temp = temp->ptr;
				counter++;
		}
		printf("\nNodes count: %d\n" , counter);
	}

	void deleteNode (Node **head , Node **tail, u32 val){
		Node* temp = *head;
		Node* lastNode = NULL;
		// head is the node to delete
		if (val == (*head) -> id){
			*head = (*head)->ptr ;
			free (temp);
			return ;
		}

		while (temp != NULL && temp->id != val){
		
			lastNode = temp;
			temp = temp -> ptr;
		}
		if(temp == NULL) {
			return;
		}
			
		if (temp == *tail)
			*tail = lastNode;
		lastNode-> ptr = temp -> ptr;	
		free(temp);		

	}


	void deleteList(Node *head){
		 Node* temp = head;
		 Node* lastNode = NULL;
		while (temp != NULL){
			lastNode = temp->ptr ;
			free(temp);
			temp = lastNode ;
		}
		 head = NULL;
	}

