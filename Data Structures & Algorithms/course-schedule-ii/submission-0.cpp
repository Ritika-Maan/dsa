class Solution {
    void findOrder(vector<int>& ans,stack<int>& st){
        while(!st.empty()){
            int node=st.top();
            st.pop();
            ans.push_back(node);
        }
    }
    bool dfs(int node,vector<bool>& visited,vector<bool>& path,stack<int>& st,vector<vector<int>>& adj){
        visited[node]=true;
        path[node]=true;
        for(auto n:adj[node]){
            if(!visited[n]){
                if(!dfs(n,visited,path,st,adj)){
                    return false;
                }
            }
            else if(path[n]){
                return false;
            }
            
        }
        path[node]=false;
        st.push(node);
        return true;
    }
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(numCourses);
        for(auto const& e:prerequisites){
            adj[e[1]].push_back(e[0]);
        }
        vector<bool>visited(numCourses);
        vector<bool>path(numCourses);
        stack<int> st;
        vector<int> ans;
        for(int i=0;i<numCourses;i++){
            if(!visited[i]){
                if(!dfs(i,visited,path,st,adj)){
                    return ans;
                }
            }
        }
        findOrder(ans,st);
        return ans;
    }
};
