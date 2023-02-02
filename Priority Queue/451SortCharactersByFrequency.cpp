// Given a string s, sort it in decreasing order based on the frequency of the characters. The frequency of a character is the number of times it appears in the string.

// Return the sorted string. If there are multiple answers, return any of them.

class Solution {
public:
    class Pair{
        public:
            int fr;
            char ch;

            Pair(){}

            Pair(int f,char c){
                fr=f;
                ch=c;
            }
    };

    class Comp{
        public:
            bool operator()(Pair p1,Pair p2){
                return p1.fr < p2.fr;
            }
    };

    string frequencySort(string s) {
        int n = s.length();

        priority_queue<Pair,vector<Pair>,Comp>pq;
        unordered_map<char,int>ump;
        for(int i=0;i<n;i++){
            ump[s[i]]++;
        }
        for(auto x:ump){
            pq.push(Pair(x.second,x.first));
        }

        string ans="";
        while(!pq.empty()){
            int cnt = pq.top().fr;
            char ch = pq.top().ch;
            pq.pop();

            for(int i=0;i<cnt;i++){
                ans += ch;
            }
        }
        return ans;
    }
};
