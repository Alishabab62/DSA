#include<iostream>
using namespace std;

void mergeArray(int arr[],int start,int end){
    int mid = (start+end)/2;
    int lengthLeft = mid-start+1;
    int lengthRight = end-mid;
    int *leftArr = new int[lengthLeft];
    int *rightArr = new int[lengthRight];

    int k = start;
    for(int i = 0; i < lengthLeft; i++){
        leftArr[i] = arr[k];
        k++;
    }
    // k = mid+1;
    for(int i = 0; i < lengthRight; i++){
        rightArr[i] = arr[k];
        k++;
    }
    int i =0;
    int j = 0;
    int indexArr = start;
    while(i<lengthLeft && j<lengthRight){
        if(leftArr[i] < rightArr[j]){
            arr[indexArr] = leftArr[i];
            indexArr++;
            i++;
        }
        else{
            arr[indexArr] = rightArr[j];
            indexArr++;
            j++;
        }
    }

    while(i<lengthLeft){
        arr[indexArr] = leftArr[i];
        indexArr++;
        i++;
    }
    while(j<lengthRight){
        arr[indexArr] = rightArr[j];
        indexArr++;
        j++;
    }

}

void mergeSort(int arr[],int start,int end){
    if(start >= end){
        return;
    }
    int mid = (start+end)/2;
    mergeSort(arr,start,mid);
    mergeSort(arr,mid+1,end);
    mergeArray(arr,start,end);
}
 

int main(){
    int arr[10] = {5,2,3,1};
    int start = 0;
    int end = 3;
    mergeSort(arr,start,end);

    for(int i=start;i<=end;i++){
        cout << arr[i] << " ";
    }
}