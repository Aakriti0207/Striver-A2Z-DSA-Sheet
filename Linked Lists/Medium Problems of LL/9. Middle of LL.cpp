//Middle of the Linked List
Given the head of a singly linked list, return the middle node of the linked list.

If there are two middle nodes, return the second middle node.

//Brute Force Approach- Using formula of middle element i.e. (n/2) + 1th node

class Solution {
public:
    ListNode* middleNode(ListNode* head) {
        ListNode* temp = head;
        int n = 0;
        while(temp != NULL){
            n++;
            temp = temp -> next;
        }
        temp = head;
        int middleElement = (n/2) + 1;
        while(temp != NULL){
            middleElement--;
            if(middleElement == 0){
                break;
            }
            temp = temp -> next;
        }
        return temp;
    }
}; TC -> O(N + N/2) ~ O(N)


//Optimal Approach - Using Turtoise and Hare Algorithm 
  //We intialise 2 pointers slow and fast at the head
    //With each iteration slow pointer move one step ahead and fast pointer moves 2 steps ahead till it reaches null(even) or node before null(odd)


class Solution {
public:
    ListNode* middleNode(ListNode* head) {
        ListNode *slow =head , *fast = head;
        while(fast != NULL && fast -> next != NULL){
            slow = slow -> next;
            fast = fast -> next -> next;
        }
        return slow;
    }
}; TC -> O(n/2) 
