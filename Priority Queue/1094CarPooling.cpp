class Solution {
public:
    static bool comp(vector<int>&a,vector<int>&b){
        if(a[1]!=b[1]){
            return a[1]<b[1];        
        }
        return a[2]<b[2];
    }
    
    class Pair{
        public:
            int des;
            int nop;
        
            Pair(){}
        
            Pair(int d,int n){
                des = d;
                nop = n;
            }
    };
    
    class Comp{
        public:
            bool operator()(Pair p1,Pair p2){
                return p1.des > p2.des;
            }      
    };
    
    bool carPooling(vector<vector<int>>& trips, int capacity) {
        sort(trips.begin(),trips.end(),comp);
        
        priority_queue<Pair,vector<Pair>,Comp>pq;
        pq.push(Pair(trips[0][2],trips[0][0]));
        
        int cc=trips[0][0];
        if(cc>capacity){
            return false;
        }
        
        for(int i=1;i<trips.size();i++){
            while(!pq.empty() && pq.top().des <= trips[i][1]){
                cc -= pq.top().nop;
                pq.pop();
            }
            
            cc+= trips[i][0];
            if(cc> capacity){
                return false;
            }
            pq.push(Pair(trips[i][2],trips[i][0]));
        }
        return true;
    }
};
