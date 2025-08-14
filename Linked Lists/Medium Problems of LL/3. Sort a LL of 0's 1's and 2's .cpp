//Sort a linked list of 0s, 1s and 2s

Given the head of a linked list where nodes can contain values 0s, 1s, and 2s only. Your task is to rearrange the list so that all 0s appear at the beginning, followed by all 1s, and all 2s are placed at the end.


//BRUTE FORCE- uses count as another variable and then overwrites the linkedlist


/*  Node is defined as
  struct Node {
    int data;
    struct Node *next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};*/
class Solution {
  public:
    Node* segregate(Node* head) {
        if(!head || !head->next) return head;
        int count0 = 0 , count1 = 0 , count2 = 0;
        Node *temp = head;
        while(temp){
            if(temp -> data == 0) count0++;
            else if(temp->data == 1)count1++;
            else count2++;
            temp = temp -> next; //MISTAKE
        }
        temp = head;
        while(temp){
            while(count0){  //NEED TO USE WHILE - if we use "if" it'll check only once...
                temp -> data = 0;
                count0--;
                temp = temp -> next;
            }
            while(count1){
                temp -> data = 1;
                count1--;
                temp = temp -> next;
            }
            while(count2){
                temp -> data = 2;
                count2--;
                temp = temp -> next;
            }
            
        }
        return head;
    }
}; TC -> O(2n)


  //OPTIMAL APPROACH- 
  //We create seperate lists for zeros ones and twos and then merge them
  //We don't actually CREATE another list we create a list which refers to the original array

  class Solution {
  public:
    Node* segregate(Node* head) {
        if(!head || !head->next) return head;
        Node zeroDummy(-1) , oneDummy(-1) , twoDummy(-1); //When we use this approach we do NOT need to delete dummy nodes since we are using stack not heap
        Node *zero = &zeroDummy , *one = &oneDummy , *two = &twoDummy;
        Node *temp = head;
        while(temp){
            if(temp -> data == 0){
                zero -> next = temp;
                zero = zero -> next;
                temp = temp -> next;
            }else if(temp -> data == 1){
                one -> next = temp;
                one = one -> next;
                temp = temp -> next;
            }else{
                two -> next = temp;
                two = two -> next;
                temp = temp -> next;
            }
        }
        //LINKING
        zero -> next = (oneDummy.next) ? oneDummy.next : twoDummy.next; //DOT next NOT -> next due to Stack
        one -> next = twoDummy.next;
        two -> next = NULL;
        return zeroDummy.next;
    }
}; TC -> O(n)
