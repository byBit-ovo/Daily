class Solution {
public:
    int mySqrt(int x) {
        int left = 0, right = x;
        int res = 0;
        while(left <= right)
        {
            double mid = left+(right-left)/2;
            if(mid*mid < x){
                res = mid;
                left = mid + 1;
            }
            else if(mid*mid == x){
                return mid;
            }
            else
            {
                right = mid - 1;
            }
        }
        return res;
    }
};
