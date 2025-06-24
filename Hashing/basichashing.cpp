#include<bits/stdc++.h>
using namespace std;
int main(){
    int sizeofarray;
    cin>>sizeofarray;
    int arr[sizeofarray];
    for(int i=0 ; i<sizeofarray ; i++){
        cin>>arr[i];
    }
    //PreCompute
    int hash[20]={0};
    for(int i=0 ; i<sizeofarray ; i++){
        hash[arr[i]] += 1;
    }
    int queries;
    cin>>queries;
    while(queries--){
        int number;
        cin>>number;
        cout << hash[number] << endl;
    }
    return 0;

}