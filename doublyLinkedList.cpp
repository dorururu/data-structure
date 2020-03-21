#include <iostream>
using namespace std;

struct Node {
    int data;
    Node *next;
    Node *prev;
};

struct List {
    Node *head;
    Node *tail;
    Node *cur;
    int numOfdata;
};


void listInit(List *plist) {
    plist->head = (Node *)malloc(sizeof(Node));
    plist->tail = (Node *)malloc(sizeof(Node));

    plist->head->prev = NULL;
    plist->head->next = plist->tail;

    plist->tail->prev = plist->head;
    plist->tail->next = NULL;

    plist->numOfdata = 0;
}


void insert(List *plist, int data) {
    Node *newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    
    newNode->prev = plist->tail->prev;
    plist->tail->prev->next = newNode;

    newNode->next = plist->tail;
    plist->tail->prev = newNode;

    (plist->numOfdata)++;
}

bool getFirst(List *plist, int *data) {
    if(plist->head->next == plist->tail) return false;

    plist->cur = plist->head->next;    
    *data = plist->cur->data;

    return true;
}

bool getNext(List *plist, int *data) {
    if(plist->cur->next == plist->tail) return false;

    plist->cur = plist->cur->next;
    *data = plist->cur->data;
    return true;
}

int remove(List *plist) {
    Node *rpos = plist->cur;
    int rdata = rpos->data;

    plist->cur->prev->next = plist->cur->next;
    plist->cur->next->prev = plist->cur->prev;

    plist->cur = plist->cur->prev;
    

    free(rpos);
    (plist->numOfdata)--;
    return rdata;
}


int main() {

    List list;
    int data;
    listInit(&list);


    insert(&list, 2);
    insert(&list, 3);
    insert(&list, 5);
    insert(&list, 7);
    insert(&list, 8);

    if(getFirst(&list, &data)) {
        cout << data << ' ';
        while(getNext(&list, &data)) {
            cout << data << ' ';
        }
        cout << '\n';
    }

    if(getFirst(&list, &data)) {
        if(data%2 == 0)
            remove(&list);
        while(getNext(&list, &data)) {
            if(data%2 == 0)
                remove(&list);
        }
    }

    if(getFirst(&list, &data)) {
        cout << data << ' ';
        while(getNext(&list, &data)) {
            cout << data << ' ';
        }
        cout << '\n';
    }
  

    return 0;
}