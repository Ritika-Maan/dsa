class Solution {
    bool dfs(int i,vector<bool>& visited,vector<bool>&path,vector<vector<int>>&adj){
        visited[i]=true;
        path[i]=true;
        for(auto n:adj[i]){
            if(!visited[n]){
                if(!dfs(n,visited,path,adj)){
                    return false;
                }
            }else if(path[n]){
                return false;
            }
        }
        path[i]=false;
        return true;
    }
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(numCourses);
        for(auto const& r:prerequisites){
            adj[r[0]].push_back(r[1]);
        }
        vector<bool> visited(numCourses,false);
        vector<bool>path(numCourses,false);
        for(int i=0;i<numCourses;i++){
            if(!visited[i]){
                if(!dfs(i,visited,path,adj)){
                    return false;
                }
            }
        }
        return true;
    }
};
