// https://leetcode.com/problems/find-the-city-with-the-smallest-number-of-neighbors-at-a-threshold-distance/

class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        vector<vector<long long>>floyd(n,vector<long long>(n,INT_MAX));
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(i==j){
                    floyd[i][j]=0;
                }
            }
        }
        
        for(int i=0;i<edges.size();i++){
            int u = edges[i][0];
            int v = edges[i][1];
            int w = edges[i][2];
            
            floyd[u][v]=w;
            floyd[v][u]=w;
        }
        
        for(int k=0;k<n;k++){
            for(int i=0;i<n;i++){
                for(int j=0;j<n;j++){
                    if(floyd[i][k]+floyd[k][j] < floyd[i][j]){
                        floyd[i][j] = floyd[i][k] + floyd[j][k];
                    }
                }
            }
        }
        
        int ansCity;
        int ansCityVal=INT_MAX;
         for(int i=0;i<n;i++){
             int city=0;
            for(int j=0;j<n;j++){
                if(floyd[i][j]<=distanceThreshold){
                    city++;
                }   
            }
             if(city!=0 && city<=ansCityVal){
                 ansCity = i;
                 ansCityVal = city;
             }
        }
        return ansCity;
    }
};
