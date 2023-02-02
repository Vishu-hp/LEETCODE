class Solution {
public:
    class Pair{
        public:
            double dis;
            int idx;

            Pair(){}

            Pair(double d,int i){
                dis=d;
                idx=i;
            }
    };

    class Comp{
        public:
            bool operator()(Pair p1,Pair p2){
                return p1.dis > p2.dis;
            }
    };

    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        int n=points.size();

        priority_queue<Pair,vector<Pair>,Comp>pq;
        for(int i=0;i<n;i++){
            double d = sqrt(pow(points[i][0],2)+pow(points[i][1],2));
            pq.push(Pair(d,i));
        }

        int cnt=0;
        vector<vector<int>>ans;
        while(!pq.empty()){
            Pair tmp = pq.top();
            pq.pop();

            cnt++;
            ans.push_back(points[tmp.idx]);
            if(cnt==k){
                return ans;
            }
        }
        return ans;
    }
};
