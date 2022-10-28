// https://leetcode.com/problems/evaluate-division/

class Solution {
public:
    class Pair{
        public:
        string nbr;
        double w;
        
        Pair(){}
        
        Pair(string nbr,double w){
            this->nbr= nbr;
            this->w = w;
        }
    };
    
    unordered_map<string,vector<Pair>>g;
    
    double dfs(string s,string d,unordered_set<string>&vis){
       if(g.find(s)==g.end() && g.find(d)==g.end()){
           return -1.0;
       }
        
        if(s == d){
            return 1.0;
        }
        
        vis.insert(s);
        for(auto x:g[s]){
            string nbr = x.nbr;
            double w = x.w;
            
            if(vis.find(nbr) == vis.end()){
                double tmpAns = dfs(nbr,d,vis);
                if(tmpAns != -1.0){
                    return tmpAns*w;
                }
            }
        }
        return -1.0;
    }
    
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        for(int i=0;i<equations.size();i++){
            string u = equations[i][0];
            string v = equations[i][1];
            double val = values[i];
            
            g[u].push_back(Pair(v,val));
            g[v].push_back(Pair(u,1/val));
        }   
        
        vector<double>ans;
        for(int i=0;i<queries.size();i++){
            string s = queries[i][0];
            string d = queries[i][1];
            
            unordered_set<string>vis;
            
            double tmp = dfs(s,d,vis);
            ans.push_back(tmp);
        }
        return ans;
    }
};
