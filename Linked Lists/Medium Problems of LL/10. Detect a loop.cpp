//Linked List Cycle
Given head, the head of a linked list, determine if the linked list has a cycle in it.

There is a cycle in a linked list if there is some node in the list that can be reached again by continuously following the next pointer. Internally, pos is used to denote the index of the node that tail's next pointer is connected to. Note that pos is not passed as a parameter.

Return true if there is a cycle in the linked list. Otherwise, return false.

//BRUTE FORCE APPROACH- USING HASH MAPS
  //We can store elements in hash map when we encounter a node already visited before we return yes.
class Solution {
public:
    bool hasCycle(ListNode *head) {
        if(!head || !head -> next ) return false;
        unordered_map<ListNode* , int> mpp;
        ListNode *temp = head;
        while(temp != NULL){
            if(mpp.find(temp) != mpp.end()) return true;
            mpp[temp]++;
            temp = temp -> next;
        }
        return false;
    }
};TC -> O(2*N*logN) SC -> O(N)

//Optimal Solution- Turtoise and Hare Algorithm
  // We initialise 2 pointers- slow and fast, slow pointer moves by 1 step fast pointer moves by 2 steps
class Solution {
public:
    bool hasCycle(ListNode *head) {
        if(!head || !head -> next) return false;
        ListNode *slow = head , *fast = head;
        while(fast != NULL && fast -> next != NULL){
            slow = slow -> next;
            fast = fast -> next -> next;
            if(slow == fast) return true;
        }
        return false;
    }
}; TC -> O(N) 
