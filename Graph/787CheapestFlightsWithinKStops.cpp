// https://leetcode.com/problems/cheapest-flights-within-k-stops/

class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<int>dis(n,INT_MAX);
        dis[src]=0;
        for(int itr=0;itr<=k;itr++){
            vector<int>tmp(dis);
            for(auto x:flights){
                int u = x[0];
                int v = x[1];
                int cost = x[2];
                
                if(dis[u]!=INT_MAX && dis[u]+cost<tmp[v]){
                    tmp[v] = dis[u]+cost;
                }
            }
            dis=tmp;
        }
        return (dis[dst]==INT_MAX)?-1:dis[dst];
        
    }
};
