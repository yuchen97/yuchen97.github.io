/*********************************************************************************
  *Copyright(C),xxx-xxx
  *FileName:   04reConstructBinaryTree.cpp
  *Author:  chenyu
  *Version:  1.0
  *Date:  2019/10/16
  *Description:  Enter a preorder traversal and an inorder traversal of the binarytree,
                 and reconstruct the binarytree.
  *Others:  NewCoderOffer4
  *Code List: 
  *History:  
     1.Date: 2019/10/16
       Author: chenyu
       Modification: create
       
**********************************************************************************/
/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* reConstructBinaryTree(vector<int> pre,vector<int> vin) {
        if( pre.size()!=vin.size() || pre.empty() ){
            return nullptr;
        } else {
            int len = pre.size();
            return ConstructCore(pre, vin, 0, len-1, 0, len-1);
        }
    }
    TreeNode* ConstructCore(vector<int> pre, vector<int> vin, int pb, int pe, int vb, int ve){
         
        if(pb>pe || vb>ve)
            return nullptr;
        TreeNode* pRoot = new TreeNode(pre[pb]);
        for(int i=vb; i<=ve; ++i){
            if(vin[i] == pre[pb]){
                pRoot->left = ConstructCore(pre, vin, pb+1, pb+i-vb, vb, i-1);
                pRoot->right = ConstructCore(pre, vin, pb+i-vb+1, pe, i+1, ve);
                break;
            }
        }
        return pRoot;
    }
};
