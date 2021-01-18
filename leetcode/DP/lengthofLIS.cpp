// #include <vector>

class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        
        int res = 1;
        int len = nums.size();
        vector<int> dp(len, 1);
        
        for (int i = 1; i < len; ++i)
        {
            for (int j = 0; j < i; ++j)
            {
                if (nums[j] < nums[i])
                    dp[i] = max(dp[i], dp[j] + 1);
            }
            res = max(res, dp[i]); 
        }
        return res;
    }
};