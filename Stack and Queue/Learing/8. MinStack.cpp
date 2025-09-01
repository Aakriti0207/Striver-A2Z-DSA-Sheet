//Min Stack
Design a stack that supports push, pop, top, and retrieving the minimum element in constant time.

Implement the MinStack class:

MinStack() initializes the stack object.
void push(int val) pushes the element val onto the stack.
void pop() removes the element on the top of the stack.
int top() gets the top element of the stack.
int getMin() retrieves the minimum element in the stack.
You must implement a solution with O(1) time complexity for each function.

//Brute Force- to iterate through the entire stack and store minimum element - 
  // But stack is dynamic in nature due to which a lot of memory would be taken up + it won't be efficiant

// APPROACH 1- Implement the solution use pairs-
  // Push the new value as well as the minimum value till then together in the array- they'll be pushed together and will be popped together as well 
class MinStack {
public:
    MinStack() {
        
    }
    stack <pair<int,int>> st;
    int mini;
    
    void push(int val) {
        if(st.empty()){
            mini = val;
        }else{
            mini = min(st.top().second , val);
        }
        st.push({val , mini});
    }
    
    void pop() {
        st.pop();

    }
    
    int top() {
        return st.top().first;
    }
    
    int getMin() {
        return st.top().second;
    }
};



//APPROACH 2- Implement the solution using the formula - encoded value = 2*ogval - mini
  // This encoded value will be pushed in stack while original value will be the new mini (obviously only if the value < existing mini)
    // While popping- if the top element is > the mini element we will just pop but if the element is < mini we will need to replce mini as well using the same formula just this time-
        // prev MINI = 2*mini - top

class MinStack {
public:
    MinStack() {
        
    }
    stack<long long>st;
    long long mini = INT_MAX;
    void push(int val) {
        long long value = val;
        if(st.empty()){
            st.push(value);
            mini = value;
        }else if(value > mini){
            st.push(value);
        }else{
            long long newVal = 2*value - mini;
            st.push(newVal);
            mini = value;
        }
    }
    
    void pop() {
        if(st.empty()) return;
        long long el = st.top();
        st.pop();
        if(el < mini){
            mini = 2*mini - el;
        }

    }
    
    int top() {
        if(st.empty()) return -1;
        long long top = st.top();
        if(top > mini){
            return top;
        }else{
            return mini;
        }
    }
    
    int getMin() {
        return mini;
    }
};
