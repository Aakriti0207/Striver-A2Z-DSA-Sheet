#include <bits/stdc++.h>
using namespace std;

//Define Node 
class Node{
    public:
    int data; //Defining Data
    Node* next; //Pointer to next Node
    //Constructor
    public:
    Node(int data1 , Node* next1){
        data = data1;
        next = next1;
    }
    //Constructor2
    Node(int data1){
        data = data1;
        next = nullptr;
    }
};
//Representation of array in LL
Node* convertingArray2LL(vector<int>& arr){
    if(arr.empty()) return nullptr;
    Node* head = new Node (arr[0]);
    Node* current = head;
    for(int i=1 ; i<arr.size() ; i++){
        Node* newNode = new Node(arr[i]);
        current -> next = newNode;
        current = newNode;
    }
    return head;
}
void printLL(Node* head){
    Node* temp = head;
    while(temp != NULL){
        cout << temp->data << " ";
        temp = temp -> next;
    }
    cout << endl;
}
int main(){
    vector<int> arr = {12 , 8 , 5 , 7};
    Node* head = convertingArray2LL(arr);
    printLL(head);
    return 0;
}
