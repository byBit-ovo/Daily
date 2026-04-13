
class StoreWithNoDup
{
private:
    std::vector<int> nums;
    std::unordered_map<int,int> valToPos;
public:
    void insert(int val){
        if(valToPos.count(val)){
            return;
        }
        nums.push_back(val);
        valToPos[val]=nums.size()-1;
    }
    void remove(int val){
        if(valToPos.count(val)==0){
            return;
        }
        int index = valToPos[val];
        nums[index]=nums.back();
        nums.pop_back();
        valToPos.erase(val);
        valToPos[nums[index]]=index;
    }
    int get_random(){
        return nums[rand()%nums.size()];
    }
};
