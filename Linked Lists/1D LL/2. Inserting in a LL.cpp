//INSERTING NODES IN A LINKEDLIST AT 4 DIFFERENT PLACES
#include <bits/stdc++.h>
using namespace std;

//From here till line 40 THE CODE IS SAME AS LAST FILE- 
class Node{
    public:
    int data;
    Node* next;
    //Constructors
    Node(int data1 , Node* next1){
        data = data1;
        next = next1;
    }
    Node(int data1){
        data = data1;
        next = nullptr;
    }
};
Node* convertingArray2LL(vector<int>& arr){
    if(arr.empty()) return nullptr;
    Node* head = new Node(arr[0]);
    Node* current = head;
    for(int i=1 ; i<arr.size() ; i++){
        Node* newNode = new Node (arr[i]);
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

//CODES START NOW

//Inserting a NODE BEFORE Head
Node* insertHead (Node* head , int val){
    Node* temp = new Node (val , head);         //Creating new node with next allocation of current head
    return temp;
}

//Inserting a Tail of LL
Node* insertTail(Node* head , int val){
    //EDGE CASE -> Empty List
    if(head == NULL) return new Node (val);
    //First go to last element
    Node* temp = head;
    while(temp -> next != NULL){
        temp = temp -> next;
    }
    Node* newNode = new Node (val);
    temp -> next = newNode;
    return head;
}

//Inserting at Kth Position
Node* insertPosition (Node* head , int val , int k){
    /*EDGE CASE -> Empty array 
                -> Inserting at head position */
    if(head == NULL && k==1) return new Node(val);
    int count = 0;
    Node* temp = head;
    while(temp != NULL){
        count++;
        if(count == k-1){
            Node* newNode = new Node (val , temp->next);
            temp -> next = newNode;
            break;
        }
        temp = temp -> next;
    }
    return head;
}
//INSERT BEFORE VALUE
Node* insertBeforeValue (Node* head , int el , int val){
    //EDGE CASES-> null list + insert before head
    if(head == NULL) return NULL;
    else if(head -> data == val) return new Node (el , head);
    //Code for Rest
    Node* temp = head;
    while(temp -> next != NULL){
        if(temp -> next -> data == val){
            Node* newNode = new Node (el , temp -> next);
            temp -> next = newNode;
            break;
        }
        temp = temp -> next;
    }
    return head;
}
int main(){
    vector<int> arr = {12 , 8 , 5 , 7};
    Node* head = convertingArray2LL(arr);
    printLL(head);
    Node* newHead = insertHead(head,25);
    printLL(newHead);
    Node* newTail = insertTail(head,25);
    printLL(newTail);
    Node* newElat2 = insertPosition(head , 25 , 2);
    printLL(newElat2);
    Node* elBefore7 = insertBeforeValue(head , 25 , 7);
    printLL(elBefore7);
    return 0;
}