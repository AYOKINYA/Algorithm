#include <vector>
using namespace std:

class Solution { //bottom-up approach
public:
    int combinationSum4(vector<int>& nums, int target) {
        
        vector<unsigned int> dp(target + 1, 0);
        dp[0] = 1; // target == 0 only if nothing's summed up => # of case is 1.

        for (int i = 1; i <= target; ++i)
        {
            for (int j = 0; j < nums.size(); ++j)
            {
                if (nums[j] <= i) // i is target
                    dp[i] += dp[i - nums[j]];
            }
        }

        return dp[target];
    }
};