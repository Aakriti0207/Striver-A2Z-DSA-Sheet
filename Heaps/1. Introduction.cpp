//Operations
#include<bits/stdc++.h>
using namespace std;
class heap{
    int arr[100];
    int size = 0;
public:
    heap(){
        arr[0] = -1;
        size = 0;
    }
    void swap(int &x , int &y){
        int temp = x;
        x=y;  
        y=temp;
    }
    //Insertion
    void insert(int val){
        size++;
        int index = size;
        arr[index] = val;
        while(index > 1){  //Root is at index 1
            int parent = index/2;
            if(arr[parent] < arr[index]){
                swap(arr[parent] ,arr[index]);
                index = parent;
            }else{
                return;
            }
        }
    }
    //Deletion
    void Delete(){
        arr[1] = arr[size];         //Assigning first value to last element
        size--;
        for(int i=1 ; i<size ; i++){
            int leftnode = 2*i;
            int rightnode = 2*i + 1;
            if(arr[leftnode] > arr[i]){
                swap(arr[leftnode] , arr[i]);
                i = leftnode;
            }else if(arr[rightnode] > arr[i]){
                swap(arr[rightnode] , arr[i]);
                i = rightnode;
            }
        }
    }
    void print(){
        for(int i=1 ; i<=size ; i++){
            cout << arr[i] << " ";
        }
        cout << endl;
    }
};

int main(){
    heap h;
    h.insert(50);
    h.insert(55);
    h.insert(53);
    h.insert(52);
    h.insert(54);
    h.print();
    h.Delete();
    h.print();
    return 0;
}
