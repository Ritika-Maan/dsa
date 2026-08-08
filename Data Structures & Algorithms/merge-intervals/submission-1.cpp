class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals){
        vector<vector<int>> ans;
        sort(intervals.begin(), intervals.end());
        if(intervals.size()==0)return ans;
        if(intervals.size()==1){
            ans.push_back(intervals[0]);
            return ans;
        }
        auto curr=intervals[0];
        for(int i=1;i<intervals.size();i++){
            auto next=intervals[i];
            if(next[0]<=curr[1]){
                curr[1]=max(next[1],curr[1]);
            }else{
                ans.push_back(curr);
                curr=next;
            }
            
        }
        ans.push_back(curr);
        return ans;
    }
};
