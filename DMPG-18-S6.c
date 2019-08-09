#include <stdio.h>
#include <stdlib.h>

typedef int unit;
typedef struct {
    int length;
    int size;
    unit * data;
} list;
list * createList(int initialSize) {
    list * l = malloc(sizeof(list));
    l->size = initialSize;
    l->length = 0;
    l->data = calloc(initialSize, sizeof(unit));
    return l;
}
void destroyList(list * l) {
    free(l->data);
    free(l);
}
void append(list * l, unit num) {
    if(l->length + 1 >= l->size) {
        l->size *= 2;
        l->data = realloc(l->data, l->size*sizeof(unit));
    }
    l->data[l->length] = num;
    l->length += 1;
}
unit popRight(list * l) {
    if(l->length == 0) {
        return;
    }
    else if(l->length + 4 <= l->size / 2) {
        l->size /= 2;
        l->data = realloc(l->data, l->size*sizeof(unit));
    }
    l->length -= 1;
    unit removed = l->data[l->length];
    l->data[l->length] = 0;
    return removed;

}
unit pop(list * l, int index) {
    if(l->length == 0) {
        return;
    }
    else if(l->length + 4 <= l->size / 2) {
        l->size /= 2;
        l->data = realloc(l->data, l->size*sizeof(unit));
    }
    unit removed = l->data[index];
    for(int i = index; i < l->length; i++) {
        l->data[i] = l->data[i+1];
    }
    l->length -= 1;
    return removed;
}
void insert(list * l, int index, unit num) {
    if(l->length + 1 >= l->size) {
        l->size *= 2;
        l->data = realloc(l->data, l->size*sizeof(unit));
    }
    for(int i = l->length+1; i > index; i--) {
        l->data[i] = l->data[i-1];
    }
    l->length += 1;
    l->data[index] = num;
}
void printList(list * l) {
    printf("[");
    for(int i = 0; i < l->length-1; i++) {
        printf("%d, ", l->data[i]);
    }
    printf("%d]\n", l->data[l->length-1]);
}

int cmp(const void *a, const void *b) {
    if(((int*)a)[1] < ((int*)b)[1]) return 1;
    else if(((int*)a)[1] == ((int*)b)[1]) return 0;
    else if (((int*)a)[1] > ((int*)b)[1]) return -1;
}

typedef struct Node node;
struct Node {
    node *head;
    long data;
    node *tail;
};
node* insertElement(node *currentElement, long newData) {
    node *newElement = malloc(sizeof(node));
    node *previousElement = currentElement->head;
    newElement->data = newData;
    newElement->head = previousElement;
    newElement->tail = currentElement;
    currentElement->head = newElement;
    previousElement->tail = newElement;
    return newElement;
}
node* deleteElement(node *element) {
    node *nextElement = element->tail;
    element->head->tail = nextElement;
    nextElement->head = element->head;
    free(element);
    return nextElement;
}
void freeList(node *firstElement, node *lastElement) {
    node *element = firstElement->tail;
    node *nextElement = element->tail;
    while(element != lastElement) {
        free(element);
        element = nextElement;
        nextElement = nextElement->tail;
    }
}


int main() {
    int n, m, a, b;
    scanf(" %d %d", &n, &m);
    // 1, 2, ... n
    list * verts[n+1];
    int vertPathCounts[n+1][2];
    for(int i = 1; i <= n; i++) {
        verts[i] = createList(n/2);
        vertPathCounts[i][0] = i;
        vertPathCounts[i][1] = 0;
    }
    for(int i = 0; i < m; i++) {
        scanf(" %d %d", &a, &b);
        append(verts[a], b);
        vertPathCounts[a][1]++;
        append(verts[b], a);
        vertPathCounts[b][1]++;
    }
    for(int i = 1; i <= n; i++) {
        printf("%d\n", vertPathCounts[i][1]);
        printList(verts[i]);
    }

    qsort(vertPathCounts[1], n, sizeof(int)*2, cmp);
    
    for(int i = 1; i <= n; i++) {
        printf("[%d, %d], ", vertPathCounts[i][0], vertPathCounts[i][1]);
    }

    // int currentIndex = 0;
    // int resistance[n+1];
    // for(int i = 0; i <= n; i++) {
    //     resistance[i] = 0;
    // }
    // while(1) {
        
    // }


    for(int i = 1; i <= n; i++) {
        destroyList(verts[i]);
    }
    return 0;
}
