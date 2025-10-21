#include<iostream>
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
    void heapify(int arr[] , int n , int i){
        int largest = i;
        int leftNode = 2*i , rightNode = 2*i + 1;
        if(leftNode <= n && arr[leftNode] > arr[largest]){
            largest = leftNode;
        }
        if(rightNode <= n && arr[rightNode] > arr[largest]){
            largest = rightNode;
        }
        if(largest != i){
            swap(arr[largest] , arr[i]);
            heapify(arr , n , largest);
        }
    }
    void heapsort(int arr[] , int n){
        for(int i=n/2 ; i>0 ; i--){
            heapify(arr , n , i);
        }
        for(int i=n ; i>=2 ; i--){
            swap(arr[1] , arr[i]);
            heapify(arr , i-1 , i);
        }
    }
};
int main(){
    heap h;
    int myarr[] = {-1 , 4 , 10 , 3 , 5 , 1}; 
    int n = 5;
    h.heapsort(myarr , n);
    cout << "Sorted Array- \n";
    for(int i=1 ; i<=n ; i++){
        cout << myarr[i] << " ";
    } 
    cout << endl;
}