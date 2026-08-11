class Solution {
public:
    int maxArea(vector<int>& heights) {
        int i=0,j=heights.size()-1;
        int ans=INT_MIN;
        while(i<j){
            int diff=j-i;
            if(heights[i]>heights[j]){
                ans=max(ans,(diff*heights[j]));
                j--;
            }else{
                ans=max(ans,(diff*heights[i]));
                i++;
            }
        }
        return ans;
    }
};
