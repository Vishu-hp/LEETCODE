class Solution {
public:
    void solve(TreeNode* root,vector<vector<int>>&ans,vector<int>&tmp,int targetSum,int sum){
      if(root==NULL){
            return;
        }   
        
        if(root->left==NULL && root->right==NULL){
            if(sum + root->val == targetSum){
                tmp.push_back(root->val);
                ans.push_back(tmp);
                tmp.pop_back();
            }
            return;
        }
                
         
        
        
        
        tmp.push_back(root->val);
        solve(root->left,ans,tmp,targetSum,sum+root->val);
        solve(root->right,ans,tmp,targetSum,sum+root->val);
        tmp.pop_back();
    }
    
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<vector<int>>ans;
        if(root==NULL){
            return ans;
        }
        vector<int>tmp;
        solve(root,ans,tmp,targetSum,0);
        return ans;
    }
};
