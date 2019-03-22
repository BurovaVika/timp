#include <stdio.h>
#include<stdlib.h>

typedef struct element {
	int value;
	struct element *next;
	struct element *prev;
} element;

typedef struct s_list{		
	struct element* head;
	struct element* tail;	
} s_list;

void init(s_list* lst)
{
	lst->head=lst->tail=NULL;
}

int isEmpty(s_list* lst)
{
	return lst->head==NULL;
}

element* find(s_list* lst,int k)
{
	element *tmp=lst->head;
	while(tmp->value!=k){
		if(tmp->next!=NULL)
			tmp=tmp->next;
		else
			return NULL;
	}
	return tmp;
}

element* rfind(s_list* lst,int k)
{
	element *tmp=lst->tail;
	while(tmp->value!=k){
		if(tmp->prev!=NULL)
			tmp=tmp->prev;
		else
			return NULL;
	}
	return tmp;
}

int push_back(s_list* lst, int value)
{
	if(isEmpty(lst)==1){
		lst->head = lst->tail = malloc(sizeof(element));
		lst->head->value=value;
		lst->head->next=lst->head->prev=NULL;
	}
	else
	{
		element *tmp = malloc(sizeof(element));
		tmp->value=value;
		tmp->prev=lst->tail;
		tmp->next=NULL;
		lst->tail=tmp;
		tmp->prev->next=tmp;
	}
	return 0;
}

int push_front(s_list* lst,int value) 
{
	if(isEmpty(lst)==1){
		lst->head = lst->tail = malloc(sizeof(element));
		lst->head->value=value;
		lst->head->next=lst->head->prev=NULL;
	}
	else
	{
		element *tmp = malloc(sizeof(element));
		tmp->value=value;
		tmp->prev=NULL;
		tmp->next=lst->head;
		lst->head=tmp;
		tmp->next->prev=tmp;
	}
	return 0;
}

int clear(s_list* lst)
{
	if(isEmpty(lst)!=0)
	{
		element *tmp=lst->head;
		element *next_element=NULL;
		while(tmp!=NULL)
		{
			next_element=tmp->next;
			free(tmp);
			tmp=next_element;
		}
		lst->head=lst->tail=NULL;
	}
}

void _remove(s_list* lst, element *tmp){
	if(tmp!=NULL){
		if (tmp==lst->head && tmp==lst->tail) {
			clear(lst);
			return;
		}
		if (tmp==lst->head)
		{
			lst->head=tmp->next;
			tmp->next->prev=NULL;
		}
		else if(tmp==lst->tail)
		{
			lst->tail=tmp->prev;
			tmp->prev->next=NULL;
		}
		else if (tmp!=lst->head && tmp!=lst->tail)
		{
			tmp->next->prev=tmp->prev;
			tmp->prev->next=tmp->next;
		}
		free(tmp);
	}
}

int removeLast(s_list* lst,int x)
{
	element* element = rfind(lst,x);
	if (element!=NULL){
		_remove(lst,element);
		return 0;
	}
	return -1;
}

int removeFirst(s_list* lst, int x)
{
	element* element = find(lst,x);
	if (element!=NULL){
		_remove(lst,element);
		return 0;
	}
	return -1;
}

int insertAfter	(s_list* lst,int num, int data)
{
	element* tmp = lst->head;
	for (int i = 1;i<num;i++)
	{
		tmp=tmp->next;
		if(tmp==NULL) 
			return -1;
	}
	element *temp = malloc(sizeof(element));
	temp->value=data;
	temp->next=tmp->next;
	temp->prev=tmp;
	tmp->next->prev=temp;
	tmp->next=temp;  
	return 0;   
}

int insertBefore(s_list* lst,int num, int data)
{
	element* tmp = lst->head;
	for (int i = 1;i<num;i++)
	{
		tmp=tmp->next;
		if(tmp==NULL) 
			return -1;
	}
	element *temp = malloc(sizeof(element));
	temp->value=data;
	temp->prev=tmp->prev;
	temp->next=tmp;
	tmp->prev=temp;
	temp->prev->next=temp;      
	return 0; 
}

void print(s_list* lst)
{
	element* tmp=lst->head;
	while(tmp->next!=NULL)
	{
		printf("%d ", tmp->value);
		tmp=tmp->next;
	}
	printf("%d\n", tmp->value);
}

void print_invers(s_list* lst)
{
	element* tmp=lst->tail;
	while(tmp->prev!=NULL)
	{
		printf("%d ", tmp->value);
		tmp=tmp->prev;
	}
	printf("%d\n", tmp->value);	
}



int main()
{
	int n,a,k[3],m,t,j,x,u,y,z,r;

	s_list* lst=malloc(sizeof(s_list));	
	scanf("%d",&n);
	for (int i=0;i<n;i++)
	{
		scanf("%d",&a);
		push_back(lst,a);
	}
	print(lst);
	
	for(int i=0;i<3;i++){
		scanf("%d",&k[i]);
		if(find(lst,k[i])!=NULL)
			printf("1");
		else
			printf("0");
	}
	printf("\n");

	scanf("%d",&m);
	push_back(lst,m);
	print_invers(lst);

	scanf("%d",&t);
	push_front(lst,t);
	print(lst);

	scanf("%d%d",&j,&x);
	insertAfter(lst,j,x);
	print_invers(lst);

	scanf("%d%d",&u,&y);
	insertBefore(lst,u,y);
	print(lst);

	scanf("%d",&z);
	removeFirst(lst,z);
	print_invers(lst);

	scanf("%d",&r);
	removeLast(lst,r);
	print(lst);

	clear(lst);
	return 0;
}
