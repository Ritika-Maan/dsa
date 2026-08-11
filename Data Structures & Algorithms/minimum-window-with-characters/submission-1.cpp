class Solution {
public:
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
        int satisfied=0;
        unordered_map<char,int> cp;
        while(r<s.size()){
            if(mp.count(s[r])){
                cp[s[r]]++;
                if(cp[s[r]]==mp[s[r]]){
                    satisfied++;
                }
                while(satisfied==mp.size()){
                    ans=min(ans,((r-l)+1));
                    if(ans==((r-l)+1)){
                        ansl=l;
                        ansr=r;
                    }
                    if(cp.count(s[l])){
                        cp[s[l]]--;
                        if(!(cp[s[l]]>=mp[s[l]])){
                            satisfied--;
                        }
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
