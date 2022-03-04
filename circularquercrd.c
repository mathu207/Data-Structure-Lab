/*13.Write a program to implement Circular Queue*/
#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#define SIZE 2
void enQueue();
void deQueue();
void display();
int cq[SIZE], front = 0, rear = 0;
void main()
{
int choice, value;
while(1)
{
printf("\n1. Insert\n2. Delete\n3. Display\n4. Exit\n");
printf("Enter your choice: ");
scanf("%d",&choice);
switch(choice){
case 1:
enQueue();
break;
case 2:
deQueue();
break;
case 3:
display();
break;
case 4:
exit(0);
default: printf("\nPlease select the correct choice!!!\n");
}
}
}
void enQueue()
{
int value;
if((front == 0 && rear == SIZE) || (front == (rear%SIZE)+1))
printf("\nCircular Queue is Full! Insertion not possible!!!\n");
else
{
printf("\nEnter the value to be insert: ");
scanf("%d",&value);
rear=(rear%SIZE)+1;
cq[rear]=value;
}
}
void deQueue()
{
if((front == 0 && rear == 0)||front == rear)
printf("\nCircular Queue is Empty! Deletion is not possible!!!\n");
else
{
front=(front%SIZE)+1;
printf("The deleted Element is %d",cq[front]);
}
}
void display()
{
int i;
if((front == 0 && rear == 0)||front == rear)
printf("\nCircular Queue is Empty!");
else
{
for(i=front+1;i<=rear;i++)
{
printf("%d\n",cq[i]);
}
}
}
