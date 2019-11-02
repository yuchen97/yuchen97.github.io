/*********************************************************************************
  *Copyright(C),xxx-xxx
  *FileName:   22PrintFromTopToBottom.cpp
  *Author:  chenyu
  *Version:  1.0
  *Date:  2019/11/01
  *Description:  Print each node of the binary tree from top to bottom, and the same 
                 layer nodes print from left to right.
  *Others:  NewCoderOffer22
  *Code List: 
  *History:  
     1.Date: 2019/11/01
       Author: chenyu
       Modification: create

**********************************************************************************/
/*
struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
    TreeNode(int x) :
            val(x), left(NULL), right(NULL) {
    }
};*/
class Solution {
public:
    vector<int> PrintFromTopToBottom(TreeNode* root) {
        vector<int> arr;
        queue<TreeNode*> q;
        if(root == nullptr)  return arr;
         
        TreeNode* node = root;
        q.push(node);
        while(!q.empty()){
            node = q.front();
            q.pop();
            if(node->left != nullptr)
                q.push(node->left);
            if(node->right != nullptr)
                q.push(node->right);
            arr.push_back(node->val);
        }
        return arr;
    }
};