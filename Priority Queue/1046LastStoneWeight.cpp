// You are given an array of integers stones where stones[i] is the weight of the ith stone.

// We are playing a game with the stones. On each turn, we choose the heaviest two stones and smash them together. Suppose the heaviest two stones have weights x and y with x <= y. The result of this smash is:

// If x == y, both stones are destroyed, and
// If x != y, the stone of weight x is destroyed, and the stone of weight y has new weight y - x.
// At the end of the game, there is at most one stone left.

// Return the weight of the last remaining stone. If there are no stones left, return 0.


class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int>pq;
        int n=stones.size();
        for(int i=0;i<n;i++){
            pq.push(stones[i]);
        }
        
        while(!pq.empty()){
            if(pq.size()>=2){
                int v1=pq.top();
                pq.pop();
                int v2=pq.top();
                pq.pop();
                
                if(v1!=v2){
                    pq.push(abs(v1-v2));
                }
            }
            else{
                break;
            }
        }
        
        if(pq.size()==1){
            int a=pq.top();
            pq.pop();
            return a;
        }
        return 0;
    }
};
