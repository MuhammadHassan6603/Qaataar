#include<stdio.h>
#include<stdlib.h>
struct queue
{
	int data;
	struct queue *link;
};
void addQ(struct queue **pfront,struct queue **prear,int data)
{
	struct queue *r;
	r=(struct queue *)malloc(sizeof(struct queue));
	r->data=data;
	r->link=NULL;
	if(*pfront==NULL&&*prear==NULL)
	{
		*pfront=r;
		*prear=r;
	}
	else
	{
		(*prear)->link=r;
		*prear=r;
	// 	(*prear)->link=*pfront;     (step for circular queue)
	}
}
void delQ(struct queue **pfront,struct queue **prear)
{
	if(*pfront==NULL&&*prear==NULL)
	{
		printf("Queue is Empty");
	}
	else
	{
		struct queue *temp=*pfront;
		printf("Deletd data is = %d\n",temp->data);
		*pfront=temp->link;
		if(*pfront==NULL)
		{
			*prear=NULL;
		}
		free(temp);
	}
}
//    CIRCULAR QUEUE DISPLAY 
void cirdisplay(struct queue *pfront)
{
	struct queue *temp=pfront;
	while(temp->link!=pfront)
	{
		printf("%d\t",temp->data);
		temp=temp->link;
	}
	printf("%d\t",temp->data);
}
//    SIMPLE QUEUE DISPLAY
void display(struct queue *pfront)
{
	while(pfront!=NULL)
	{
		printf("%d\t",pfront->data);
		pfront=pfront->link;
	}
}
void main()
{
	struct queue *front=NULL,*rear=NULL;
	addQ(&front,&rear,10);
	addQ(&front,&rear,20);
	addQ(&front,&rear,30);
	//cirdisplay(front);     
	display(front);
	printf("\n");
	delQ(&front,&rear);
	delQ(&front,&rear);
	delQ(&front,&rear);
	delQ(&front,&rear);	
}                    
