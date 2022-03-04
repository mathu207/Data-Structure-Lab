#include<stdlib.h>
#include <stdio.h>
void display();
void insert_begin();
void insert_end();
void insert_pos();
void delete_begin();
void delete_end();
void delete_pos();
struct node
{
int info;
struct node *next;
};
struct node *start=NULL;
int main()
{
int choice;
while(1)
{
printf("\n____________________________");
printf("\n 1.Insert at the beginning");
printf("\n 2.Insert at the end");
printf("\n 3.Insert at specified position");
printf("\n 4.Delete from beginning");
printf("\n 5.Delete from the end");
printf("\n 6.Delete from specified position");
printf("\n 7.Display");
printf("\n 8.Exit");
printf("\nEnter your choice:");
scanf("%d",&choice);
switch(choice)
{
case 1:
insert_begin();
break;
case 2:
insert_end();
break;
case 3:
insert_pos();
break;
case 4:
delete_begin();
break;
case 5:
delete_end();
break;
case 6:
delete_pos();
break;
case 7:
display();
break;
case 8:
exit(0);
break;
default:
printf("n Wrong Choice:n");
break;
}
}
return 0;
}
void display()
{
struct node *ptr;
if(start==NULL)
{
printf("List is empty\n");
return;
}
else
{
ptr=start;
printf("The List elements are:");
while(ptr!=NULL)
{
printf("%d ",ptr->info );
ptr=ptr->next ;
}
}
}
void insert_begin()
{
struct node *temp;
temp=(struct node *)malloc(sizeof(struct node));
if(temp==NULL)
{
printf("Out of Memory Space\n");
return;
}
printf("Enter the data value for the node:" );
scanf("%d",&temp->info);
temp->next =NULL;
if(start==NULL)
{
start=temp;
}
else
{
temp->next=start;
start=temp;
}
display();
}
void insert_end()
{
struct node *temp,*ptr;
temp=(struct node *)malloc(sizeof(struct node));
if(temp==NULL)
{
printf("Out of Memory Space\n");
return;
}
printf("Enter the data value for the node:" );
scanf("%d",&temp->info );
temp->next =NULL;
if(start==NULL)
{
start=temp;
}
else
{
ptr=start;
while(ptr->next !=NULL)
{
ptr=ptr->next ;
}
ptr->next =temp;
}
display();
}
void insert_pos()
{
struct node *ptr,*temp;
int i,pos;
temp=(struct node *)malloc(sizeof(struct node));
if(temp==NULL)
{
printf("Out of Memory Space\n");
return;
}
printf("Enter the position for the new node to be inserted:");
scanf("%d",&pos);
printf("Enter the data value of the node:");
scanf("%d",&temp->info);
temp->next=NULL;
if(pos==0)
{
temp->next=start;
start=temp;
}
else
{
for(i=0,ptr=start;i<pos-1;i++)
{
ptr=ptr->next;
if(ptr==NULL)
{
printf("Position not found.\n");
return;
}
}
temp->next =ptr->next ;
ptr->next=temp;
}
display();
}
void delete_begin()
{
struct node *ptr;
if(start==NULL)
{
printf("The List is Empty.\n");
return;
}
else
{
ptr=start;
start=start->next ;
printf("The deleted element is :%d",ptr->info);
free(ptr);
}
display();
}
void delete_end()
{
struct node *temp,*ptr;
if(start==NULL)
{
printf("List is Empty.\n");
return;
}
else if(start->next ==NULL)
{
ptr=start;
start=NULL;
printf("The deleted element is:%d",ptr->info);
free(ptr);
}
else
{
ptr=start;
while(ptr->next!=NULL)
{
temp=ptr;
ptr=ptr->next;
}
temp->next=NULL;
printf("The deleted element is:%d",ptr->info);
free(ptr);
}
display();
}
void delete_pos()
{
int i,pos;
struct node *temp,*ptr;
if(start==NULL)
{
printf("The List is Empty.\n");
return;
}
else
{
printf("Enter the position of the node to be deleted:");
scanf("%d",&pos);
if(pos==0)
{
ptr=start;
start=start->next ;
printf("The deleted element is:%d",ptr->info );
free(ptr);
}
else
{
ptr=start;
for(i=0;i<pos;i++)
{
temp=ptr; ptr=ptr->next ;
if(ptr==NULL)
{
printf("Position not Found.\n");
return;
}
}
temp->next =ptr->next ;
printf("The deleted element is:%d",ptr->info );
free(ptr);
}
}
display();
}
