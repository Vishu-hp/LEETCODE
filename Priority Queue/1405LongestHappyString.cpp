class Solution {
public:
    class Pair{
        public:
            char ch;
            int cnt;

            Pair(){}

            Pair(char c,int cn){
                ch = c;
                cnt = cn;
            }
    };

    class Comp{
        public:
            bool operator()(Pair p1,Pair p2){
                return p1.cnt < p2.cnt;
            }
    };

    string longestDiverseString(int a, int b, int c) {
        priority_queue<Pair,vector<Pair>,Comp>pq;
        if(a!=0){
            pq.push(Pair('a',a));
        }
        
        if(b!=0){
            pq.push(Pair('b',b));
        }

        if(c!=0){
            pq.push(Pair('c',c));
        }

        string ans="";
        while(!pq.empty()){
            Pair t1 = pq.top();
            pq.pop();

            if(ans.length()>1 && ans[ans.length()-1]==ans[ans.length()-2] && ans[ans.length()-1]==t1.ch){
                if(!pq.empty()){
                    Pair t2 = pq.top();
                    pq.pop();

                    ans += t2.ch;
                    if(t2.cnt > 1){
                        t2.cnt -= 1;
                        pq.push(t2);
                    }
                    pq.push(t1);
                }
                else{
                    return ans;
                }
            }
            else{
                ans += t1.ch;
                if(t1.cnt>1){
                    t1.cnt -= 1;
                    pq.push(t1);
                }
            }
        }

        
        return ans;
    }
};
