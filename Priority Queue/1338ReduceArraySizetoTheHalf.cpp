// You are given an integer array arr. You can choose a set of integers and remove all the occurrences of these integers in the array.

// Return the minimum size of the set so that at least half of the integers of the array are removed.


class Solution {
public:
    class Pair{
        public:
            int num;
            int fr;

            Pair(){}

            Pair(int n,int f){
                num = n;
                fr = f;
            }
    };

    class Comp{
        public:
            bool operator()(Pair p1,Pair p2){
                return p1.fr < p2.fr;
            }
    };

    int minSetSize(vector<int>& arr) {
        int n=arr.size();

        priority_queue<Pair,vector<Pair>,Comp>pq;
        unordered_map<int,int>ump;
        for(int i=0;i<n;i++){
            ump[arr[i]]++;
        }

        for(auto x:ump){
            pq.push(Pair(x.first,x.second));
        }

        int ans=0,cnt=0;
        while(!pq.empty()){
            Pair tmp = pq.top();
            pq.pop();

            cnt += tmp.fr;
            ans++;
            if(cnt >= n/2){
                return ans;
            }
        }
        return ans;
    }
};
