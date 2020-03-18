#include <iostream>
using namespace std;

struct Node {
    int data;
    Node * next;
};

struct List {
    Node *head;
    Node *cur;
    Node *before;
    int numOfdata;
    int (*comp)(int d1, int d2);
};


void listInit(List *plist) {
    plist->head = (Node*)malloc(sizeof(Node));
    plist->head->next = NULL;
    plist->comp = NULL;
    plist->numOfdata = 0;
}

void Finsert(List *plist, int data) {
    Node *newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;

    newNode->next = plist->head->next;
    plist->head->next = newNode;

    (plist->numOfdata)++;
}

void Sinsert(List *plist, int data) {
    Node *newNode = (Node*)malloc(sizeof(Node));
    Node *pred = plist->head;
    newNode->data = data;

    while(pred->next != NULL && plist->comp(data, pred->next->data) == 0) {
        pred = pred->next;
    }

    newNode->next = pred->next;
    pred->next = newNode;

    (plist->numOfdata)++;
    
}


bool getFirst(List *plist, int *data) {
    if(plist->head->next == NULL) return false;

    plist->before = plist->head;
    plist->cur = plist->head->next;

    *data = plist->cur->data;
    return true;
}

bool getNext(List *plist, int *data) {
    if(plist->cur->next == NULL) return false;

    plist->before = plist->cur;
    plist->cur = plist->cur->next;

    *data = plist->cur->data;
    return true;
}

void Linsert(List *plist, int data) {
    if(plist->comp == NULL) {
        Finsert(plist, data);
    } else {
        Sinsert(plist, data);
    }

}

int LRmove(List *plist) {
    Node *rpos = plist->cur;
    int data = rpos->data;

    plist->before->next = plist->cur->next;
    plist->cur = plist->before;

    free(rpos);
    (plist->numOfdata)--;

    return data;
}

void setSortRule(List *plist, int (*comp)(int d1, int d2)) {
    plist->comp = comp;
}

int comp(int d1, int d2) {
    return d1 < d2;
}

int main() {

    List list;
    int data;
    listInit(&list);

    setSortRule(&list, comp);


    Linsert(&list, 10);
    Linsert(&list, 12);
    Linsert(&list, 30);
    Linsert(&list, 20);
    Linsert(&list, 12);

    if(getFirst(&list, &data)) {
        cout << data << '\n';
        while(getNext(&list, &data)) {
            cout << data << '\n';
        }
    }


    if(getFirst(&list, &data)) {
        if(data == 12) LRmove(&list);

        while(getNext(&list, &data)) {
            if(data == 12) LRmove(&list);
        }
    }


    cout <<"after deletion\n";
    if(getFirst(&list, &data)) {
        cout << data << '\n';
        while(getNext(&list, &data)) {
            cout << data << '\n';
        }
    }
  

    return 0;
}