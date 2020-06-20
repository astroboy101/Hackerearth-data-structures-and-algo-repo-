#include<stdio.h>
#include<stdlib.h>
struct node
{
	int n;
	struct node* next,*back;
}*top=NULL,*p,*top_even=NULL;
struct node *add(int k)
{
	struct node* newnode;
	newnode=(struct node*)(malloc(sizeof(struct node)));
	newnode->n=k;
	newnode->next=NULL;
	if(top==NULL)
	top=newnode;
	else
	{
		p=top;
		while(p->next!=NULL)
		p=p->next;
		p->next=newnode;
		newnode->back=p;
	}
	return top;
}
struct node* stack(int k)
{
	struct node* newnode;
	newnode=(struct node*)(malloc(sizeof(struct node)));
	newnode->n=k;
	newnode->next=NULL;
 if(top_even==NULL)
	top_even=newnode;
	else
	{
		p=top_even;
		while(p->next!=NULL)
		p=p->next;
		p->next=newnode;
		newnode->back=p;
	}
return top_even;
}
main()
{
	int n,count=0;
	long long int m,i;
	struct node *temp_node,*temp_top,*origi;
	scanf("%lld",&m);
	for(i=0;i<m;i++)
	{scanf("%d",&n);
	add(n);}
	origi=add(0);

	while(top->next!=NULL)
	{
		if ((top->n%2==0) && (top->n!=0))
		{
			stack(top->n);
			count++;
		}
		else{
			if (top_even!=NULL &&top->n!=0)
			{temp_node=top->back;
				temp_top=top_even;
				while(count!=0)
				{
					temp_node->n=temp_top->n;
					temp_node=temp_node->back;
					temp_top=temp_top->next;
					count--;
				}
				top_even=NULL;
			}
		}
		top=top->next;

	}
	if (top_even!=NULL &&top->n==0)
			{temp_node=top->back;
				temp_top=top_even;
				while(count!=0)
				{
					temp_node->n=temp_top->n;
					temp_node=temp_node->back;
					temp_top=temp_top->next;
					count--;
				}
			}
	top=origi;
	while(top->n!=0)
	{
		printf("%d ",top->n);
		top=top->next;
	}

}
