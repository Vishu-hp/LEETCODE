class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int>pq;

        for(int i=0;i<nums.size();i++){
            pq.push(nums[i]);
        }

        int cnt=0;
        while(!pq.empty()){
            int tp = pq.top();
            pq.pop();

            cnt++;
            if(cnt==k){
                return tp;
            }
        }
        return -1;
    }
};
