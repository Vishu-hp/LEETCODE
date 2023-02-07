class Solution {
public:
    class Pair{
        public:
        int xc;
        int yc;
        int md;
        
        Pair(){}
        
        Pair(int x,int y,int d){
            xc = x;
            yc = y;
            md = d;
        }
    };
    
    class Comp{
        public:
        bool operator()(Pair p1,Pair p2){
            return p1.md > p2.md;      
        }
    };
    
    int minimumEffortPath(vector<vector<int>>& heights) {
        int m = heights.size() , n=heights[0].size();
        priority_queue<Pair,vector<Pair>,Comp>pq;
        pq.push(Pair(0,0,0));
        
        int xdir[4]= {0,+1,0,-1};
        int ydir[4]= {-1,0,+1,0};
        while(!pq.empty()){
            Pair rem = pq.top();
            pq.pop();
            
            if(rem.xc == m-1 && rem.yc == n-1){
                return rem.md;
            }
            
             if(rem.xc<0 || rem.yc<0 || rem.xc>=m || rem.yc>=n || heights[rem.xc][rem.yc]==0){
                    continue;
                }
            
            
            for(int i=0;i<4;i++){
                int nx = rem.xc + xdir[i];
                int ny = rem.yc + ydir[i];
                
                if(nx>=0 && ny>=0 && nx<m && ny<n){
                    pq.push(Pair(nx,ny,max(rem.md,abs(heights[rem.xc][rem.yc]-heights[nx][ny]))));                
                }

            }
            heights[rem.xc][rem.yc] = 0;

        }
        return -1;
    }
};
