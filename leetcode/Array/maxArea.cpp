// #include <vector>

class Solution {
public:
    int maxArea(vector<int>& height) {
        int i = 0;
        int j = height.size() - 1;
        int max_area = 0;
        while (i < j)
        {
            int h = min(height[i], height[j]);
            max_area = max(max_area, (j - i) * h);
            while (height[i] <= h && i < j)
                ++i;
            while (height[j] <= h && i < j)
                --j;
        }
       
        return (max_area);
    }
};