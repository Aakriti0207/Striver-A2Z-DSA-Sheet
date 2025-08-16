//Reverse Linked List

Given the head of a singly linked list, reverse the list, and return the reversed list.

//BRUTE FORCE -> Using Stack DS
  //Stack reverse LL due to its LIFO princple

class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode* temp = head;
        stack<int> st;
        while(temp != NULL){
            st.push(temp -> val);
            temp = temp -> next;
        }
        temp = head;
        while(temp != NULL){
            temp -> val = st.top();
            st.pop();
            temp = temp -> next;
        }
        return head;
    }
}; TC -> O(2n) SC -> O(n)

  //OPTIMAL SOLUTION -> Don't use extra Space
    //Iterative
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode* temp = head;
        ListNode* prev = NULL;
        while(temp != NULL){
            ListNode* front = temp -> next;
            temp -> next = prev;
            prev = temp;
            temp = front;
        }
        return prev;
    }
}; TC -> O(n)


    //RECURSIVE

class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        if(head == NULL || head->next == NULL){    //BaseCase
            return head;
        }
        ListNode *newHead = reverseList(head -> next);
        ListNode *front = head -> next;
        front -> next = head;
        head -> next = NULL;
        return newHead;
    }
}; TC -> O(n) SC -> O(1)
