//621. Task Scheduler
You are given an array of CPU tasks, each labeled with a letter from A to Z, and a number n. Each CPU interval can be idle or allow the completion of one task. Tasks can be completed in any order, but there's a constraint: there has to be a gap of at least n intervals between two tasks with the same label.

Return the minimum number of CPU intervals required to complete all tasks.

//Approach-
  Step 1- Count Frequencies of alphabets
  Step 2- Push Frequencies into a max heap
  Step 3- Process Tasks in cycles of (n+1)
        -> We pick up to n+1 tasks from the heap.
        -> Decrease their count (since one instance got done).
        -> Store them temporarily in ans.
  Step 4- Any task that still has remaining instances (f > 0) goes back into the heap.
  Step 5- Update total time and return

//Code-

class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        //step 1- create a map for char & freq
        vector<int>mpp(26,0);
        for(char ch:tasks){
            mpp[ch-'A']++;
        }
        int time = 0;
        //Step 2- Create a priority queue- maxHeap only freq
        priority_queue<int>pq;
        for(int i=0 ; i<mpp.size() ; i++){
            if(mpp[i] > 0){
                pq.push(mpp[i]);
            }
        }
        //Step 3- Start completing tasks
        while(!pq.empty()){
            vector<int> ans;
            for(int i=0 ; i<n+1 ; i++){
                if(!pq.empty()){
                    int freq = pq.top();
                    pq.pop();
                    freq--;
                    ans.push_back(freq);
                }
            }
          //Step 4- Any task that still has remaining instances (f > 0) goes back into the heap.
            for(int &f:ans){
                if(f>0) {
                    pq.push(f);
                }
            }
          //Step 5- Update time
            if(pq.empty()){
                time += ans.size();
            }else{
                time += n+1;
            } 
        }
        return time;
    }
}; TC -> O(NlogK) SC -> O(k)
