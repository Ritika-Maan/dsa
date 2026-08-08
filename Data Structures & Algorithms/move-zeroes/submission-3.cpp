class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int i=0;
        int j=0;
        while(j<nums.size()){
            if(nums[j]!=0){
                if(i!=j){
                    nums[i]=nums[j];
                    nums[j]=0;
                }
                i++;
                j++;
            }else{
                j++;
            }
        }
    }
};