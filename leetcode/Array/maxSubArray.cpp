// #include <vector>
// using namespace std;

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int res = nums[0];
        int submax = nums[0];
        
        for (int i = 1; i < nums.size(); ++i)
        {
            submax = max(nums[i], submax + nums[i]);
            res = max(submax, res);
        }
        
        return res;
        
    }
};