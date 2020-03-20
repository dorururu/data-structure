#include <iostream>
using namespace std;

struct Node {
    int data;
    Node * next;
};

struct List {
    Node *tail;
    Node *cur;
    Node *before;
    int numOfdata;
};


void listInit(List *plist) {
    plist->tail = NULL;
    plist->cur = NULL;
    plist->before = NULL;
    plist->numOfdata = 0;
}

void insertFront(List *plist, int data) {
    Node *newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    
    if(plist->tail == NULL) {
        plist->tail = newNode;
        newNode->next = newNode;
    } else {
        newNode->next = plist->tail->next;
        plist->tail->next = newNode;
    }

    (plist->numOfdata)++;

}

void insert(List *plist, int data) {
    Node *newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    
    if(plist->tail == NULL) {
        plist->tail = newNode;
        newNode->next = newNode;
    } else {
        newNode->next = plist->tail->next;
        plist->tail->next = newNode;
        plist->tail = newNode;
    }

    (plist->numOfdata)++;
}

bool getFirst(List *plist, int *data) {
    if(plist->tail == NULL) return false;

    plist->before = plist->tail;
    plist->cur = plist->tail->next;

    *data = plist->cur->data;
    return true;
}

bool getNext(List *plist, int *data) {
    if(plist->tail == NULL) return false;

    plist->before = plist->cur;
    plist->cur = plist->cur->next;

    *data = plist->cur->data;
    return true;
}

int remove(List *plist) {
    Node *rpos = plist->cur;
    int rdata = rpos->data;


    if(rpos == plist->tail) {
        if(plist->tail->next == plist->tail) {
            plist->tail = NULL;
        } else {
            plist->tail = plist->before;
        }
    }

    plist->before->next = plist->cur->next;
    plist->cur = plist->before;

    free(rpos);
    (plist->numOfdata)--;
    return rdata;
}

int count(List *plist) {
    return plist->numOfdata;
}

int main() {

    List list;
    int data;
    listInit(&list);


    insert(&list, 7);
    insert(&list, 8);
    insert(&list, 9);
    insertFront(&list, 3);
    insertFront(&list, 2);

    int nodeCnt = count(&list);
    if(getFirst(&list, &data)) {
        cout << data << ' ';
        for(int i=0; i<nodeCnt-1; i++) {
            if(getNext(&list, &data)) {
                cout << data << ' ';
            }
        }
    }

    cout << '\n';

    if(nodeCnt != 0) {
        getFirst(&list, &data);
        if(data < 5) remove(&list);

        for(int i=0; i<nodeCnt-1; i++) {
            getNext(&list, &data);
            if(data < 5) remove(&list);
        }
    }

    nodeCnt = count(&list);
    if(getFirst(&list, &data)) {
        cout << data << ' ';
        for(int i=0; i<nodeCnt-1; i++) {
            if(getNext(&list, &data)) {
                cout << data << ' ';
            }
        }
    }

    cout << '\n';

  

    return 0;
}