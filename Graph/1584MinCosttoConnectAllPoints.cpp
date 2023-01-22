class Solution {
public:
    class DSU{
        public:
        vector<int>par;
        vector<int>rank;

        DSU(int n){
            par.resize(n+1);
            rank.resize(n+1);

            for(int i=0;i<n+1;i++){
                par[i] = i;
                rank[i] = i;
            }
        }

        int find(int x){
            if(par[x]==x){
                return x;
            }

            int gl = find(par[x]);
            par[x]=gl;
            return gl;
        }

        bool union_(int x,int y){
            int l1 = find(x);
            int l2 = find(y);

            if(l1==l2){
                return true;
            }

            if(rank[l1]<rank[l2]){
                par[l1]=l2;
            }
            else if(rank[l1]>rank[l2]){
                par[l2]=l1;
            }
            else{
                par[l2]=l1;
                rank[l1]++;
            }

            return false;
        }
    };

    int minCostConnectPoints(vector<vector<int>>& points) {
        vector<pair<int,pair<int,int>>>edg;

        for(int i=0;i<points.size();i++){
            for(int j=i+1;j<points.size();j++){
                edg.push_back({abs(points[i][0]-points[j][0])+abs(points[i][1]-points[j][1]),
                {i,j}});
            }
        }

        sort(edg.begin(),edg.end());
        DSU obj(points.size());

        int ans=0;
        for(auto x:edg){
            if(obj.find(x.second.first) != obj.find(x.second.second)){
                ans += x.first;
                obj.union_(x.second.first,x.second.second);
            }
        }
        return ans;
    }
};
