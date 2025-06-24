#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cout << "Enter the size of array- " << endl;
    cin>>n;
    int arr[n];
    cout << "Enter elements of the array- " << endl;
    for(int i=0 ; i<n ; i++){
        cin >> arr[i];
    }
    //precompute
    map<int, int> mpp; //character mapping- mpp<char, int>
    for(int i=0 ; i<n ; i++){
        mpp[arr[i]]++;
    }
    //Iterate over map
    // for(auto it : mpp){
    //     cout << it.first << "->" << it.second << endl;
    // }

    int queries;
    cout << "Enter the number of queries: " << endl;
    cin >> queries;
    cout << "Enter queries: " << endl;
    while(queries--){
        int number;
        cin>>number;
        cout << mpp[number] << endl;
    }
    return 0;
    
}