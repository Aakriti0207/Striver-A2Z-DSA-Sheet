//25. Reverse Nodes in k-Group

/*
  Approach -
    1. Find kth node
    2. Break connections from both sides
    3. Reverse current Group
    4. Move ahead
We know how to reverse LL using prev,curr,next
We just need to do it in groups now
*/


class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        if(head == NULL || k == 1) return head;
        ListNode* dummyHead = head;
        ListNode* prevTail = NULL;
        while(dummyHead){
            ListNode* dummyTail = dummyHead;
            int count = 1;
            while(dummyTail && count < k){ //Finding kth node
                dummyTail = dummyTail -> next;
                count++;
            }
            if(dummyTail == NULL){ //less than k nodes left
                prevTail -> next = dummyHead;
                break;
            }
            ListNode* next = dummyTail -> next; //saving next element
            dummyTail -> next = NULL; //breaking relations with other elements
            ListNode* curr = dummyHead; //initialising head again
            ListNode* prev = NULL; //prev of current head - breaking relations again
            while(curr){ //reversal code
                ListNode* front = curr -> next;
                curr -> next = prev;
                prev = curr;
                curr = front;
            }
            if(dummyHead == head) head = prev; 
            else prevTail -> next = prev;
            prevTail = dummyHead;
            dummyHead = next;
        }
        return head;
    }
};
