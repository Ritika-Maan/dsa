class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int i=0;
        int globalmax=nums[i];
        int curr=0;
        while(i<nums.size()){
            curr= max(curr+nums[i],nums[i]);
            globalmax=max(globalmax,curr);
            i++;
        }
        return globalmax;
    }
};
