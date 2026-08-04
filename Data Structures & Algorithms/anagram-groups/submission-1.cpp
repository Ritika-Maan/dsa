class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string,vector<string>>mp;
        for(auto i:strs){
            string s=i;
            sort(i.begin(),i.end());
            mp[i].push_back(s);
        }
        vector<vector<string>> ans;
        for(auto j:mp){
            ans.push_back(j.second);
        }
        return ans;
    }
};
