//Delete the Middle Node of a Linked List
You are given the head of a linked list. Delete the middle node, and return the head of the modified linked list.

The middle node of a linked list of size n is the ⌊n / 2⌋th node from the start using 0-based indexing, where ⌊x⌋ denotes the largest integer less than or equal to x.

For n = 1, 2, 3, 4, and 5, the middle nodes are 0, 1, 1, 2, and 2, respectively.

//Brute Force-
  //Use formula- travers through the list and find n/2th element- delete the next element

class Solution {
public:
    ListNode* deleteMiddle(ListNode* head) {
        if(!head || !head->next) return NULL;
        ListNode *temp = head;
        int count = 0;
        while(temp){
            count++;
            temp = temp -> next;
        }
        int mid = count/2;
        temp = head;
        while(temp){
            mid--;
            if(mid == 0){
                ListNode*del = temp -> next;
                temp -> next = temp -> next -> next;
                delete del;
                break;
            }
            temp = temp -> next;
        }
        return head;
    }
}; TC -> O(N + N/2)

//Optimal Approach - Use Turtoise and Hare Algorithm
class Solution {
public:
    ListNode* deleteMiddle(ListNode* head) {
        if(head == NULL || head -> next == NULL) return NULL;
        ListNode *slow = head , *fast = head;
        fast = fast -> next -> next;
        while(fast != NULL && fast -> next != NULL){
            slow = slow -> next;
            fast = fast -> next -> next;
        }
        ListNode* del = slow->next;
        slow -> next = slow -> next -> next;
        delete del;
        return head;
    }
}; TC -> O(N/2)
