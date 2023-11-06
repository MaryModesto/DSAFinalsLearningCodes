/* * * * * * * * * * * * * * * * * * 
* AUTHOR: MODESTO, MARY CHEVEL P.   *
* SCHOOL YEAR: 2023 - 2024          *
* DSA PROF: MA'AM PINEAPPLE         *
* DATE: NOVEMBER 1, 2023            *
* * * * * * * * * * * * * * * * * */

/*NOTE: THE CONTRAINTS FOR THIS IMPLEMENTATION ARE THAT THE NODES HAVE TO BE IN SEQUENTIAL ORDER*/

#include <stdio.h>
#include <stdlib.h>
#define MAX 10
#define ROOT -1
#define DNS -2

typedef int TREE[MAX];
typedef int node;
typedef int label;

void Display(TREE T);
node Parent(node N, TREE T);
node Leftmost_Child(node N, TREE T);
node Right_Sibling(node N, TREE T);
label Label(node N, TREE T);
node Root(TREE T);
void Initialize(TREE T, int values[]);
void MakeNULL(TREE T);

//SINCE WITHIN THIS IMPLEMENTATION, WE ARE ABLE TO DISTINGQUISH ALREADY THE LEFTMOST AND
//RIGHTMOST NODES, WE CAN ALSO DO THE PREORDER, INORDER, AND POSTORDER TRAVERSALS:)
void Prefix(TREE T, node root);
void Infix(TREE T);
void Postfix(TREE T);

int main()
{
    TREE myTree;
    int myArr[] = {ROOT, 0, 0, 0, 1, 2, 2, 6, 6, 3};

    //INITIALIZE MY TREE
    Initialize(myTree, myArr);
    Display(myTree);

    //PRINT OUT THE LEFTMOST CHILD OF EVERY NODE
    int x;
    for (x = 0; x < MAX; ++x) {
        printf("[%d] => %d\n", x, Leftmost_Child(x, myTree));
    }
    printf("\n");

    //PRINT OUT THE RIGHT SIBLING OF EVERY NODE
    for (x = 0; x < MAX; ++x) {
        printf("[%d] => %d\n", x, Right_Sibling(x, myTree));
    }
    printf("\n");
    return 0;
}

void Display(TREE T) {
    int x;
    for (x = 0; x < MAX; ++x) {
        printf("[%d] => ", x);
        if (T[x] == ROOT) {
            printf("ROOT");
        } else if (T[x] == DNS) {
            printf("DNS");
        } else{
            printf("%d", T[x]);
        }
        printf("\n");
    }
    printf("\n");
}

node Parent(node N, TREE T) {
    return T[N] != DNS && T[N] != ROOT ? T[N] : DNS;
}

node Leftmost_Child(node N, TREE T) {
    int retVal = DNS;
    
    if (T[N] != DNS && T[N] != MAX - 1) {
        int x;
        for (x = N; x < MAX && T[x] != N; ++x) {}
        retVal = (x == MAX ? DNS : x);
    }
    return retVal;
}

node Right_Sibling(node N, TREE T) {
    return T[N] == ROOT || T[N] == DNS || N == MAX - 1 ? DNS : T[N] == T[N + 1] ? N + 1 : DNS;
}

label Label(node N, TREE T) {
    return T[N];
}

node Root(TREE T) {
    return 0;
}

void Initialize(TREE T, int values[]) {
    int x;
    for (x = 0; x < MAX; ++x) {
        T[x] = values[x];
    }
}

void MakeNULL(TREE T) {
    int x;
    for (x = 0; x < MAX; ++x) {
        T[x] = DNS;
    }
}

//THE TRAVERSAL FUNCTIONS START HERE
void Prefix(TREE T, node root) {
    if (root != 10) {
        printf("%d ", T[root]);
    }
}
void Infix(TREE T);
void Postfix(TREE T);