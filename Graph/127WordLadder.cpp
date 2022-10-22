// https://leetcode.com/problems/word-ladder/

class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        if(find(wordList.begin(),wordList.end(),endWord) == wordList.end()){
            return 0;
        }
        
        unordered_map<string,vector<string>>adjList;
        for(auto x:wordList){
            for(int j=0;j<x.length();j++){
                string pattern = x.substr(0,j)+"*"+x.substr(j+1);
                adjList[pattern].push_back(x);
            }
        }
        
        unordered_map<string,bool>vis;
        queue<string>q;
        q.push(beginWord);
        int ans=1;
        while(q.size()>0){
            int n = q.size();
            for(int i=0;i<n;i++){
                string rem = q.front();
                q.pop();
                
                if(rem == endWord){
                    return ans;
                }
                
                if(vis[rem]==true){
                    continue;
                }
                vis[rem] = true;
                
                for(int i=0;i<rem.length();i++){
                    string pattern = rem.substr(0,i)+"*"+rem.substr(i+1);
                    
                    for(auto x:adjList[pattern]){
                        if(vis[x]==false){
                            q.push(x);
                        }
                    }
                }
            }
            ans++;
        }
        return 0;
    }
};
