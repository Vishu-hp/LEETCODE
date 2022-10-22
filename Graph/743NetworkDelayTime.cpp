// https://leetcode.com/problems/network-delay-time/

class Pair{
        public:
        int vt;
        int wsf;
      
        Pair(){}
        
        Pair(int vt,int wsf){
            this->vt=vt;
            this->wsf=wsf;
        }
    };
    
    bool operator <(const Pair &p1,const Pair &p2){
        return p1.wsf>p2.wsf;
    }

class Solution {
public:
    class Edge{
        public:
        int v;
        int w;
        
        Edge(){}
        
        Edge(int v,int w){
            this->v=v;
            this->w=w;
        }
    };
    
    
    
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<Edge>g[n+1];
        for(int i=0;i<times.size();i++){
            int u = times[i][0];
            int v= times[i][1];
            int w = times[i][2];
            
            g[u].push_back(Edge(v,w));
        }
        priority_queue<Pair>pq;
        vector<int>dis(n+1,-1);
        pq.push(Pair(k,0));
        int ans=0;
        while(pq.size()>0){
            Pair rem = pq.top();
            pq.pop();
            
            if(dis[rem.vt]!=-1){
                continue;
            }
            dis[rem.vt] = rem.wsf;
            ans = max(ans,dis[rem.vt]);
            
            for(auto x:g[rem.vt]){
                pq.push(Pair(x.v,rem.wsf+x.w));
            }
        }
        
        for(int i=1;i<n+1;i++){
            if(dis[i]==-1){
                return -1;
            }
        }
        return ans;
    }
};
