// https://leetcode.com/problems/number-of-ways-to-arrive-at-destination/

class Pair{
    public:
    int v;
    long long wsf;
    
    Pair(int v,long long wsf){
        this->v = v;
        this->wsf = wsf;
    }
};

bool operator <(const Pair &p1,const Pair &p2){
    return p1.wsf > p2.wsf;
}

class Solution {
public:
    int mod = 1e9+7;
    
    class Edge{
      public:
        int nbr;
        int wt;
        
        Edge(int nbr,int wt){
            this->nbr = nbr;
            this->wt = wt;
        }
    };
    
    int countPaths(int n, vector<vector<int>>& roads) {
        vector<Edge>g[n];
        for(int i=0;i<roads.size();i++){
            int u = roads[i][0];
            int v = roads[i][1];
            int w = roads[i][2];
            
            g[u].push_back(Edge(v,w));
            g[v].push_back(Edge(u,w));
        }
        
        priority_queue<Pair>pq;
        pq.push(Pair(0,0));
        vector<long long>dis(n,LLONG_MAX);
        dis[0]=0;
        vector<long long>ways(n,0);
        ways[0]=1;
        
        while(pq.size()>0){
            Pair rem = pq.top();
            pq.pop();
            
            for(auto x:g[rem.v]){
                int nbr = x.nbr;
                long long wt = x.wt;
                
                if(rem.wsf+wt<dis[nbr]){
                    dis[nbr] = rem.wsf + wt;
                    ways[nbr] = ways[rem.v];
                    pq.push(Pair(nbr,rem.wsf+wt));
                }
                else if(rem.wsf+wt == dis[nbr]){
                    ways[nbr] = (ways[nbr] + ways[rem.v])%mod ;
                }
                
            }
        }
      
        return ways[n-1];
    }
};
