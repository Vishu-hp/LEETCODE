// You are given an m x n binary matrix mat of 1's (representing soldiers) and 0's (representing civilians). The soldiers are positioned in front of the civilians. That is, all the 1's will appear to the left of all the 0's in each row.

// A row i is weaker than a row j if one of the following is true:

// The number of soldiers in row i is less than the number of soldiers in row j.
// Both rows have the same number of soldiers and i < j.
// Return the indices of the k weakest rows in the matrix ordered from weakest to strongest.




class Solution {
public:
    
    class Pair{
        public:
        int pw,idx;
        
        Pair(){}
        
        Pair(int p,int i){
            pw = p;
            idx = i;
        }
    };
    
    class PairComp{
        public:
            bool operator()(Pair p1,Pair p2){
                if(p1.pw == p2.pw){
                    return p1.idx > p2.idx;
                }
                return p1.pw > p2.pw;
            }
    };
    
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
        priority_queue<Pair,vector<Pair>,PairComp>pq;
        int m=mat.size() , n=mat[0].size();
        for(int i=0;i<m;i++){
            Pair p;
            p.idx=i;
            int cnt=0;
            for(int j=0;j<n;j++){
                if(mat[i][j]==1){
                    cnt++;
                }
                else{
                    break;
                }
            }
            p.pw = cnt;
            pq.push(p);
        }
        
        vector<int>ans(k);
        for(int i=0;i<k;i++){
            Pair rem = pq.top();
            pq.pop();
            ans[i] = rem.idx;
        }
        return ans;
    }
};
