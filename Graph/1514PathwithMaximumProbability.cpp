// https://leetcode.com/problems/path-with-maximum-probability/

class Solution {
public:
    class Pair{
        public:
        int nbr;
        double w;
        
        Pair(){}
        
        Pair(int nbr,double w){
            this->nbr = nbr;
            this->w = w;
        }
    };
    
    
    
    
    
    unordered_map<int,vector<Pair>>g;
    
    
   
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start, int end) {
      for(int i=0;i<edges.size();i++){
          int u = edges[i][0];
          int v = edges[i][1];
          double w = succProb[i];
          
          g[u].push_back(Pair(v,w));
          g[v].push_back(Pair(u,w));
      }     
        
        vector<bool>vis(n,false);
        priority_queue<pair<double,int>>pq;
        vector<double>prob(n,-1);
        prob[start]=1.0;
        pq.push({1.0,start});
        while(pq.size()>0){
            int v = pq.top().second;
            double psf = pq.top().first;
            pq.pop();
            
            if(vis[end] == true){
                break;
            }
            
            if(vis[v]==true){
                continue;
            }
            
            vis[v]=true;
            
            for(auto x:g[v]){
                int nbr = x.nbr;
                double p = x.w;
                
                if(vis[nbr]==false){
                    if(prob[nbr] < prob[v]*p){
                        prob[nbr] = prob[v]*p;
                        pq.push({prob[nbr],nbr});
                    }
                }
            }
        }
        
        if(prob[end]==-1){
            return 0;
        }
        else{
            return prob[end];
        }
    }
};
