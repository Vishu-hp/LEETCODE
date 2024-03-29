class Solution {
public:
    int kthLargestValue(vector<vector<int>>& matrix, int k) {
        priority_queue<int,vector<int>,greater<int>>pq;
        for(int i=0;i<matrix.size();i++){
            for(int j=0;j<matrix[0].size();j++){
                if(j!=0){
                    matrix[i][j] = matrix[i][j-1]^matrix[i][j] ;
                }
            }
        }

        for(int i=0;i<matrix.size();i++){
            for(int j=0;j<matrix[0].size();j++){
                if(i!=0){
                    matrix[i][j] = matrix[i-1][j]^matrix[i][j] ;
                }
            }
        }

        for(int i=0;i<matrix.size();i++){
            for(int j=0;j<matrix[0].size();j++){
                pq.push(matrix[i][j]);
                if(pq.size()>k){
                    pq.pop();
                }
            }
        }


        return pq.top();
    }
};
