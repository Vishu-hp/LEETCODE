// https://leetcode.com/problems/lexicographically-smallest-equivalent-string/description/

class Solution {
public:
    char find(unordered_map<char,char>&par,char x){
        if(par[x]==x){
            return x;
        }

        char l = find(par,par[x]);
        par[x]=l;
        return l;
    }

    void union_(unordered_map<char,char>&par,char a,char b){
        char l1 = find(par,a);
        char l2 = find(par,b);

        if(l1==l2){
            return;
        }

        if(l1!=l2){
            if(l1<l2){
                par[l2] = l1;
            }
            else if(l2<l1){
                par[l1]=l2;
            }
        }
        return ;
    }

    string smallestEquivalentString(string s1, string s2, string baseStr) {
        unordered_map<char,char>par;
        par['a']='a';
        par['b']='b';
        par['c']='c';
        par['d']='d';
        par['e']='e';
        par['f']='f';
        par['g']='g';
        par['h']='h';
        par['i']='i';
        par['j']='j';
        par['k']='k';
        par['l']='l';
        par['m']='m';
        par['n']='n';
        par['o']='o';
        par['p']='p';
        par['q']='q';
        par['r']='r';
        par['s']='s';
        par['t']='t';
        par['u']='u';
        par['v']='v';
        par['w']='w';
        par['x']='x';
        par['y']='y';
        par['z']='z';



        int n=s1.length();
        for(int i=0;i<n;i++){
            if(find(par,s1[i])!=find(par,s2[i])){
                union_(par,s1[i],s2[i]);
            }
        }        

        string ans=baseStr;
        for(int i=0;i<baseStr.length();i++){
            char l=find(par,baseStr[i]);
            ans[i] = l;
        }
        return ans;
    }
};
