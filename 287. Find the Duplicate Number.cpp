class Solution {//因为相同的数字就代表着相同的指向，等同于有环的链表
public:
    int findDuplicate(vector<int>& nums) {
        
        if(nums.size()<2)return -1;
        else
        {
            int fast=nums[nums[0]];//因为有保证肯定有相同的数字
            int slow=nums[0];
            while(fast!=slow)
            {
                fast=nums[nums[fast]];
                slow=nums[slow];
            }
            int entery=0;//这个地方很重要
            
            while(entery!=slow)
            {
                entery=nums[entery];
                slow=nums[slow];
            }
            return entery;
        }
         
        
    }
};
