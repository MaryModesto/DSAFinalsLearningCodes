#include <stdio.h>
#define MAX 10

typedef struct {
    int Heap[MAX];
    int lastNdx;
}PQueue;

void Initialize(PQueue *M);
void Display(PQueue M);
void Insert(PQueue *M, int elem);
int DeleteMin(PQueue *M);
void MinHeap(PQueue *M);

int main()
{
    PQueue myPQueue;
    int mySet[] = {4, 3, 7, 9, 6, 6, 2, 19, 4};

    //initialize the queue
    Initialize(&myPQueue);

    //insert values within my queue
    int x, count = 9;
    for (x = 0; x < count; ++x) {
        Insert(&myPQueue, mySet[x]);
    }

    //display intitial queue
    Display(myPQueue);

    //delete minimum value
    DeleteMin(&myPQueue);

    //display updated queue
    Display(myPQueue);

    //minheapify my queue
    MinHeap(&myPQueue);

    //display updated queue
    Display(myPQueue);
    return 0;
}

void Display(PQueue M) {
    printf("Last Index: [%d]\n", M.lastNdx);

    int x;
    for (x = 0; x <= M.lastNdx; ++x) {
        printf("[%d]", M.Heap[x]);
    }
    printf("\n\n");
}

void Initialize(PQueue *M) {
    M->lastNdx = -1;
}

void Insert(PQueue *M, int elem) {
    if (M->lastNdx < MAX) {
        int newNdx = ++(M->lastNdx);
        M->Heap[newNdx] = elem;

        for (; newNdx > 0 && M->Heap[newNdx / 2] > elem; newNdx /= 2) {
            M->Heap[newNdx] = M->Heap[newNdx / 2];
            M->Heap[newNdx / 2] = elem;
        }
    }
}

int DeleteMin(PQueue *M) {
    int retVal = M->Heap[0], currNdx = 0, sValNdx, temp;
    if (M->lastNdx != -1) {
        M->Heap[0] = M->Heap[M->lastNdx--];

        for (sValNdx = M->Heap[((currNdx)*2) + 1] < M->Heap[((currNdx)*2) + 2] ? 1 : 2; currNdx < M->lastNdx && M->Heap[currNdx] >= M->Heap[sValNdx]; ) {
            temp = M->Heap[currNdx];
            M->Heap[currNdx] = M->Heap[sValNdx];
            M->Heap[sValNdx] = temp;
            currNdx = sValNdx;

            if ((currNdx*2) + 1 <= M->lastNdx) {
                sValNdx = M->Heap[(currNdx*2) + 1] < M->Heap[(currNdx*2) + 2] ? (currNdx*2) + 1 : (currNdx*2) + 2;
            } else {
                currNdx = MAX + 1;
            }
        }
    }

    return M->lastNdx == -1? -1 : retVal;
}

void MinHeap(PQueue *M) {
    int oldNdx = M->lastNdx, x;

    for (x = oldNdx; x > 0; --x) {
        M->Heap[x] = DeleteMin(M);
    }
    M->lastNdx = oldNdx;
}