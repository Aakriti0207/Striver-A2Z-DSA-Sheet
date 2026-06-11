//160. Intersection of Two Linked Lists

Given the heads of two singly linked-lists headA and headB, return the node at which the two lists intersect. If the two linked lists have no intersection at all, return null.
The test cases are generated such that there are no cycles anywhere in the entire linked structure.
Note that the linked lists must retain their original structure after the function returns.

BRUTE FORCE APPROACH
  //For every node in listA, check all nodes in listB

class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        while(headA != NULL){
            ListNode *tempB = headB;
            while(tempB != NULL){
                if(tempB == headA) return headA;
                tempB = tempB -> next;
            }
            headA = headA -> next;
        }
        return NULL;
    }
};

//TIME COMPLEXITY => O(2n) - worst case

BETTER APPROACH - Hashing
  //Iterate through list1 and hash its node address
  //Iterate through list2 and search the hashed value in hash table

class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        unordered_set<ListNode*> st;
        while(headA){
            st.insert(headA);
            headA = headA -> next;
        }
        while(headB){
            if(st.find(headB) != st.end()) return headB;
            headB = headB -> next;
        }
        return NULL;
    }
};

//TIME COMPLEXITY => O(n+m) SPACE COMPLEXITY => O(n)


OPTIMAL APPROACH - Find shorter list

/*
  We reduce the search length by searching length of shorter list-
    - Find length of both the lists and compute the positive difference between them-
    - Move dummy pointer of larger list to difference and THEN move both pointers simultaneously
*/

class Solution {
    //Optimal Approach
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        int countA = 0 , countB = 0;
        ListNode* temp = headA;
        while(temp){
            countA++;
            temp = temp -> next;
        }
        temp = headB;
        while(temp){
            countB++;
            temp = temp -> next;
        }
        int difference = countA - countB;
        if(difference < 0){
            while(difference){
                headB = headB -> next;
                difference++;
            }
        }else{
            while(difference){
                headA = headA -> next;
                difference--;
            }
        }

        while(headA){
            if(headA == headB) return headA;
            headB = headB -> next;
            headA = headA -> next;
        }
        return headA;
    }
    
};

//TIME COMPLEXITY => O(n+m) + O(n+m) - worst case

MOST OPTIMAL - USING DUMMY NODES
/*
  Take 2 dummy nodes for each list - iterate through the list if any node reached null - point it to the head of opposite list
  continue iterating until they collide
*/

class Solution {
    //Most Optimal Approach
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode* point1 = headA;
        ListNode* point2 = headB;
        while(point1 != point2){
            point1 = (point1 == NULL)? headB : point1 -> next;
            point2 = (point2 == NULL)? headA : point2 -> next;
        }
        return point1;
    }
};

//TIME COMPLEXITY - O(n+m) 
  
