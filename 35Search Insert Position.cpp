class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int insertor=0;
        int size=nums.size();
        if(size==0)return 0;
        
        for(int i=0;i<size;i++)
        {
            if(nums[i]<target)
                insertor++;
            else if(nums[i]==target)
                return i;
            else
                return insertor;
        }
        
        return insertor;//注意在数组的最后插入
    }
};
