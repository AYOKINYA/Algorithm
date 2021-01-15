// #include <vector>

class Solution {
public:
    vector<int> countBits(int num) {
        vector<int> res;
        res.push_back(0);
        for (int i = 1; i <= num; ++i)
        {
            int count = 0;
            int val = i;
            while (val != 0)
            {
                if (val & 1)
                    ++count;
                val = val >> 1;
            }
            res.push_back(count);
        }
        return res;
    }
};