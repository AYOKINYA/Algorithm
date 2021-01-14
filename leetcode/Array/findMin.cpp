// #include <vector>

class Solution {
public:
    int findMin(vector<int>& nums) {
        int len = nums.size();
        int min = nums[0];
        for (int i = 1; i < len; ++i)
        {
            if (min > nums[i])
            {
                min = nums[i];
                return min;
            }
        }
        return min;
    }
};
