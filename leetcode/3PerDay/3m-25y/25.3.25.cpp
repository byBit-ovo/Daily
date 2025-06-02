class Solution {
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     * 
     * @param numbers int整型vector 
     * @return bool布尔型
     */
    bool IsContinuous(vector<int>& numbers) {
        // write code here
        vector<int> arr(numbers);
        sort(arr.begin(),arr.end());
        int count = 0;
        auto iter = arr.begin();
        while(iter != arr.end()){
            if(*iter==0){
                iter = arr.erase(iter);
                ++count;
            }
            else{
                ++iter;
            }
        }

        for(int i=1;i<arr.size();++i){
            if(arr[i]==arr[i-1]) return false;
            if(arr[i]-1!=arr[i-1]){
                if(arr[i] - arr[i-1] -1 > count){
                    return false;
                }
                count-=arr[i]-arr[i-1]-1;
            }
        }
        return true;







    }
};
