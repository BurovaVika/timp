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
 listadd->last->next = newList;
 else
 listadd->first = newList;
 listadd->last = newList;
 return 0;
}
void init(Tree *tree) { 
 tree->root = NULL;
}
int insert(Tree *tree, int data) { 
 Node *tm_ = (Node*)malloc(sizeof(Node));
 tm_->data = data;
 if (tree->root == NULL) {
 tm_->left = tm_->right = NULL;
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
 if (tm_->data == AddRoot->data) {
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
void print_(Node* r) {
    if (r) {
        print_(r->left);
        print_(r->right);
        printf("%d ", r->data);
    }
}
int main()
{
    Tree *tree = (Tree*)malloc(sizeof(Node));
	init(tree);

	int a;
	for (int i = 0; i < 7; i++)
	{scanf("%d",&a);
		insert(tree, a);
}
print_(tree -> root);

printf("\n");	

    return 0;
}

