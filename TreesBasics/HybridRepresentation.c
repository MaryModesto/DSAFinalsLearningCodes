#include <stdio.h>
#include <stdlib.h>
#define MAX 10
#define DNS -1

typedef struct Node {
    int key;
    struct Node *link;
}*NodeType;

typedef struct {
    NodeType Child;
    int Parent;
}Header;

typedef struct {
    Header H[MAX];
}TREE;

typedef int node;
typedef int label;

void Display(TREE T);
void Children(node N, TREE T);
node Parent(node N, TREE T);
node Leftmost_Child(node N, TREE T);
node Right_Sibling(node N, TREE T);
label Label(node N, TREE T);
node Root(TREE T);
void Initialize(TREE *T);
void MakeNULL(TREE *T);

int main()
{

    return 0;
}