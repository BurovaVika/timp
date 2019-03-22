#include <stdio.h>
#include<stdlib.h>

typedef struct element {
	int value;
	struct element *next;
} element;

typedef struct s_list{		
	struct element* head;	
} s_list;


void init(s_list* lst)
{
	lst->head=NULL;
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

int push_back(s_list* lst, int value)
{
	if(isEmpty(lst)==1){
		lst->head = malloc(sizeof(element));
		lst->head->value=value;
		lst->head->next=NULL;
	}
	else
	{

		element* temp = lst->head;
		while(temp->next!=NULL)
			temp=temp->next;
		temp->next=malloc(sizeof(element));
		temp->next->value=value;
		temp->next->next=NULL;
	}
	return 0;
}

int push_front(s_list* lst,int value) 
{
	if(isEmpty(lst)==1){
		lst->head = malloc(sizeof(element));
		lst->head->value=value;
		lst->head->next=NULL;
	}
	else
	{
		element *tmp = malloc(sizeof(element));
		tmp->value=value;
		tmp->next=lst->head;
		lst->head=tmp;
	}
	return 0;
}

int clear(s_list* lst)
{
	if(isEmpty(lst)!=0){
		element *tmp=lst->head,*next_element=NULL;
		while(tmp!=NULL)
		{
			next_element=tmp->next;
			free(tmp);
			tmp=next_element;
		}
		lst->head=NULL;
	}
}

void _remove(s_list* lst, element *tmp){
	if(tmp!=NULL){
		if (tmp==lst->head)
			lst->head=tmp->next;
		else
		{
			element *temp = lst->head;
			while(temp->next!=tmp)
				temp=temp->next;
			temp->next = tmp->next;
		}
		free(tmp);
	}
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

int insertAfter	(s_list* lst,int num, int value)
{
	element* tmp = lst->head;
	element* prev_tmp = lst->head;
	for (int i = 1;i<num+1;i++)
	{
		prev_tmp=tmp;
		tmp=tmp->next;
		if(tmp==NULL) 
			return -1;
	}
	element* temp = malloc(sizeof(element));
	prev_tmp->next=temp;
	temp->next=tmp;
	temp->value=value;
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

int main()
{
	int n,a,k[3],m,t,j,x,z;
	s_list* lst=malloc(sizeof(s_list));
	init(lst);	
	scanf("%d",&n); //1
	for (int i=0;i<n;i++)
	{
		scanf("%d",&a);
		push_back(lst,a);//2
	}
	print(lst);//3
	
	for(int i=0;i<3;i++){
		scanf("%d",&k[i]);//4
		if(find(lst,k[i])!=0)
			printf("1");//4
		else
			printf("0");
	}
	printf("\n");

	scanf("%d",&m);
	push_back(lst,m);//5
	print(lst);//6

	scanf("%d",&t);
	push_front(lst,t);//7
	print(lst);//8

	scanf("%d%d",&j,&x);
	insertAfter(lst,j,x); // 9
	print(lst);//10

	scanf("%d",&z);
	removeFirst(lst,z);//11
	print(lst);//12

	clear(lst);//13
	return 0;
}
