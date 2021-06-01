class Solution {
    private:
        int ans = 0;
        int c = 0;
public:
    void dfs(vector<vector<int>>& grid,int i,int j,int mx,vector<vector<bool>>& vis){
        if(i<0 || i>=grid.size() || j<0 || j>=grid[i].size() || vis[i][j] == true || grid[i][j] == 0){
            return ;
        }
        if(grid[i][j] == 1){
            c++;        
       //     cout << c << " " << i << " " << j << endl;
            vis[i][j] = true;
        }
        dfs(grid,i+1,j,mx,vis);
        dfs(grid,i-1,j,mx,vis);
        dfs(grid,i,j+1,mx,vis);
        dfs(grid,i,j-1,mx,vis);
        return ;
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        vector<vector<bool>> vis(grid.size(),vector<bool>(grid[0].size(),false));
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[i].size();j++){
                if(grid[i][j] == 1 && vis[i][j] == false){  
                    c = 0;
                    dfs(grid,i,j,0,vis);
                    ans = max(c,ans);
                }
            }   
        }
        return ans;
    }
};
