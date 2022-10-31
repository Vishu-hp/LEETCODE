// https://leetcode.com/problems/number-of-restricted-paths-from-first-to-last-node/

class Pair{
        public:
        int v;
        int wsf;
        
        Pair(int v,int wsf){
            this->v = v;
            this->wsf = wsf;
        }
    };
    
    bool operator <(const Pair &p1,const Pair &p2){
        return p1.wsf>p2.wsf;
    }
    

class Solution {
public:
    int mod = 1e9+7;
    
    class Edge{
        public:
        int v;
        int w;
        Edge(){}  
        Edge(int v,int w){
            this->v = v;
            this->w = w;
        }
    };
    
    
    int dfs(vector<Edge>g[],vector<int>&dis,int s,vector<bool>&vis, vector<int>&mem){
        if(s == 1){
            return 1;
        }
        
        if(mem[s] != -1){
            return mem[s];
        }
        
        // vis[s] = true;
        int cnt=0;
        for(auto x:g[s]){
            int val = dis[s];
            int val2 = dis[x.v];
            // if(vis[x.v]==false && val2>val){
            //     cnt = (cnt%mod + dfs(g,dis,x.v,vis,mem)%mod)%mod;
            // }
            
             if(val2>val){
                cnt = (cnt%mod + dfs(g,dis,x.v,vis,mem)%mod)%mod;
            }
        }
        // vis[s] = false;
        mem[s] = cnt%mod;
        return cnt;
    }
    
    int countRestrictedPaths(int n, vector<vector<int>>& edges) {
        vector<Edge>g[n+1];
        for(int i=0;i<edges.size();i++){
            int u = edges[i][0];            
            int v = edges[i][1];
            int w = edges[i][2];
            
            g[u].push_back(Edge(v,w));
            g[v].push_back(Edge(u,w));
        }
        
        priority_queue<Pair>pq;
        vector<int>dis(n+1,-1);
        pq.push(Pair(n,0));
        while(pq.size()>0){
            Pair rem = pq.top();
            pq.pop();
            
            if(dis[rem.v] != -1){
                continue;
            }
            
            dis[rem.v] = rem.wsf;
            
            for(auto x:g[rem.v]){
                if(dis[x.v]==-1){
                    pq.push(Pair(x.v,rem.wsf+x.w));
                }
            }
        }
        
        vector<bool>vis(n+1,false);
        vector<int>mem(n+1,-1);
        int ans = dfs(g,dis,n,vis,mem);
        return ans;
    }
};
