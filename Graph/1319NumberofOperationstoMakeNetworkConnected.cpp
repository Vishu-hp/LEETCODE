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
                par[i] = i;
                rank[i] = 1;
            }
        }

        int find(int x){
            if(par[x]==x){
                return x;
            }

            int gl = find(par[x]);
            par[x] = gl;
            return gl;
        }

        bool union_(int a,int b){
            int l1=find(a);
            int l2 = find(b);

            if(l1==l2){
                return true;
            }

            if(rank[l1]<rank[l2]){
                par[l1]=l2;
            }
            else if(rank[l2]<rank[l1]){
                par[l2]=l1;
            }
            else{
                par[l2]=l1;
                rank[l1]++;
            }

            return false;
        }

    };

    int makeConnected(int n, vector<vector<int>>& connections) {
        if(connections.size()<n-1){
            return -1;
        }

        sort(connections.begin(),connections.end());
        DSU obj(n);
        int exE=0;
        for(int i=0;i<connections.size();i++){
            int a=connections[i][0];
            int b=connections[i][1];

            if(obj.union_(a,b)){
                exE++;
            }
        }
        
        int numComp=0;
        for(int i=0;i<n;i++){
            if(i == obj.find(i)){
                numComp++;
            }
        }

        if(exE >= numComp-1){
            return numComp-1;
        }
        return -1;
    }
};
