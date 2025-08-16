//Palindrome Linked List

Given the head of a singly linked list, return true if it is a palindrome or false otherwise.

//BRUTE FORCE APPROACH-
  //Use Stack DS and check the elements of linkedlist with elements of stack

class Solution {
public:
    bool isPalindrome(ListNode* head) {
        stack<int> st;
        ListNode *temp = head;
        while(temp != NULL){
            st.push(temp -> val);
            temp = temp -> next;
        }
        temp = head;
        while(temp != NULL){
            if(temp->val != st.top()) return false;
            st.pop();
            temp = temp -> next;
        }
        return true;
    }
};  TC -> O(2*N) SC -> O(N)

  //OPTIMAL APPROACH -
  //Find middle element and reverse the second half of the list 

class Solution {
public:
    ListNode *reverseLL(ListNode *head){
        if(!head || !head->next) return head;
        ListNode *newHead = reverseLL(head -> next);
        ListNode *front = head -> next;
        front -> next = head;
        head -> next = NULL;
        return newHead;
    }
    bool isPalindrome(ListNode* head) {
        //EDGE CASE
        if(!head || !head -> next) return true;
        //Find Middle Element
        ListNode *slow = head , *fast = head;
        while(fast -> next != NULL && fast -> next -> next != NULL){
            slow = slow -> next;
            fast = fast -> next -> next;
        }
        //Reverse
        ListNode *newHead = reverseLL(slow -> next);
        ListNode *first = head , *second = newHead;
        while(second != NULL){
            if(first -> val != second -> val){
                reverseLL(newHead);
                return false;
            }
            first = first -> next;
            second = second -> next;
        }
        reverseLL(newHead);
        return true;
    }
}; TC -> O(2N) SC -> O(1)
