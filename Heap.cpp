#include<iostream>
using namespace std;

class Heap{
    public:
    int *arr;
    int index;
    int capacity;

    Heap(int capacity){
        this->capacity = capacity;
        this->arr = new int[capacity];
        index = 0;
    }

    void insertIntoHeap(int val){
        index++;
        arr[index] = val;
        int temp = index;
        while(temp>1){  
            int parentIndex = temp/2;
            if(arr[parentIndex] < arr[temp]){
                swap(arr[parentIndex],arr[temp]);
                temp = parentIndex;
            }
            else{
                break;
            }
        }
    }

    void print(){
        for(int i=1;i<=index;i++){
            cout << arr[i] << " ";
        }
    }

    int deleteElementFromHeap(){
    int answer = arr[1];
    arr[1] = arr[index];
    index--;
    int tempIndex = 1;
    int largestIndex = tempIndex;
    while(tempIndex < index){
        int leftIndex = 2*tempIndex;
        int rightIndex = 2*tempIndex + 1;

        if(leftIndex <= index && arr[largestIndex] < arr[leftIndex]){
            largestIndex = leftIndex;
        }
        if(rightIndex <= index && arr[largestIndex] < arr[rightIndex]){
            largestIndex = rightIndex;
        }
        if(largestIndex != tempIndex){
            swap(arr[tempIndex],arr[largestIndex]);
            tempIndex = largestIndex;
        }else{
            break;
        }
    }

}
};

void heapUsingRecursion(int arr[],int size, int index){
    int leftIndex = 2*index;
    int rightIndex = 2*index + 1;
    int largestIndex = index;
    if(leftIndex <= size && arr[largestIndex] < arr[leftIndex]){
        largestIndex = leftIndex;
    }
    if(rightIndex <= size && arr[largestIndex] < arr[rightIndex]){
        largestIndex = rightIndex;
    }
    if(largestIndex != index){
        swap(arr[index],arr[largestIndex]);
        index = largestIndex;
        heapUsingRecursion(arr,size,index);
    }
}

void buildHeap(int arr[],int size){
    for(int i = size/2;i>0;i--){
        heapUsingRecursion(arr,size,i); 
    }
}

int main(){
    int arr[10] = {-1,80,75,10,60,90,100,70,50};
    int size = 8;
    buildHeap(arr,size);
    for(int i = 1;i<=size;i++){
        cout << arr[i] << " ";
    }
    Heap h(10);
    h.insertIntoHeap(80); 
    h.insertIntoHeap(75); 
    h.insertIntoHeap(10); 
    h.insertIntoHeap(60); 
    h.insertIntoHeap(90); 
    h.insertIntoHeap(100); 
    h.insertIntoHeap(70); 
    h.insertIntoHeap(50);
    cout << "Heap Printing" << endl;
    h.print();
    // cout << endl;
    // h.deleteElementFromHeap();
    // h.print();
    cout <<"Heap creation" << endl;
}