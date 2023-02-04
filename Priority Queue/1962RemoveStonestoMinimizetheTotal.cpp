class Solution {
public:
    int minStoneSum(vector<int>& piles, int k) {
        priority_queue<int>pq;
        int n=piles.size();

        for(int i=0;i<n;i++){
            pq.push(piles[i]);
        }

        int rem;
        while(!pq.empty() && k--){
            rem = pq.top();
            pq.pop();

            pq.push(rem-floor(rem/2));
        }

        int ans=0,t;
        while(!pq.empty()){
            t= pq.top();
            pq.pop();

            ans += t;
        }
        return ans;
    }
};
