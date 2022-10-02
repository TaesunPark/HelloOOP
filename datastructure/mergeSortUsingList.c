#include <stdio.h>
#include <stdlib.h>

// 연결 리스트 노드 구조체
typedef struct NODE{
    struct NODE* next;
    int data;
}Node;

int n;
Node* addNode(int k, Node* preNode);
void mergeSort(Node** node, int k);
void printNodes(Node* head);

int main(){
    int tmp;
    Node* head = (Node*) malloc(sizeof(Node));
    Node* tmpNode;
    scanf("%d", &n);

    for(int i=0; i<n; i++){
        scanf("%d", &tmp);

        //head
        if(i == 0){
            head->data = tmp;
            head->next = NULL;
            tmpNode = head;
            continue;
        }

        tmpNode = addNode(tmp, tmpNode);
    }
    printNodes(head);
    //mergeSort(&head, n);

    return 0;
}

Node* addNode(int k, Node* preNode){
    Node* newNode = (Node *) malloc(sizeof(Node));
    newNode->data = k;
    newNode->next = NULL;
    preNode->next = newNode;
    return newNode;
}

void printNodes(Node* head) {

    Node* tmp = head;

    while (tmp != NULL) {
        printf(" %d", tmp->data);
        tmp = tmp->next;
    }

}
