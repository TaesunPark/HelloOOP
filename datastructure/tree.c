#include <stdio.h>
#include <memory.h>
#include <stdlib.h>

typedef struct node {
    struct node* lChild;
    struct node* rChild;
    struct node* parent;
    int key;
}Node;

Node* root;
int isExternal(Node* node);
int isInternal(Node* node);
void insertItem(int k);
int findElement(int k);
Node* treeSearch(Node* node, int k);
void print(Node* node);
Node* sibling(Node* w);
Node* inOrderSucc(Node* w);
void removeElement(int k);
Node* reduceExternal(Node* z);
void freeTree(struct node *w);
void deleteNode(Node * node);

Node* createNode();

int main(){

    char c;
    int k;
    int isQ = 1;
    root = createNode();

    root->parent = NULL;
    root->lChild = NULL;
    root->rChild = NULL;

    while (isQ) {

        scanf("%c", &c);
        getchar();

        switch (c)
        {
            case 'i':
                scanf("%d", &k);
                getchar();
                insertItem(k);
                break;

            case 'd':
                scanf("%d", &k);
                getchar();
                removeElement(k);
                break;

            case 's':
                scanf("%d", &k);
                getchar();
                findElement(k);
                break;

            case 'p':
                print(root);
                printf("\n");
                break;

            case 'q':
                isQ = 0;
                break;

            default:
                break;
        }

    }

    freeTree(root);
}


void print(Node* node) {

    if (isExternal(node)) {
        return;
    }

    printf(" %d", node->key);
    print(node->lChild);
    print(node->rChild);
}


void insertItem(int k){

    Node * w = treeSearch(root, k);

    if(isInternal(w)){
        return;
    }

    Node* left = createNode();
    Node* right = createNode();

    w->key = k;
    w->lChild = left;
    w->rChild = right;
    left->parent = w;
    right->parent = w;
    left->lChild = NULL;
    left->rChild = NULL;
    right->lChild = NULL;
    right->rChild = NULL;
    return;
}

void removeElement(int k) {

    Node* p = treeSearch(root, k);

    if (isExternal(p)) {
        printf("X\n");
        return ;
    }

    int e = p->key;

    Node* z = p->lChild;

    if (!isExternal(z)) {
        z = p->rChild;
    }

    if (isExternal(z)) {
        reduceExternal(z);
    } else {
        Node* y = inOrderSucc(p);
        z = y->lChild;
        p->key = y->key;
        reduceExternal(z);
    }

    printf("%d\n",e);
}

int findElement(int k){

    Node * w = treeSearch(root, k);

    if(isExternal(w)){
        printf("X\n");
        return NULL;
    } else{
        printf("%d\n", w->key);
        return w->key;
    }
}

Node* sibling(Node* w) {

    if (w -> parent == NULL){
        return NULL;
    }

    if (w->parent->lChild == w) {
        return w->parent->rChild;
    }
    else {
        return w->parent->lChild;
    }
}

Node* inOrderSucc(Node* w){

    w = w->rChild;

    if (isExternal(w) == 1){
        return NULL;
    }

    while (isInternal(w->lChild)){
        w = w->lChild;
    }
    return w;
}

Node* reduceExternal(Node* z) {
    Node* w = z->parent;
    Node* zs = sibling(z);

    if (w->parent == NULL) {
        root = zs;
        return zs;
    }

    Node* g = w->parent;
    zs->parent = g;

    if (w == g->lChild)
        g->lChild = zs;
    else if (w == g->rChild)
        g->rChild = zs;

    deleteNode(w);
    deleteNode(z);

    return zs;

}

Node* treeSearch(Node* node, int k){

    if(isExternal(node)){
        return node;
    }

    if(k == node->key){
        return node;
    } else if(k < node->key){
        return treeSearch(node->lChild, k);
    } else{
        return treeSearch(node->rChild, k);
    }

}

int isExternal(Node* node) {

    if (node->lChild == NULL && node->rChild == NULL){
        return 1;
    }

    return 0;
}

int isInternal(Node* node) {

    if (node->lChild != NULL || node->rChild != NULL){
        return 1;
    }

    return 0;
}

void freeTree(struct node *w) {

    if (isExternal(w)) {
        return;
    }

    else {
        freeTree(w->lChild);
        freeTree(w->rChild);
        free(w);
    }
}

Node * createNode(){
    Node * node = (Node*)malloc(sizeof(Node));
    memset(node, 0, sizeof(Node *));
    return node;
}

void deleteNode(Node * node){
    free(node);
    memset(node, 0, sizeof(Node *));
    return;
}
