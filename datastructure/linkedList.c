#pragma warning(disable:4996)
#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
        struct Node* prev;
        struct Node* next;
        char key;
}node;

typedef struct list {
        struct Node* head;
        struct Node* tail;
}list;

void addNode(list* list, int r, char e);
void deleteNode(list* list, int r);
node* getNodeByPosition(list* list, int po);
int getSize(list* list);
void get(list* list, int r);
void print(list* list);
node* makeNode();

int main(){
    list* newList = (list *)malloc(sizeof(list));
    newList->head = makeNode();
    newList->tail = makeNode();
    newList->head->next = newList->tail;
    newList->tail->prev = newList->head;
    int n;
    int num;
    char chr;
    scanf("%d", &n);

    for(int i=0; i<n; i++){
        char commend;
        getchar();
        scanf("%c", &commend);

        switch (commend) {
            case 'A':
                scanf("%d ", &num);
                scanf("%c", &chr);
                addNode(newList, num, chr);
                break;
            case 'D':
                scanf("%d", &num);
                deleteNode(newList, num);
                break;
            case 'G':
                scanf("%d", &num);
                get(newList, num);
                break;
            case 'P':
                print(newList);
                break;
        }
    }
}

void addNode(list* list, int r, char e){

    if(getSize(list) < r - 1 || r < 1){
        printf("invalid position\n");
        return;
    }

    node* a = makeNode();
    a->key = e;

    node* beforeNode = getNodeByPosition(list, r-1);

    a->prev= beforeNode;
    a->next = beforeNode->next;
    beforeNode->next->prev = a;
    beforeNode->next = a;
}

void deleteNode(list* list, int r){
    if(r < 1 || r > getSize(list) || getSize(list) < 1){
        printf("invalid position\n");
        return;
    }

    node* beforeNode = getNodeByPosition(list, r);
    beforeNode->prev->next = beforeNode->next;
    beforeNode->next->prev = beforeNode->prev;
}

node* getNodeByPosition(list* list, int po){

    node* p = list->head;

    int i = 0;

    while(1){

        if(i == po){
            return p;
        }
        i++;
        p = p->next;
    }
}

int getSize(list* list){
    int i=0;
    node* p = list->head->next;

    while (p != list->tail){
        i++;
        p = p->next;
    }
    return i;
}

void get(list* list, int r){
    node *p = list->head->next;
    int i = 1;

    if (r < 1 || getSize(list) < r){
        printf("invalid position\n");
        return;
    }

    while(p != list->tail){
        if(i == r){
            printf("%c\n", p->key);
            return;
        }
        p = p->next;
        i++;
    }
}
void print(list* list){
    node* p = list->head->next;

    while(p != list->tail){
        printf("%c", p->key);
        p = p->next;
    }
    printf("\n");
}


node* makeNode(){
    node* newNode = (node*)malloc(sizeof(node));
    newNode->next = NULL;
    newNode->prev = NULL;
    return newNode;
}