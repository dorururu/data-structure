#include <iostream>
#define MAX 1000
using namespace std;

struct ArrayList {
    int arr[MAX];
    int currentPosition;
    int numOfData;

};

void listInit(ArrayList *list) {
    list->currentPosition = -1;
    list->numOfData = 0;
}

void listInsert(ArrayList *list, int num) {
    if(list->numOfData >= MAX) {
        cout << "List is full" << '\n';
        return;
    }

    list->arr[list->numOfData] = num;
    (list->numOfData)++;
}

bool getFirst(ArrayList *list, int *num) {
    if(list->numOfData == 0) {
        cout << "List is empty" << '\n';
        return false;
    }

    list->currentPosition = 0;
    *num = list->arr[0];
    return true;
}


bool getNext(ArrayList *list, int *num) {
    if(list->currentPosition >= list->numOfData -1) {
        return false;
    }

    list->currentPosition++;
    *num = list->arr[list->currentPosition];
    return true;
}

int remove(ArrayList *list) {
    int num = list->arr[list->currentPosition];
    for(int i=list->currentPosition; i<list->numOfData-1; i++) {
        list->arr[i] = list->arr[i+1];
    }

    list->numOfData--;
    list->currentPosition--;

    return num;
}

int main() {
    
    ArrayList list;
    listInit(&list);


    // insert 1 ~ 10
    for(int i=0; i<10; i++) listInsert(&list, i+1);
    
    int num;
    
    
    //remove 5
    if(getFirst(&list, &num)) {
        if(num == 5) remove(&list);

        while(getNext(&list, &num)) {
            if(num == 5) remove(&list);
        }
    }


    if(getFirst(&list, &num)) {
        cout << num << ' ';
        while(getNext(&list, &num)) {
            cout << num << ' ';
        }
    }

    

    return 0;
}