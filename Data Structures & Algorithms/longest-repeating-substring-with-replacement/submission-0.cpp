class Solution {
public:
    int characterReplacement(string s, int k) {
        int left=0;
        int freq[26]={0};
        int ans=INT_MIN;
        int maxfreq=0;
        for(int i=0;i<s.length();i++){
            freq[s[i]-'A']++;
            maxfreq=max(maxfreq,freq[s[i]-'A']);
            int windowlen=(i-left);
            if((windowlen-maxfreq)<k){
                ans=max(ans,windowlen+1);
            }else{
                freq[s[left]-'A']--;
                left++;
            }
        }
        return ans;
    }
};
