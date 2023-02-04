class Solution {
public:
    class Pair{
        public:
            long long rd;
            long long cr;

            Pair(){}

            Pair(long long  r,long long c){
                rd = r;
                cr=c;
            }
    };

    class Comp{
        public:
        bool operator()(Pair p1,Pair p2){
            return p1.cr < p2.cr;
        }
    };

    long long maximumImportance(int n, vector<vector<int>>& roads) {
        priority_queue<Pair,vector<Pair>,Comp>pq;
        unordered_map<long long,long long>ump;
        for(int i=0;i<roads.size();i++){
            ump[roads[i][0]]++;
            ump[roads[i][1]]++;
        }

        for(auto x:ump){
            pq.push(Pair(x.first,x.second));
        }

        long long ans=0;
        for(int i=n;i>=1 && pq.empty()==false;i--){
            Pair tmp = pq.top();
            pq.pop();

            ans += tmp.cr*i;
        }
        return ans;
    }
};
