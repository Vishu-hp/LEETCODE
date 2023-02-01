// You are given a positive integer num. You may swap any two digits of num that have the same parity (i.e. both odd digits or both even digits).

// Return the largest possible value of num after any number of swaps


class Solution {
public:
    int largestInteger(int num) {
        priority_queue<int,vector<int>,greater<int>>pq1;
        priority_queue<int,vector<int>,greater<int>>pq2;
    
        int tmp=num , nod=0;
        while(tmp!=0){
            int ld=tmp%10;
            tmp /= 10;
            nod++;
            if(ld%2==0){
                pq1.push(ld);
            }
            else{
                pq2.push(ld);
            }
        }
        
        tmp = num;
        int ans=0;
        long long int p=1;
        while(tmp!=0){
            int ld = tmp%10;
            tmp /= 10;
            if(ld%2==0){
                int r = pq1.top();
                pq1.pop();
                ans += p*r;
                p *= 10;
            }
            else{
                int r = pq2.top();
                pq2.pop();
                ans += p*r;
                p *= 10;
            }
        }
        return ans;
    }
};
