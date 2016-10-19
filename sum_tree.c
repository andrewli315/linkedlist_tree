#include <stdio.h>
#include <stdlib.h>

int stack[100];
int cp_stk[100];
void copy(void);
int pop(void);
int cp_pop(void);
int top = -1;
int cp_top=-1;
int isEmpty();
void push(int);
typedef struct Node{
	int num;
	struct node *parent;
}node;
node* new_node(int x);
int main(void)
{
	char str[] = "(7(8(0 2 4)0 9(10 2(0 6))))\0";
	node *ptr,*parent;
	node **p = (node**)malloc(sizeof(node*));
	node *tmp;
	int k=0;
	int i;
	int l;
	int level =0;
	int flag = 0;
	int j=0;
	int temp;
	char num[100];
	for(i=0;i<100;i++)
	{
		p[i] = (node*)malloc(sizeof(node));
	}
	i=0;
	while(str[i]!='\0')
	{
		if(str[i] == '(') 
		{
			level++;
			num[j] = '\0';
			push(atoi(num));
			j=0;
		}
		else if(str[i] >='0' && str[i] <= '9')
		{
			num[j++] = str[i];
		}
		else if(str[i] == ')')
		{
			if(str[i-1] >= '0' && str[i-1] <= '9')
			{
				num[j] = '\0';
				p[k] = new_node(atoi(num));
				printf("%d\n",atoi(num));
				tmp = p[k];
				while(isEmpty()!=0)
				{
					tmp->parent = new_node(pop());
					tmp = tmp->parent;
				}
				j=0;
				level--;
				k++;
				copy();
				pop();
				cp_pop();
			}

			
		}
		else if(str[i] == ' ')
		{
			num[j] = '\0';
			p[k] = new_node(atoi(num)) ;
			tmp = p[k];
			while(isEmpty() != 0)
			{
				tmp->parent = new_node(pop());
				tmp = tmp->parent;
			}
			j=0;
			copy();
			k++;
		}
		i++;

	}
	for(l=0;l<k;l++)
	{
		tmp = p[l];
		while(tmp->parent!=NULL)
		{
			printf("%d-> ",tmp->num);
			tmp = tmp->parent;
		}
		printf("\n");
	}
	return 0;
}
node* new_node(int x)
{
	node *new;
	new =(node*)malloc(sizeof(node));
	new->num = x;
	return new;
}
int isEmpty()
{
	if(top == -1)
		return 0;
	else
		return 1;
}
int pop(void)
{
	return stack[top--];
}
void push(int x)
{
	stack[++top] = x;
	cp_stk[++cp_top] = x;
}
int cp_pop()
{
	return cp_stk[cp_top--];
}
void copy(void)
{
	int i;
	for(i=0;i<100;i++)
	{
		stack[i] = cp_stk[i];
	}
	top = cp_top;
}
