//The numbering is based on videos in linkedlist playlist-

//Add Two Numbers
//You are given two non-empty linked lists representing two non-negative integers. The digits are stored in reverse order, and each of their nodes contains a single digit. Add the two numbers and return the sum as a linked list.

//You may assume the two numbers do not contain any leading zero, except the number 0 itself.

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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* dummy = new ListNode (-1);
        ListNode* temp = dummy;
        int carry = 0;
        while(l1 != NULL || l2 != NULL){
            int sum = 0;
            if(l1 != NULL){   //Check if list 1 is empty
                sum += l1 -> val;
                l1 = l1 -> next;
            }
            if(l2 != NULL){ //Check if list 2 is empty
                sum += l2 -> val;
                l2 = l2 -> next;
            }
            sum += carry; 
            carry = sum/10;
            ListNode* newNode = new ListNode(sum%10); //Creation of new Node
            temp -> next = newNode; //Linking 
            temp = temp -> next;
        }
        if(carry){  //If both lists ended but there's still a carry over element
            ListNode* newNode = new ListNode(carry); //New Node
            temp -> next = newNode; //Linking
        }
        return dummy -> next;
    }
};// TC-> O(l1 * l2)  SC-> O(max(l1 , l2))

//We use dummy node because without it we will have to write multiple conditional statements for multiple edge cases