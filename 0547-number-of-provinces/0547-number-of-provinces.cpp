class Solution {
private:
    void bfs(int node , vector<vector<int>>& adj , vector<int>& vis) {
        vis[node] = 1;
        queue<int> q;
        q.push(node);

        while(!q.empty()) {
            int i = q.front();
            q.pop();

            for(int j = 0 ; j < adj.size() ; j++) {
                if(adj[i][j] == 1 && !vis[j]) {
                    vis[j] = 1;
                    q.push(j);
                }
            }
        }
    }
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        vector<int> vis(n , 0);
        int count = 0;

        for(int i = 0 ; i < n ; i++) {
            if(!vis[i]) {
                count++;
                bfs(i , isConnected , vis);
            }
        }
        return count;
        
        
    }
};