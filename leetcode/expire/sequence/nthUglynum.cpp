class Solution {
public:
    struct cmp{
        bool operator()(double a,double b){
            return a>b;
        }
    };
    double nthUglyNumber(int n) {
        std::priority_queue<double,std::vector<double>,cmp> heap;
        std::unordered_set<double> exsit;
        int factors[3] = {2,3,5};
        double res = 1;
        for(int e:factors){
            heap.push(e * res);
        }
        exsit.insert(1);
        for(int i = 2;i <= n; ++i)
        {
            res = heap.top();
            heap.pop();
            for(int e: factors){
                if(exsit.count(e * res) == 0)
                {
                    heap.push(e * res);
                    exsit.insert(e * res);
                }
            }
        }
        return res;
    }
};
class Solution {
public:
    int nthUglyNumber(int n) {
        int i2 = 0,i3 = 0,i5 = 0;
        std::vector<int> nums(n);
        nums[0] = 1;
        for(int i = 1;i<n;++i){
            int next = min(
                nums[i2] * 2,min( nums[i3] * 3,nums[i5] * 5)
            );
            if(next == nums[i2]*2){
                ++i2;
            }
            if(next == nums[i3]*3){
                ++i3;
            }
            if(next == nums[i5]*5){
                ++i5;
            }
            nums[i] = next;
        }
        return nums.back();
    }
};
