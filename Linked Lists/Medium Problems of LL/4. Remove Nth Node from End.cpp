//Remove Nth Node From End of List
Given the head of a linked list, remove the nth node from the end of the list and return its head.

//BRUTE FORCE APPROACH -> delete (n-L+1)th node from start..

  
  /**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if(!head) return NULL;
        int length = 0;
        ListNode *temp = head;
        while(temp != NULL){
            length++;
            temp = temp -> next;
        }
        temp = head;
        int node = length - n;
        if(length == n){  //EDGE CASE FOR HEAD
            ListNode* newHead = head -> next;
            delete head;
            return newHead;
        }
        while(temp){
            node--;
            if(node == 0) break;
            temp = temp -> next;
        }
        ListNode* delNode = temp->next;
        temp -> next = delNode -> next;
        delete delNode;
        return head;
    }
};TC -> O(n) + O(L-n) == O(2n) in worst case


//Thus we need a more optimised solution for this problem
//Here, we use the 2 pointer method 
//we initialise fastp and slowp pointers and traverse fastp to nth node first THEN we traverse both fastp and slowp together until fastp reaches the LAST node
//Thus, out slowp will automatically reach the L-Nth node

class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* fastp = head , *slowp = head;
        for(int i=0 ; i<n ; i++){
            fastp = fastp -> next;
        }
        if(fastp == NULL){ //EDGE CASE
            ListNode* newHead = head -> next;
            delete head;
            return newHead;
        }
        //Start iterating with slowp
        while(fastp -> next){
            fastp = fastp -> next;
            slowp = slowp -> next;
        }
        //delete the next element of slowp
        ListNode* delNode = slowp -> next;
        slowp -> next = delNode -> next; //LINKING
        delete delNode;
        return head;
    }
}; TC -> O(n)
