#include <vector>
using namespace std;

class Solution {
public:
    int rob(vector<int>& nums) {
        if (nums.size() == 0)
            return 0;
        
        vector<int> dp(nums.size() + 1, 0);
        dp[0] = 0;
        dp[1] = nums[0];
        for (int i = 1; i < nums.size(); ++i)
        {
            int val = nums[i];
            dp[i + 1] = max(dp[i], dp[i - 1] + val);
        }
        return dp[nums.size()];
    }
};