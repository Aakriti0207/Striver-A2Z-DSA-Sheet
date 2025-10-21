#include <iostream>
#include <vector>
#include <queue>
using namespace std;

void swap (int &x , int &y){
    int temp = x;
    x=y;
    y=temp;
}

void heapify(vector<int>& arr , int n , int i){
    int largest = i;
    int leftNode = 2*i + 1 , rightNode = 2*i+2;
    //maxheap
    if(leftNode < n && arr[leftNode] > arr[largest]){
        largest = leftNode;
    }
    if(rightNode < n && arr[rightNode] > arr[largest]){
        largest = rightNode;
    }
    if(largest != i){
        swap(arr[i] , arr[largest]);
        heapify(arr , n , largest);
    }
}

void convertMintoMax(vector<int>& arr , int n){
    for (int i=n/2 -1 ; i>=0 ; i--){
        heapify(arr , n , i);
    }
}
int main(){
    vector<int> arr = {1 , 3 , 5 , 7 , 9 , 10};
    int n = arr.size();
    convertMintoMax(arr , n);
    cout << "Max Heap for given array- \n";
    for(int i=0 ; i<n ; i++){
        cout << arr[i] << " ";
    }
    cout << endl;

    //Using priority Queue
    priority_queue<int , vector<int> , greater<int>> minHeap;
    minHeap.push(4);
    minHeap.push(10);
    minHeap.push(3);
    minHeap.push(5);
    minHeap.push(1);
    priority_queue<int> maxHeap;
    while(!minHeap.empty()){
        maxHeap.push(minHeap.top());
        minHeap.pop();
    }
    cout << "Max-Heap order: ";
    while(!maxHeap.empty()) {
        cout << maxHeap.top() << " ";
        maxHeap.pop();
    }
    cout << endl;
}
