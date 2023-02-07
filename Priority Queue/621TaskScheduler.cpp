// USING PRIORITY QUEUE
// class Solution {
// public:
//     class Pair{
//         public:
//             int fr;
//             int tm;
        
//             Pair(){}
        
//             Pair(int f,int t){
//                 fr = f;
//                 tm = t;
//             }
//     };
    
//     class Comp{
//         public:
//         bool operator()(Pair p1,Pair p2){
//             return p1.tm > p2.tm;
//         }
//     };
    
//     int leastInterval(vector<char>& tasks, int n) {
//         int len = tasks.size();
//         priority_queue<int>pq1;
//         int time=0;
//         priority_queue<Pair,vector<Pair>,Comp>pq2;
//         unordered_map<char,int>ump;
//         for(auto x:tasks){
//             ump[x]++;
//         }
        
//         for(auto x:ump){
//             pq1.push(x.second);
//         }
        
//         while(!pq1.empty() || !pq2.empty()){
//             time++;

//             if(pq1.empty()==false){
//                 int rem = pq1.top();
//                 pq1.pop();
//                 rem -= 1;
//                 if(rem!=0){
//                     pq2.push(Pair(rem,time+n));                
//                 }
//             }
            
            
            
//             if(!pq2.empty() && pq2.top().tm == time){
//                 Pair rem = pq2.top();
//                 pq2.pop();
//                 pq1.push(rem.fr);
//             }
//         }
//         return time;
//     }
// };




// USING QUEUE
class Solution {
public:
    class Pair{
        public:
            int fr;
            int tm;
        
            Pair(){}
        
            Pair(int f,int t){
                fr = f;
                tm = t;
            }
    };
    
    
    int leastInterval(vector<char>& tasks, int n) {
        int len = tasks.size();
        priority_queue<int>pq1;
        int time=0;
        
        queue<Pair>pq2;
        unordered_map<char,int>ump;
        for(auto x:tasks){
            ump[x]++;
        }
        
        for(auto x:ump){
            pq1.push(x.second);
        }
        
        while(!pq1.empty() || !pq2.empty()){
            time++;

            if(pq1.empty()==false){
                int rem = pq1.top();
                pq1.pop();
                rem -= 1;
                if(rem!=0){
                    pq2.push(Pair(rem,time+n));                
                }
            }
            
            
            
            if(!pq2.empty() && pq2.front().tm == time){
                Pair rem = pq2.front();
                pq2.pop();
                pq1.push(rem.fr);
            }
        }
        return time;
    }
};
