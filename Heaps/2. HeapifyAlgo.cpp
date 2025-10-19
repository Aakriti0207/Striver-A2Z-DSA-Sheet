#include<bits/stdc++.h>
using namespace std;

class heap{
    int arr[100];
    int size;
public:
    heap(){
        arr[0] = -1;
        size = 0;
    }
    void swap(int &x , int &y){
        int temp = x;
        x = y;
        y = temp;
    }
    void Heapify(int arr[] , int n , int i){
        int largest = i;
        int leftNode = 2*i;
        int rightNode = 2*i + 1;
        if(leftNode <= n && arr[largest] < arr[leftNode]){
            largest = leftNode;
        }
        if(rightNode <= n && arr[largest] < arr[rightNode]){
            largest = rightNode;
        }
        if(largest != i){
            swap(arr[i] , arr[largest]);
            Heapify(arr , n , largest);
        }
    }
};
int main(){
    int arr[6] = {-1 , 54 , 53 , 55 , 52 , 50};
    int n = 5;
    heap p;
    for(int i=n/2 ; i>0 ; i--){
        p.Heapify(arr , n , i);
    }
    cout << "After Heapification- \n";
    for(int i=1 ; i<n ; i++){
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}