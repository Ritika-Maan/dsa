class Solution {
public:
    bool isAnagram(string s, string t) {
        unordered_map<int,int> mp;
        if(s.size()!=t.size()){
            return false;
        }
        for(int i=0;i<s.size();i++){
            mp[s[i]]+=1;
        }
        for(int i=0;i<t.size();i++){
            mp[t[i]]-=1;
        }
        for(auto i:mp){
            if(i.second>=1){
                return false;
            }
        }
        return true;
    }
};
