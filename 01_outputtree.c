
#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int data;
     struct Node *left;
     struct Node *right;
     struct Node *parent;
} Node;

typedef struct tree
{
     struct Node *root;
     int count;
} Tree;

typedef struct listNode
{
     Node *PtrTree;
     struct listNode *next;
}NodeOfList;

typedef struct list
{
     NodeOfList *first;
     NodeOfList *last;
}List;
void createlist(List *listadd)
{
     listadd->first = NULL;
     listadd->last = NULL;
};

int push(List *listadd, Node *n)
{
     NodeOfList *newList = (NodeOfList*)malloc(sizeof(NodeOfList));
     newList->PtrTree = n;
     newList->next = NULL;
     if (listadd->first)
     {
         listadd->last->next = newList;
     }
 else
     listadd->first = newList;
 listadd->last = newList;
 return 0;
}

void dellist(List *listadd)
{
     NodeOfList *tm_, *nlistadd;
     tm_ = listadd->first;
 do
 {
     nlistadd = tm_;
     tm_ = tm_->next;
     free(nlistadd);
 } 
 while (tm_);
 listadd->first = NULL;
 listadd->last = NULL;
}

void init(Tree *tree) { 
 tree->root = NULL;
}


int insert(Tree *tree, int data) { 
 Node *tm_ = (Node*)malloc(sizeof(Node));
 tm_->data = data;
 if (tree->root == NULL)
 {
     tm_->left = NULL; 
     tm_->right = NULL;
     tm_->parent = NULL;
     tree->root = tm_;
     tree->count = 1;
     return 0;
 }
 if (tm_->data == tree->root->data)
     return -1;
 Node *root2 = (Node*)malloc(sizeof(Node)), *AddRoot = NULL;
 root2 = tree->root;
 while (root2 != NULL)
 {
     AddRoot = root2;
     if (data < root2->data)
         root2 = root2->left;
     else
         root2 = root2->right;
 }
 if (tm_->data == AddRoot->data) 
 {
     return -1; 
 }
 tm_->parent = AddRoot;
 tm_->left = NULL;
 tm_->right = NULL;
 if (data < AddRoot->data)
     AddRoot->left = tm_;
 else
     AddRoot->right = tm_;
 tree->count++;
 return 0;
}

Node *search(Node *node, int data) { 
     if ((node == NULL) || (node->data == data))
         return node;
     if (data < node->data)
         return search(node->left, data);
     else
         return search(node->right, data);
}

Node *min(Node *root)
{ 
     Node *l = root;
     while (l->left != NULL)
     l = l->left;
     return l;
}

int findNode(Tree *tree, int data, Node *node)
{ 
     Node * tm_ = (Node *) malloc(sizeof(Node));
     Node *root2 = (Node *) malloc(sizeof(Node));
     root2 = tree->root;
     tm_ = search(root2, data);
     if (tm_ == NULL)
     {
         return 1;
     }
     node = tm_;
     return 0;
}

void print(Node* node)
{
     if (node)
     {
         Node *l =(Node *) malloc(sizeof(Node));
         Node *r =(Node *) malloc(sizeof(Node));
         List list1, list2;
         List *z = &list1;
         List *s = &list2;
         createlist(z);
         createlist(s);
         Node *tm_ = NULL;
         NodeOfList* listadd = NULL;
         int c = 0, value_ = node->data;
         int j = 0;
         l = node->left;
         r = node->right;
         push(z, node);
     while (2)
     {
         while (z->first)
             {
             if (z->first)
             {
                 NodeOfList *pop;
                 tm_ = z->first->PtrTree;
                 pop = z->first;
                 z->first = z->first->next;
                 if (z->first == NULL)
                     z->last = NULL;
                 free(pop);
              }
              else
                  tm_ = NULL;
              if (z->first == NULL)
              {
                  if (tm_->data == value_ && c == 1)
                      printf("");
                  else
                      printf("%d ", tm_->data);
              }
              else 
              if (tm_->data == value_ && c == 1)
                  printf("");
              else
                 printf("%d ", tm_->data);
              if (tm_->left)
                 push(s, tm_->left);
              else
                  push(s, node);
              if (tm_->right)
                  push(s, tm_->right);
              else
                    push(s, node);
            }
            node->left = node->right = NULL;
            c = 1;
            listadd = s->first;
            while (s->first->PtrTree->data == value_)
            {
                s->first = s->first->next;
                if (s->first->next == NULL)
                if (s->first->PtrTree->data == value_)
                {
                   j = 1;
                   node->left = l;
                   node->right = r;
                   dellist(s);
                  break;
                }
             }
            s->first = listadd;
            if (j == 1)
                break;
            z->first = s->first;
            z->last = s->last;
            s->first = NULL;
            s->last = NULL;
            }
     }
     else
         printf("-\n");
}

void printTree(Tree *tree)
{
     print(tree->root);
}

int main()
{
    Tree *tree = (Tree*)malloc(sizeof(Node));
	init(tree);

	int a;
	for (int i = 0; i < 7; i++)
	{scanf("%d",&a);
		insert(tree, a);}

print(tree->root);

printf("\n");	

    return 0;
}

