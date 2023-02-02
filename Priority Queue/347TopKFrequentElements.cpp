class Solution {
public:
    class Pair{
        public:
            int num;
            int fr;

            Pair(){}

            Pair(int n,int f){
                num = n;
                fr= f;
            }
    };

    class Comp{
        public:
            bool operator()(Pair p1,Pair p2){
                return p1.fr < p2.fr;
            }
    };

    vector<int> topKFrequent(vector<int>& nums, int k) {
        int n = nums.size();
        priority_queue<Pair,vector<Pair>,Comp>pq;
        unordered_map<int,int>ump;
        for(int i=0;i<n;i++){
            ump[nums[i]]++;
        }

        for(auto x:ump){
            pq.push(Pair(x.first,x.second));
        }

        int cnt=0;
        vector<int>ans;
        while(!pq.empty()){
            Pair tmp = pq.top();
            pq.pop();

            cnt++;
            ans.push_back(tmp.num);
            if(cnt==k){
                return ans;
            }
        }
        return ans;
    }
};
