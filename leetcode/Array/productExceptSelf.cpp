// #include <vector>

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int len = nums.size();
        std::vector<int> res;
        res.push_back(1);
        for (int i = 1; i < len; ++i)
            res.push_back(nums[i - 1] * res[i - 1]);
        int R = 1;
        for (int i = len - 1; i >= 0; --i)
        {
            res[i] = res[i] * R;
            R *= nums[i];
        }
        return res;
    }
};