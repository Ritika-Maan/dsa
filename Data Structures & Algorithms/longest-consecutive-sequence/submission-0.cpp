class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> mp(nums.begin(),nums.end());
        int longest =0;
        for(int n:mp){
            if(mp.find(n-1)==mp.end()){
                int length=1;
                while(mp.find(n+length)!=mp.end()){
                    length++;
                }
                longest=max(longest,length);
            }
        }
        return longest;
        
    }
};
