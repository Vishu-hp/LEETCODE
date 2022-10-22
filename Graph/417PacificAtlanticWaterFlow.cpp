// https://leetcode.com/problems/pacific-atlantic-water-flow/

class Solution {
public:
    void dfs(vector<vector<int>>&heights,vector<vector<bool>>&vis,int r,int c,int ph){
        if(r<0 || c<0 || r>=heights.size() || c>=heights[0].size() || vis[r][c]==true
          || heights[r][c]<ph){
            return;
        }
        
        vis[r][c] = true;
        
        dfs(heights,vis,r-1,c,heights[r][c]);
        dfs(heights,vis,r,c+1,heights[r][c]);
        dfs(heights,vis,r+1,c,heights[r][c]);
        dfs(heights,vis,r,c-1,heights[r][c]);
    }
    
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int rows = heights.size() , cols = heights[0].size();
        vector<vector<bool>>po(rows,vector<bool>(cols,false));
        vector<vector<bool>>ao(rows,vector<bool>(cols,false));
        
        for(int c=0;c<cols;c++){
            dfs(heights,po,0,c,-1);
        }
        
        for(int r=0;r<rows;r++){
            dfs(heights,po,r,0,-1);
        }
        
        for(int c=0;c<cols;c++){
            dfs(heights,ao,rows-1,c,-1);
        }
        
        for(int r=0;r<rows;r++){
            dfs(heights,ao,r,cols-1,-1);
        }
        
        vector<vector<int>>ans;
        
        for(int i=0;i<rows;i++){
            for(int j=0;j<cols;j++){
                if(po[i][j] && ao[i][j]){
                    vector<int>tmp;
                    tmp.push_back(i);
                    tmp.push_back(j);
                    ans.push_back(tmp);
                }
            }
        }
        return ans;
    }
};
