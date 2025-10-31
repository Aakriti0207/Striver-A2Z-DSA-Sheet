// Greedy Algorithms is where we become greedy and provide the solution to only satisfy the condition that is asked and save the other potential solution for future references
// 455. Assign Cookies
Assume you are an awesome parent and want to give your children some cookies. But, you should give each child at most one cookie.

Each child i has a greed factor g[i], which is the minimum size of a cookie that the child will be content with; and each cookie j has a size s[j]. If s[j] >= g[i], we can assign the cookie j to the child i, and the child i will be content. Your goal is to maximize the number of your content children and output the maximum number.

//Understanding the problem-
    -> We are provided 2 arrays 1 is students/children other is cookies
    -> children array consists of greedy measure and the cookies each child gets must be >= the greed measure
1. One approach would be to just use 2 loops and iterate both arrays 
But it would produce wrong ans because this way we can assign 4 cookies to greed factor 1 when there can be a lower cookie that can be assigned to 1 as well when child with greed index 4 would not be assigned any thing.
Thus we need to assign min possible cookie number with respect to the greed index => Greedy 

=> We can do this by sorting both the arrays- 
//Code
class Solution {
public:
    int findContentChildren(vector<int>& children, vector<int>& cookies) {
        int n = children.size() , m = cookies.size();
        sort(children.begin() , children.end());
        sort(cookies.begin() , cookies.end());
        int l = 0 , r = 0;
        int count = 0;
        while(l<n && r<m){
            if(cookies[r] >= children[l]){
                count++;
                l++;
            }
            r++;
        }
        return count;
    }
};
