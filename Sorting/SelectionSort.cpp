#include<bits/stdc++.h>
using namespace std;

void SelectionSort(int arr[] , int n){
    //Select minimum and swap with first element
    for(int i=0 ; i<n ; i++){
        int min=i;
        for(int j=i ; j<n ; j++){
            if(arr[j] < arr[min]) min=arr[j];
        }
        int temp=arr[min];
        arr[min]=arr[i];
        arr[i]=temp;
    }
}
//Time Complexity-> O(n^2)
void BubbleSort(int arr[] , int n){
    //Pushes Max at last by ADJACENT SWAPS
    for(int i=n-1 ; i>0 ; i--){
        for(int j=0 ; j<i ; j++){
            if(arr[j] > arr[j+1]){
                int temp=arr[j+1];
                arr[j+1]=arr[j];
                arr[j]=temp;
            }
        }
    }
}
//Time Complexity -> O(n^2)
void InsertionSort(int arr[] , int n){
    //Takes an element and INSERTS it in its correct position
    for(int i=0 ; i<n ; i++){
        int key = i;
        while(key>0 && arr[key] < arr[key-1]){
            int temp=arr[key+1];
            arr[key+1] = arr[key];
            arr[key] = temp;
            key--;
        }
    }
}
//Time Complexity -> O(n^2)
//MERGE SORT-> Requires 2 functions - Merge Function and Sorting Function
void MergeFunction(int arr[] , int low , int mid , int high){
    vector<int>temp;
    int left=low;
    int right=mid+1;
    while(left <= mid && right <=high){
        if(arr[left] <= arr[right]){
            temp.push_back(arr[left]);
            left++;
        }else{
            temp.push_back(arr[right]);
            right++;
        }
    }
    //Copying Leftover Elements
    while(left <= mid){
        temp.push_back(arr[left]);
        left++;
    }
    while(right <= high){
        temp.push_back(arr[right]);
        right++;
    }
    //INSERTING from temp array to original array
    for(int i=low ; i<=high ; i++){
        arr[i] = temp[i-low];
    }
}
void MergeSort(int arr[] , int low , int high){
    if(low>=high) return; //Base Case
    int mid=(low+high)/2;
    MergeSort(arr , low , mid);
    MergeSort(arr , mid+1 , high);
    MergeFunction(arr , low , mid , high);
}
//Time Complexity- O(n X lognbase2) Space Complexity- O(n)
//QUICKSORT- 
//Pick a pivot and place it in its correct place in sorted array
//Smaller on left larger on right-> contains 2 functions- partition and sort
int partition(int arr[] , int low , int high){
    int pivot=arr[low];
    int i=arr[low];
    int j=arr[high];
    while(i<j){
        while(arr[i]<pivot && i<=high-1){
            i++;
        }
        while(arr[j] > pivot && j>=low+1){
            j--;
        }
        if(i<j) swap(arr[i],arr[j]);
        return j;
    }
}
void QuickSort(int arr[],int low,int high){
    if(low<high){
        int pIndex=partition(arr , low , high);
        QuickSort(arr , low , pIndex-1);
        QuickSort(arr , pIndex+1 , high);
    }
}
//Time Complexity- O(NXlogNbase2) Space Complexity- O(n)