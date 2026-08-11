class Solution {
public:
    bool satisfied(unordered_map<char,int>& mp, unordered_map<char,int>& cp){
        int ans=0;
        for(auto i:mp){
            if(cp.count(i.first)){
                if(i.second<=cp[i.first]){
                    ans++;
                }
            }
        }
        if(ans==mp.size()){
            return true;
        }
        return false;
    }
    string minWindow(string s, string t) {
        if(s.length()<t.length()){return "";}
        unordered_map<char,int> mp;
        for(char i:t){
            mp[i]++;
        }
        int ans=INT_MAX;
        string str;
        int ansl,ansr;
        int l=0,r=0;
        unordered_map<char,int> cp;
        while(r<s.size()){
            if(mp.count(s[r])){
                cp[s[r]]++;
                while(satisfied(mp,cp)){
                    ans=min(ans,((r-l)+1));
                    if(ans==((r-l)+1)){
                        ansl=l;
                        ansr=r;
                    }
                    if(cp.count(s[l])){
                        cp[s[l]]--;
                    }
                    l++;
                    
                }
                r++;
            }else{
                r++;
            }
        }
        if(ans==INT_MAX){
            return str;
        }else{
            for(int j=ansl;j<=ansr;j++){
                str+=s[j];
            }
            return str;
        }
    }
};
