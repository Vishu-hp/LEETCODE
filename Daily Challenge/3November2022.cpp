// https://leetcode.com/problems/longest-palindrome-by-concatenating-two-letter-words/

class Solution {
public:
    int longestPalindrome(vector<string>& words) {
        unordered_map<string,int>mp1;
        for(int i=0;i<words.size();i++){
            mp1[words[i]]++ ;
        }
        
       int ans=0;
        int cnt=0;
        for(int i=0;i<words.size();i++){
            string s = words[i];
            string rev = s;
            reverse(rev.begin(),rev.end());
            
            if( s!=rev && mp1[s]>0 && mp1[rev]>0){
                ans+=4;
                mp1[s]--;
                mp1[rev]--;
            }
            else if(s == rev && mp1[s]>1){
                ans+=4;
                mp1[s] -= 2;
            }
            else if(s==rev && cnt==0 && mp1[s]>0){
                ans+=2;
                mp1[s]--;
                cnt++;
            }
        }
        return ans;
    }
};
