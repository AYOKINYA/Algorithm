class Solution {
public:
    int getSum(int a, int b) {

        while (b != 0)
        {
            int res = a ^ b;
            b = (unsigned int)(a & b) << 1;
            a = res;
        }
        return a;
    }
};
