class Solution {
public:
    class DSU{
        public:
        vector<int>par;
        vector<int>rank;

        DSU(int n){
            par.resize(n);
            rank.resize(n);

            for(int i=0;i<n;i++){
                par[i]=i;
                rank[i]=1;
            }
        }

        int find(int x){
            if(par[x]==x){
                return x;
            }

            int gl=find(par[x]);
            par[x]=gl;
            return gl;
        }

        void union_(int a,int b){
            int l1 = find(a);
            int l2=find(b);

            if(l1==l2){
                return;
            }

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
            return;
        }
    };

    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        int n=accounts.size();
        DSU obj(n);      

        unordered_map<string,int>ump;
        for(int i=0;i<n;i++){
            for(int j=1;j<accounts[i].size();j++){
                if(ump.find(accounts[i][j]) == ump.end()){
                    ump[accounts[i][j]] = i;
                }
                else{
                    obj.union_(i,ump[accounts[i][j]]);
                }
            }
        }

        vector<string>v1[n];
        for(auto x:ump){
            v1[obj.find(x.second)].push_back(x.first);
        }

        vector<vector<string>>ans;
        vector<string>v2;
        for(int i=0;i<n;i++){
            if(v1[i].size()==0){
                continue;
            }
            v2.clear();
            sort(v1[i].begin(),v1[i].end());
            v2.push_back(accounts[i][0]);
            for(auto x:v1[i]){
                v2.push_back(x);
            }
            ans.push_back(v2);
        }
        return ans;
    }
};
