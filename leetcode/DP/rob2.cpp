#include <vector>
using namespace std;

class Solution {
public:
    int rob(vector<int>& nums) {
        if (nums.size() == 1)
            return nums[0];
        
        vector<int> dp(nums.size() + 1, 0);
        int res;
        dp[0] = 0;
        dp[1] = nums[0];
        for (int i = 1; i < nums.size() - 1; ++i)
        {
            int val = nums[i];
            dp[i + 1] = max(dp[i], dp[i - 1] + val);
        }
        res = dp[nums.size() - 1];

        dp[0] = 0;
        dp[1] = 0;
        dp[2] = nums[1];

        for (int i = 2; i < nums.size(); ++i)
        {
            int val = nums[i];
            dp[i + 1] = max(dp[i], dp[i - 1] + val);
        }

        res = max(res, dp[nums.size()]);
        return res;
    }
};