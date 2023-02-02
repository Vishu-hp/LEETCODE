// You are playing a solitaire game with three piles of stones of sizes a, b and c respectively. Each turn you choose two different non-empty piles, take one stone from each, and add 1 point to your score. The game stops when there are fewer than two non-empty piles (meaning there are no more available moves).

// Given three integers a, b and c, return the maximum score you can get.

class Solution {
public:
    int maximumScore(int a, int b, int c) {
        priority_queue<int>pq;
        pq.push(a);
        pq.push(b);
        pq.push(c);

        int ans=0;
        while(pq.size()>=2){
            int t1 = pq.top();
            pq.pop();
            int t2 = pq.top();
            pq.pop();

            ans++;
            if(t1>1){
                pq.push(t1-1);
            }
            if(t2>1){
                pq.push(t2-1);
            }
        }
        return ans;
    }
};
