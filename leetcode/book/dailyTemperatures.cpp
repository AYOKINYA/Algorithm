#include <vector>
using namespace std;

class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& T) {
        vector<int> res(T.size(), 0);
        stack<int> idx_stack;
        
        for (int i = 0; i < T.size(); ++i)
        {
            while (idx_stack.size() > 0 && T[i] > T[idx_stack.top()])
            {
                int last = idx_stack.top();
                res[last] = i - last;
                idx_stack.pop();
            }
            idx_stack.push(i);
        }
        
        return res;
        
    }
};