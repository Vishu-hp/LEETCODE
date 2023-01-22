class Solution {
public:
        vector<int>par;
        vector<int>rank;


       

        int find(int x){
            if(par[x]==-1){
                return x;
            }

            int gl = find(par[x]);
            par[x]=gl;
            return gl;
        }

        void union_(int x,int y){
            int l1 = find(x);
            int l2 = find(y);

            if(l1==l2) return;

            if(rank[l1]>rank[l2]){
                par[l2]=l1;
            }
            else if(rank[l2]>rank[l1]){
                par[l1]=l2;
            }
            else{
                par[l1]=l2;
                rank[l2]++;
            }
        }


    int countServers(vector<vector<int>>& grid) {
        par.resize(501,-1);
        rank.resize(501,1);
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                if(grid[i][j]){
                    union_(i,j+250);
                }
            }
        }

        unordered_map<int,int> mp;
          for(int i=0;i<grid.size();++i){
                for(int j=0;j<grid[0].size();++j){
                    if(grid[i][j]){
                      mp[find(i)]++;}
          }
          }
          int ans=0;
        for(auto& x:mp){
           if(x.second>=2){
               ans+=x.second;
           }
        }
        return ans;
    }
};
