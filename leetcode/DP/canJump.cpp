#include <vector>
using namespace std;

class Solution {
public:
    bool canJump(vector<int>& nums) {
        int len = nums.size();

        vector<int> dp(len + 1, 0);
        dp[0] = 1;
        dp[1] = 1;
        for (int i = 1; i <= len; ++i)
        {
            if (dp[i])
            {
                int max_jump = nums[i - 1];
                for (int j = 1; j <= max_jump; ++j)
                {
                    if (i + j > len)
                        break ;
                    dp[i + j] = 1;
                }
            }
        }
        return dp[len];
    }
};