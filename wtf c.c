#include <stdio.h>
#include <stdlib.h>

typedef struct list list;
typedef struct node node;

struct list {
    node ** data;
    int length;
    int size;
};

struct node {
    int person;
    list * shorter;
};

list * createList(int initialSize) {
    list * l = malloc(sizeof(list));
    l->data = malloc(sizeof(node*)*initialSize);
    l->length = 0;
    l->size = initialSize;
    return l;
}

node * createNode(int person) {
    node * n = malloc(sizeof(node));
    n->person = person;
    n->shorter = createList(8);
    return n;
}

void append(list * l, node * data) {
    if(l->length+1 == l->size) {
        l->size *= 2;
        l->data = realloc(l->data, sizeof(node*)*l->size);
    }
    l->data[l->length] = data;
    ++l->length;
}

void attachNodeBelow(node * n, node * attachment) {
    append(n->shorter, attachment);
}

void destroyNode(node * n) {
    free(n->shorter->data);
    free(n->shorter);
    free(n);
}

void fill(short * start, int len, int n) {
    for(int i = 0; i < len; i++) {
        start[i] = n;
    }
}

node * nodes[1000010];
short visited[1000010];

int asdljasdhlg(node * n, int dest) {
    if(n->person == dest) {
        return 1;
    } else {
        for(int i = 0; i < n->shorter->length; ++i) {
            if(visited[n->shorter->data[i]->person] == 0) {
                visited[n->shorter->data[i]->person] = 1;
                return asdljasdhlg(n->shorter->data[i], dest);
            }
        }
        return 0;
    }
}

int main() {
    fill(&visited[0], 1000010, 0);

    int n, m;
    scanf(" %d%d", &n, &m);
    for(int i = 1; i <= n; ++i) {
        nodes[i] = createNode(i);
    }

    int p, q;
    for(int i = 0; i < m; ++i) {
        scanf(" %d%d", &p, &q);
        attachNodeBelow(nodes[p], nodes[q]);
    }

    scanf(" %d%d", &p, &q);
    if(asdljasdhlg(nodes[p], q)) {
        printf("%s\n", "yes");
    } else if(asdljasdhlg(nodes[q], p)) {
        printf("%s\n", "no");
    } else {
        printf("%s\n", "unknown");
    }

    for(int i = 1; i <= n; ++i) {
        destroyNode(nodes[i]);
    }
    return 0;
}
