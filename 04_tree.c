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
void dellist(List *listadd)
{
 NodeOfList *tm_, *nlistadd;
 tm_ = listadd->first;
 do
 {
 nlistadd = tm_;
 tm_ = tm_->next;
 free(nlistadd);
 } while (tm_);
 listadd->first = NULL;
 listadd->last = NULL;
}
void init(Tree *tree) { 
 tree->root = NULL;
}
void clear(Tree *tree) { 
 while (tree->root != NULL)
 RemoveMin(tree->root, tree);
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
int RemoveMin(Node *n, Tree *t) {
 t->count--;
 if (t->count != 1) {
 while (n->left != NULL)
 n = n->left;
 if (n->right != NULL) {
 n->right->parent = n->parent;
 if (n == t->root)
 t->root = n->right;
 else
 n->parent->left = n->right;
 }
 else
 n->parent->left = NULL;
 int data = n->data;
 free(n);
 return data;
 }
 else {
 t->root = NULL;
 t->count = 0;
 free(t->root);
 return 0;
 }
}
Node *search(Node *node, int data) { 
 if ((node == NULL) || (node->data == data))
 return node;
 if (data < node->data)
 return search(node->left, data);
 else
 return search(node->right, data);
}
Node *min(Node *root) { 
 Node *l = root;
 while (l->left != NULL)
 l = l->left;
 return l;
}
int findNode(Tree *tree, int data, Node **node) { 
 Node * tm_ = (Node *) malloc(sizeof(Node));
 Node *root2 = (Node *) malloc(sizeof(Node));
 root2 = tree->root;
 tm_ = search(root2, data);
 if (tm_ == NULL) {
 return 1;
 }
 *node = tm_;
 return 0;
}
int rotateLeft(Tree* tree) {
 Node *tm_ = tree->root->right;
 if (tm_ == NULL)
 return 1;
 tree->root->right = tm_->left;
 tm_->left = tree->root;
 tm_->parent = tree->root->parent;
 tree->root->parent = tm_;
 tree->root = tm_;
 return 0;
}
int rotateRight(Tree *tree) {
 Node *tm_ = tree->root->left;
 if (tm_ == NULL)
 return 1;
 tree->root->left = tm_->right;
 tm_->right = tree->root;
 tm_->parent = tree->root->parent;
 tree->root->parent = tm_;
 tree->root = tm_;
 return 0;
}
void print(Node* node)
{
 if (node)
 {
 List list1, list2;
 List *z = &list1;
 List *s = &list2;
 createlist(z);
 createlist(s);
 Node *tm_ = NULL;
 NodeOfList* listadd = NULL;
 int c = 0, value_ = node->data, j = 0;
 Node *l =(Node *) malloc(sizeof(Node));
l = node->left;
 Node *r =(Node *) malloc(sizeof(Node));
 r = node->right;
 push(z, node);
 while (1)
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
 printf("_\n");
 else
 printf("%d\n", tm_->data);
 }
 else if (tm_->data == value_ && c == 1)
 printf("_ ");
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
void printTree(Tree *tree) {
 print(tree->root);
}
Node* _Remove(Node* tree, int data)
{
 Node* temp;
 if (!tree) {
 return tree;
 }
 else if (data < tree->data) {
 tree->left = _Remove(tree->left, data);
 }
 else if (data > tree->data) {
 tree->right = _Remove(tree->right, data);
 }
 else {
 if (tree->left && tree->right) {
 temp = min(tree->right);
 temp->left = tree->left;
 temp = tree->right;
 free(tree);
 return temp;
 }
 else if (tree->left == tree->right) {
 free(tree);
 return NULL;
 }
 else {
 if (!tree->left) temp =tree->right;
 else temp = tree->left;
 free(tree);
 return temp;
 }
 }
 return tree;
}
int Remove(Tree *tree, int data) {
 Node *tm_ = _Remove(tree->root, data);
 if (!tm_)
 return 1;
 else {
 tree->count--;
 tree->root = tm_;
 return 0;
 }
}
void special (int m,Tree * tree)
{
     Node *treeN = (Node*)malloc(sizeof(Node));
 if (findNode(tree, m, &treeN) == 1)
     printf("-\n");
 else {
     if (treeN->parent == NULL)
 printf("_ ");
 else
     printf("%d ", treeN->parent->data);
 if (treeN->left == NULL)
     printf("_ ");
 else
     printf("%d ", treeN->left->data);
 if (treeN->right == NULL)
     printf("_ ");
 else
     printf("%d ", treeN->right->data);
 }
}
int main() {
 Tree *check = (Tree*)malloc(sizeof(Node));
 init(check);
 int a[4];
 scanf("%d%d%d%d", &a[0], &a[1], &a[2], &a[3]);
 for (int i = 0; i < 4; i++)
 insert(check, a[i]);
 print(check->root);
 scanf("%d%d%d", &a[0], &a[1], &a[2]);
 for (int i = 0; i < 3; i++)
 insert(check, a[i]);
 print(check->root);
 int m;
 scanf("%d", &m);
 special(m,check);
 printf("\n");
 scanf("%d", &m);
special(m,check);
 scanf("%d", &m);
 Remove(check, m);
 print(check->root);
 while (rotateLeft(check) == 0);
 print(check->root);
 while (rotateRight(check) == 0);
 print(check->root);
 printf("%d\n", check->count);
 clear(check);
 print(check->root);
 
}

