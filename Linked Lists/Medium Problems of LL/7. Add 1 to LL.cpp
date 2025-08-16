//Add 1 to a Linked List Number

You are given a linked list where each element in the list is a node and have an integer data. You need to add 1 to the number formed by concatinating all the list node numbers together and return the head of the modified linked list. 

Note: The head represents the first element of the given array.


// Approach 1 - Iterative - Reverse the LL and then add 1 to head 
class Solution {
  public:
    Node* reverseLL(Node* head){
        if(!head || !head->next) return head;
        Node* newHead = reverseLL(head -> next);
        Node* front = head -> next;
        front -> next = head;
        head -> next = NULL;
        return newHead;
    }
    
    Node* addOne(Node* head) {
        Node *newHead = reverseLL(head);
        Node *temp = newHead;
        int carry = 1;
        Node* prev = NULL;
        while(temp && carry){
            int sum = temp -> data + carry;
            temp -> data = sum % 10;
            carry = sum / 10;
            prev = temp;
            temp = temp -> next;
        }
        if(carry){
            reverseLL(newHead)
            Node* newNode = new Node (carry);
            newNode -> next = head;
            return newNode;
            
        }
        return reverseLL(newHead);
    }
}; TC -> O(3N)

  //RECURSIVE APPROACH-
  //If we want to solve the problem without reversing the entire list- we can ONLY do so by Recursion because it uses backtracking approach

class Solution {
  public:
    int recursionForCarry(Node* temp){
        if(temp == NULL){
            return 1;
        }
        int carry = recursionForCarry(temp -> next);
        int sum = temp -> data + carry;
        temp -> data = sum % 10;
        carry = sum/10;
        return carry;
    }
    Node* addOne(Node* head) {
        int carry = recursionForCarry(head);
        if(carry){
            Node* newHead = new Node (carry);
            newHead -> next = head;
            return newHead;
        }
        return head;
    }
}; TC -> O(N) , SC -> O(N)
