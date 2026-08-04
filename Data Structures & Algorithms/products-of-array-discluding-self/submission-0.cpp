class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> prefix(nums.size(),1);
        vector<int> suffix(nums.size(),1);
        vector<int> ans(nums.size());
        int p=1,s=1;
        for(int i=0;i<nums.size();i++){
            prefix[i]=p;
            p*=nums[i];
        }
        for(int i=nums.size()-1;i>=0;i--){
            suffix[i]=s;
            s*=nums[i];
        }
        for(int i=0;i<nums.size();i++){
            ans[i]=prefix[i]*suffix[i];
        }
        return ans;
    }
};
