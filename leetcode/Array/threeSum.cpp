// #include <vector>
// using namespace std;

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int len = nums.size();
        vector<vector<int>> res;
        
        sort(nums.begin(), nums.end());
        
        if (len < 3)
            return res;
        
        for (int i = 0; i < len ; ++i)
        {
            int j = i + 1;
            int k = len - 1;
            if (i != 0 && nums[i] == nums[i - 1])
                continue;
            while (j < k)
            {
                int three_sum = nums[i] + nums[j] + nums[k];
                
                if (three_sum == 0)
                {
                    vector<int> tmp;
                    tmp.push_back(nums[i]);
                    tmp.push_back(nums[j]);
                    tmp.push_back(nums[k]);
                    
                    res.push_back(tmp);
                    
                    j++;
                    k--;
                    
                    while(j < k && nums[j] == nums[j - 1])
                        j++;
                    while(j < k && nums[k] == nums[k + 1])
                        k--;
                    
                }
                else if (three_sum < 0)
                    j++;
                else
                    k--;
            }
        }
        return res;
    }
                    
};