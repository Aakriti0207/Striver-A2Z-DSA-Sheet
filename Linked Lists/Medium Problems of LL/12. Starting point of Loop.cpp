//Linked List Cycle II
Given the head of a linked list, return the node where the cycle begins. If there is no cycle, return null.

There is a cycle in a linked list if there is some node in the list that can be reached again by continuously following the next pointer. Internally, pos is used to denote the index of the node that tail's next pointer is connected to (0-indexed). It is -1 if there is no cycle. Note that pos is not passed as a parameter.

Do not modify the linked list.

//Brute Force Approach 
  //Find first repeating element from hashing and return
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        unordered_map<ListNode* , int>mpp;
        ListNode* temp = head;
        while(temp != NULL){
            if(mpp.count(temp) != 0) return temp;
            mpp[temp]++;
            temp = temp -> next;
        }
        return NULL;
    }
};
//OPTIMAL APPROACH - turtoise and hare algorithm
  //Once slow and fast pointers are met- reset slow to head and move both of them 1 step when they meet again its the start of loop
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        if(!head || !head -> next) return NULL;
        ListNode *slow = head , *fast = head;
        while(fast != NULL && fast -> next != NULL){
            slow = slow -> next;
            fast = fast -> next -> next;
            if(slow == fast){
                slow = head;
                while(slow != fast){
                    slow = slow -> next;
                    fast = fast -> next;
                }
                return slow;
            }
            
        }
        return NULL;
    }
};

