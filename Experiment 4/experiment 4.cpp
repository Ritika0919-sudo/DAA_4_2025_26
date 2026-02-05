#include<bits/stdc++.h>
using namespace std;

#define MAX 100
int heapsize = 0;
int heap[MAX];

void heapify_up(int i){
    while(i > 0 && heap[(i - 1) / 2] > heap[i]){
        swap(heap[i], heap[(i - 1) / 2]);
        i = (i - 1) / 2;
    }
}

void insert(int x){
    if(heapsize == MAX){
        cout << "heap overflow\n";
        return;
    }
    heap[heapsize++] = x;
    heapify_up(heapsize - 1);
}

void heapify_down(int i){
    int smallest = i;
    int l = 2 * i + 1;
    int r = 2 * i + 2;

    if(l < heapsize && heap[l] < heap[smallest])
        smallest = l;
    if(r < heapsize && heap[r] < heap[smallest])
        smallest = r;

    if(smallest != i){
        swap(heap[i], heap[smallest]);
        heapify_down(smallest);
    }
}

void delmin(){
    if(heapsize == 0){
        cout << "heap empty\n";
        return;
    }
    heap[0] = heap[--heapsize];
    heapify_down(0);
}

void delindx(int i){
    if(heapsize == 0){
        cout << "heap empty\n";
        return;
    }
    if(i < 0 || i >= heapsize){
        cout << "invalid idx\n";
        return;
    }

    heap[i] = heap[--heapsize];

    if(i > 0 && heap[i] < heap[(i - 1) / 2])
        heapify_up(i);
    else
        heapify_down(i);
}

void deleteElement(int val){
    int i;
    for(i = 0; i < heapsize; i++){
        if(heap[i] == val) break;
    }
    if(i == heapsize) return;

    heap[i] = heap[--heapsize];

    if(i > 0 && heap[i] < heap[(i - 1) / 2])
        heapify_up(i);
    else
        heapify_down(i);
}

int main(){
    insert(10);
    insert(17);
    insert(25);
    insert(50);
    insert(15);
    insert(3);
    insert(13);

    delmin();
    delmin();
    delindx(1);
    deleteElement(25);

    for(int i = 0; i < heapsize; i++)
        cout << heap[i] << " ";

    return 0;
}
