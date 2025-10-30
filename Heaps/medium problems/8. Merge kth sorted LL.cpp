//Merge k Sorted Lists
You are given an array of k linked-lists lists, each linked-list is sorted in ascending order.
Merge all the linked-lists into one sorted linked-list and return it.

  //Brute Force Approach-
  1. Traverse all the lists and push elements into a vector
  2. Sort the vector 
  3. Create a new LL storing the data

//Code
class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        //Step 1
        vector<int> vals;
        for(auto list : lists){    //Traversing
            ListNode* temp = list;
            while(temp){
                vals.push_back(temp -> val);
                temp = temp -> next;
            }
        }
        //Step 2 - sort
        sort(vals.begin() , vals.end());
        //step 3 - create another list 
        ListNode* head = new ListNode(0);  //dummy node
        ListNode* tail = head;
        for(int x:vals){
            tail -> next = new ListNode(x);
            tail = tail -> next;
        }
        return head -> next;
    } 
}; TC -> O(2N+NlogN) SC -> O(N)

//Better Approach 
  Use merge function and merge 2 lists first then the third and soo on
//Code-
class Solution {
public:
    ListNode* merge2lists(ListNode* a , ListNode* b){
        if(!a) return b;
        if(!b) return a;
        if(a -> val < b -> val){
            a -> next = merge2lists(a->next , b);
            return a;
        }else{
            b -> next = merge2lists(a , b->next);
            return b;
        }
    }
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if(lists.empty()) return NULL;
        //We need to segregate 2 lists for which create a node
        ListNode* head = lists[0];
        for(int i=1 ; i<lists.size() ; i++){
            head = merge2lists(head,lists[i]);
        }
        return head;
    }
}; TC -> O(n1+n2) for each merge , O(kN) for N merges , SC -> O(1)

  //Optimal Approach
  Use a min-heap
  1. Create a min-heap and push head node of each list into heap
  2. while heap is not empty->
    -> Pop the smallest element and add it to the resultant vector
    -> Check for the next element if it exists push it into the heap
  3. Return head of the merged lists

//Code-
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
class compare{
public:
    bool operator()(ListNode* a , ListNode* b){
        return a->val > b->val;
    }
};
class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<ListNode* , vector<ListNode*> , compare>pq;
        for(int i=0 ; i<lists.size() ; i++){
            if(lists[i] != NULL){
                pq.push(lists[i]);
            }
        }
        ListNode* head = new ListNode(0);
        ListNode* tail = head;
        while(!pq.empty()){
            ListNode* temp = pq.top();
            pq.pop();
            tail -> next = temp;
            tail = tail -> next;
            if(temp -> next != NULL){
                pq.push(temp -> next);
            }
        }
        return head -> next;
    }
}; TC -> O(NlogK) SC -> O(k)
