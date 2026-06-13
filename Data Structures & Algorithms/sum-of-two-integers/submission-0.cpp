class Solution {
public:
    int getSum(int a, int b) {
        while(b!= 0){
            int t1 = a ^ b;
            int t2 = (uint32_t)(a & b) << 1;

            a = t1;
            b = t2;
        }
        return a;
    }
};
