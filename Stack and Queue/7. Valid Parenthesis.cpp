//Valid Parentheses
Given a string s containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.

An input string is valid if:

Open brackets must be closed by the same type of brackets.
Open brackets must be closed in the correct order.
Every close bracket has a corresponding open bracket of the same type.

//We know that for solving this problem we should be keeping track of both opening and closing brackets
  // If we come across a closing bracket- it's opening bracket should be present just before
    // We will need a data structure that will keep track of first in and last out element -> STACK
class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        for(auto it:s){
            if(it == '{' || it == '(' || it == '['){
                st.push(it);
            }else{
                if(st.size() == 0) return false;
                char ch = st.top();
                st.pop();
                if((ch == '{' && it == '}') || (ch == '(' && it == ')') || (ch == '[' && it == ']') ){
                    continue;
                }else return false;
            }
        }
        return st.empty();
    }
};
