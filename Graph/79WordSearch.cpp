// https://leetcode.com/problems/word-search/

class Solution {
public:
    bool dfs(vector<vector<char>>&board,string word,vector<vector<bool>>&vis,int r,int c,int idx){
        if(idx == word.length()){
            return true;
        }
        
        if(r<0 || r>=board.size() || c<0 || c>=board[0].size() || vis[r][c]==true ||
           word[idx]!=board[r][c]){
            return false;
        }
        
        vis[r][c]=true;
        
        bool ans = (dfs(board,word,vis,r-1,c,idx+1) ||
               dfs(board,word,vis,r,c+1,idx+1) ||
               dfs(board,word,vis,r+1,c,idx+1) ||
               dfs(board,word,vis,r,c-1,idx+1));
        
        vis[r][c]=false;
        
        return ans;
    }
    
    bool exist(vector<vector<char>>& board, string word) {
        int rows = board.size();
        int cols = board[0].size();
        
        vector<vector<bool>>vis(rows,vector<bool>(cols,false));
        
        for(int i=0;i<rows;i++){
            for(int j=0;j<cols;j++){
                if(dfs(board,word,vis,i,j,0)){
                    return true;
                }
            }
        }
        return false;
    }
};
