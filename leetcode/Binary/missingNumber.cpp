// #include <vector>

class Solution {
public:
    int missingNumber(vector<int>& nums) {
        
        int n = nums.size();
        int ret = n * (n + 1) / 2;
        
        for (int i = 0; i < n; ++i)
            ret = ret - nums[i];
        
        return ret;
    }
};