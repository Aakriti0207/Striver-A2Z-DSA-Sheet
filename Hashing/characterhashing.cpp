#include<bits/stdc++.h>
using namespace std;
int main(){
    string s;
    cout << "Enter the string: "<< endl;
    cin >> s;
    //PreCompute
    int hash[26]={0};
    for(int i=0; i< s.size(); i++){
        hash[s[i] -'a']++; // lowercase
        //Upparcase hash[s[i]-'A'] += 1
        //Both uppercase and lowercase- hash[256]={0} then hash[s[i]]++ 
    }
    cout << "Enter the number of queries: " << endl;
    int queries;
    cin >> queries;
    cout << "Enter queries: "<<endl;
    while(queries--){
        char character;
        cin >> character;
        cout << hash[character -'a'] << endl;
    }
    return 0;

}