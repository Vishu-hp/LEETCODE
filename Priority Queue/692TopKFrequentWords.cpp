class Solution {
public:
    class Pair{
        public:
        string str;
        int fr;
        
        Pair(){}
        
        Pair(string s,int f){
            str = s;
            fr = f;
        }
    };
    
    class Comp{
        public:
            bool operator()(Pair p1,Pair p2){
                return p1.fr > p2.fr;
            }
    };
    
   
    
    vector<string> topKFrequent(vector<string>& words, int k) {
        unordered_map<string,int>ump;
        for(int i=0;i<words.size();i++){
            ump[words[i]]++;
        }
        
       priority_queue<pair<int, string>>pq;
        for(auto &it: ump){
            pq.push(make_pair(-it.second, it.first));
            if(pq.size() > k){
                pq.pop();
            }
        }
        
       vector<pair<int,string>>t1(k);
        int idx=0;
        while(!pq.empty()){
            t1[idx].first = pq.top().first;
            t1[idx].second = pq.top().second;
            idx++;
            pq.pop();
        }
        sort(t1.begin(),t1.end());
        vector<string>ans;
        for(int i=0;i<k;i++){
            ans.push_back(t1[i].second);
        }
        return ans;
        
    }
};
