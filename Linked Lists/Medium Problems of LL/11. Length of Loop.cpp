//Find length of Loop

Given the head of a linked list, determine whether the list contains a loop. If a loop is present, return the number of nodes in the loop, otherwise return 0.

Note: 'c' is the position of the node which is the next pointer of the last node of the linkedlist. If c is 0, then there is no loop.

//BRUTE FORCE -
  //Once a priviously visited node is visited again- length can be obtained by subtracting timer values at 2 instances of visiting that particular node.
    // We store the value of node + its timer value in the hash map

  class Solution {
  public:
    int lengthOfLoop(Node *head) {
        unordered_map<Node* , int> mpp;
        Node* temp = head;
        int timer = 0;
        while(temp != NULL){
            if (mpp.find(temp) != mpp.end()){
                int length = timer - mpp[temp];
                return length;
            }
            mpp[temp] = timer;
            temp = temp -> next;
            timer++;
        }
        return 0;
    }
};

//OPTIMAL APPROACH- Turtoise and Hare Algorithm
  //Same initialise slow and fast pointers- once they meet each other stop the slow pointer and move fast pointer by single step until it reaches slow again.
class Solution {
  public:
  int Length(Node* slow , Node* fast){
      fast = fast -> next;
      int count = 1;
      while(slow != fast){
          fast = fast -> next;
          count++;
      }
      return count;
  }
    int lengthOfLoop(Node *head) {
        if(!head || head -> next == NULL) return 0;
        Node* slow = head , *fast = head;
        while(fast != NULL && fast -> next != NULL){
            slow = slow -> next;
            fast = fast -> next -> next;
            if(slow == fast){
                int length = Length(slow , fast);
                return length;
            }
        }
        return 0;
        
    }
};
