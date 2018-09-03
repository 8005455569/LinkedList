#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<iostream>
using namespace std;
struct node
{
	int info;
	struct node *prev,*next;
};
struct node* insertatbeg(struct node *start,int data);
struct node* insertatend(struct node *start,int data);
void display(struct node* start);
int main()
{
	int i,data,n;
	struct node *prev=NULL,*start=NULL;
	printf("\n1.Insertion at begning");
	printf("\n2.Insertion at end");
	printf("\n3.Display the linked list");
	printf("\n4.Quit");
	while(1)
	{
			printf("\nEnter your choice");
	        scanf("%d",&n);
		switch(n)
		{
			case 1:
				printf("\nEnter the info part of linked list");
				scanf("%d",&data);
				start=insertatbeg(start,data);
				break;
			case 2:
				printf("\nEnter the info part of linked list");
				scanf("%d",&data);
				start=insertatend(start,data);
			    break;	
			case 3:
				display(start);
			    break;  
			case 4:
			    exit(0);
			default:
			    printf("\nWrong choice");		  
		}
	}
}
struct node* insertatbeg(struct node* start,int data)
{
	struct node *tmp;
	tmp=(struct node*)malloc(sizeof(struct node));
	tmp->info=data;
	tmp->next=NULL;
	tmp->prev=NULL;
	start=tmp;
	return start;
}
struct node* insertatend(struct node* start,int data)
{
	struct node *p,*tmp;
	tmp=(struct node*)malloc(sizeof(struct node));
	tmp->info=data;
	p=start;
	while(p->next!=NULL)
	   p=p->next;
    p->next=tmp;
	tmp->next=NULL;
	tmp->prev=p;
	return start;
}
void display(struct node* start)
{
	struct node* p;
	if(start==NULL)
	{
	 printf("\nlist is empty");
	 return;
	}
	p=start;
	printf("\nList is : ");
	while(p!=NULL)
	{
		printf("%d ",p->info);
		p=p->next;
	}
	printf("\n");
}
