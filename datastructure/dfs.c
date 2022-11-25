#pragma warning(disable:4996)
#include<stdio.h>
#include<stdlib.h>

typedef struct edge {
    int v1;
    int v2;
    char label;
}edge;

typedef struct incidence {
    int edge;
    struct incidence* next;
}inc;

typedef struct vertex {
    inc* inc;
    int v;
    int isVisited;
}vertex;

vertex* vert;
edge* edges;
int n, m;
int queue[1000];

void insertEdge(int a, int b);
void buildIncList(int a, int b, int index);
void Dfs(int v);
void Bfs(int v);
void Bfs2(int v);
void init();

int main(void) {

    int a, b;

    int s, v = 0;

    scanf("%d %d %d", &n, &m, &s);

    vert = (vertex*)malloc(n * sizeof(vertex));
    edges = (edge*)malloc(m * sizeof(edge));

    init();

    for (int i = 0; i < m; i++) {
        scanf("%d %d", &a, &b);
        insertEdge(a, b);
    }

    for (int i = 0; i < n; i++) {
        if (vert[i].v == s) {
            v = i;
            break;
        }
    }

    Dfs(v);

    return 0;

}

void init(){

    for (int i = 0; i < n; i++) {
        vert[i].v = i + 1;
        inc* newInc = (inc*)malloc(sizeof(inc));
        vert[i].inc = newInc;
        vert[i].inc->edge = -1;
        vert[i].inc->next = NULL;
        vert[i].isVisited = 0;
    }

    for (int i = 0; i < m; i++) {
        edges[i].v1 = -1;
        edges[i].v2 = -1;
        edges[i].label = 'f';
    }
}

void Dfs(int v) {

    int w = 0;
    vert[v].isVisited = 1;
    printf("%d\n", vert[v].v);

    inc* p = vert[v].inc;

    while (p->next != NULL) {

        p = p->next;
        int p1 = edges[p->edge].v1;
        int q1 = edges[p->edge].v2;

        if (edges[p->edge].label == 'f') {

            w = (p1 == v) ? q1 : p1;

            if (vert[w].isVisited == 0) {
                edges[p->edge].label = 't';
                Dfs(w);
            }
            else {
                edges[p->edge].label = 'b';
            }
        }
    }
}

void insertEdge(int a, int b) {

    int i = 0;

    while (1) {
        if (edges[i].v2 == -1 || edges[i].v2 == -1) {
            edges[i].v1 = a - 1;
            edges[i].v2 = b - 1;
            buildIncList(a, b, i);
            return;
        }
        i++;
    }

}

void buildIncList(int a, int b, int index) {
    int i, j;
    int num = 0;
    inc* p = NULL, * q = NULL, * tmp = NULL;

    inc* newInc = (inc*)malloc(sizeof(inc));
    newInc->edge = index;

    p = vert[a - 1].inc;
    q = vert[b - 1].inc;

    i = a - 1;
    j = b - 1;

    while (p->next != NULL) {
        tmp = p;
        p = p->next;

        num = (edges[p->edge].v1 == i ? edges[p->edge].v2 : edges[p->edge].v1);

        if (num > j) {
            tmp->next = newInc;
            newInc->next = p;
            break;
        }
    }

    if (num <= j) {
        newInc->next = NULL;
        p->next = newInc;
    }

    if (i == j)
        return;

    inc* newInc2 = (inc*)malloc(sizeof(inc));
    newInc2->edge = index;
    num = 0;

    while (q->next != NULL) {

        tmp = q;
        q = q->next;

        num = (edges[q->edge].v1 == j ? edges[q->edge].v2 : edges[q->edge].v1);

        if (num > i) {
            tmp->next = newInc2;
            newInc2->next = q;
            break;
        }
    }

    if (num <= i) {
        newInc2->next = NULL;
        q->next = newInc2;
    }
}
