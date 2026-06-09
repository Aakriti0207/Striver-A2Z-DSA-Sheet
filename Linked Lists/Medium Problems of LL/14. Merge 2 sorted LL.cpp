//14. Merge 2 sorted LL.cpp

/*
You are given the heads of two sorted linked lists list1 and list2.
Merge the two lists into one sorted list. The list should be made by splicing together the nodes of the first two lists.
Return the head of the merged linked list.
*/

BRUTE FORCE - NEW ARRAY
  //Create a new array, add elements from list1 and list2, sort the array and then re-enter the elements in a new array

class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        vector<int> arr;
        ListNode* temp = list1;
        while(temp){
            arr.push_back(temp -> val);
            temp = temp -> next;
        }
        temp = list2;
        while(temp){
            arr.push_back(temp -> val);
            temp = temp -> next;
        }
        sort(arr.begin() , arr.end());
        int n = arr.size();
        ListNode* head = new ListNode(-1);
        temp = head;
        for(int i=0 ; i<n ; i++){
            temp -> next = new ListNode(arr[i]); // connect the lists
            temp = temp -> next;
        }
        return head->next;
    }
};

//TIME COMPLEXITY => O(N+M log(N+M)) 
//SPACE COMPLEXITY => O(N+M)

OPTIMAL APPROACH - 2 Pointers
// Since both lists already sorted, Always pick- smaller node move pointer 

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
    //OPTIMAL APPROACH
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode* dummy = new ListNode(-1);
        ListNode* temp = dummy;
        while(list1 && list2){
            if(list1 -> val <= list2 -> val){
                temp -> next = list1; //no new nodes here
                list1 = list1 -> next;
            }else{
                temp -> next = list2;
                list2 = list2 -> next;
            }
            temp = temp -> next;
        } 
        //Remaining-
        while(list1){
            temp -> next = list1 -> val;
            temp = temp -> next;
            list1 = list1 -> next;
        }
        while(list2){
            temp -> next = list2 -> val;
            temp = temp -> next;
            list2 = list2 -> next;
        }
        return dummy -> next;
    }
};

//TIME COMPLEXITY => O(N+M)
//SPACE COMPLEXITY => O(1)
