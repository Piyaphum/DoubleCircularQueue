#include<stdio.h>
#include<stdlib.h>
#include<conio.h>

struct node  
{  
    struct node* prev;  
    struct node* next;  
    int data;  
};  

struct node* head = NULL;
struct node* rear = NULL;

void enQueue_front();
void enQueue_rear();
void deQueue_front();
void deQueue_rear();
void display();


int main() {
	int choice;
	do{
		printf("\n\n*****MENU*****\n");
		printf("1. Enqueue_front\n2. Eequeue_rear\n3.Dequeue_front\n4.Dequeue_rear\n5.Exit");
		printf("\nEnter you choice: ");
		scanf("%d",&choice);
		
		switch(choice){
			case 1: enQueue_front();display();
			break;
			case 2: enQueue_rear();display();
			break;
			case 3: deQueue_front();display();
			break;
			case 4: deQueue_rear();display();
			break;
			case 5: exit(0); //this func is one of the standard library in C "<stdlib>" called program control function.
			default : printf("\nWrong selection!!! Try again!!!");
		} 
	} while(choice!=5);
}

void enQueue_front(){
	system("cls");
	struct node* newnode; 
	int item;
	newnode = (struct node*)malloc(sizeof(struct node));
	if(newnode == NULL){
		printf("\nOVERFLOW");
	} 
	else{
		printf("\nEnter item value: ");
		scanf("%d",&item);
		newnode->data = item;
		if(head == NULL){
			head = rear = newnode;
			newnode->next = newnode;
			newnode->prev = newnode;
		}
		else{
			newnode->next = head;
			newnode->prev = rear;
			rear->next = newnode;
			head->prev = newnode;
			head = newnode;
		}
	}		
}


void enQueue_rear(){
	system("cls");
	struct node* newnode;
	int item;
	newnode = (struct node*)malloc(sizeof(struct node));
	if(newnode == NULL){
		printf("\nOVERFLOW");
	}
	else{
		printf("\nEnter item value: ");
		scanf("%d",&item);
		newnode->data = item;
		if(head == NULL){
			head = rear = newnode;
			newnode->next = newnode;
			newnode->prev = newnode;
		}
		else{
			newnode->next = head;
			newnode->prev = rear;
			rear->next = newnode;
			head->prev = newnode;
			rear = newnode;
		}
	}
}

void deQueue_front(){
	system("cls");
	struct node* temp = head;
	if(head == NULL){
		printf("\nUNDERFLOW");
	}
	else{
		if(head == rear){
			head = rear = NULL;
		}
		else{
			head = head->next;
			head->prev = rear;
			rear->next = head;
		}
	}
	printf("%d has been dequeued\n",temp->data);
	free(temp);
}

void deQueue_rear(){
	system("cls");
	struct node* temp = rear;
	if(head == NULL){
		printf("\nUNDERFLOW");
	}
	else{
		if(head == rear){
			head = rear = NULL;
		}
		else{
			rear = rear->prev;
			rear->next = head;
			head->prev = rear;
		}
	}
	printf("%d has been dequeued\n",temp->data);
	free(temp);
}

void display(){
	if (head == NULL) {
        printf("Queue is empty.\n");
        return;
    }

    struct node* current = head;
    printf("Queue elements: ");

    do {
        printf(" %d ",current->data);
        current = current->next;
    } while (current != head);

    printf("\n");
}
