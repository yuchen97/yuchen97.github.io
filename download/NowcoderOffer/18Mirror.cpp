/*********************************************************************************
  *Copyright(C),xxx-xxx
  *FileName:   18Mirror.cpp
  *Author:  chenyu
  *Version:  1.0
  *Date:  2019/10/27
  *Description:  Operates the given binary tree and transforms it into a mirror of 
                 the source binary tree.
  *Others:  NewCoderOffer18
  *Code List: 
  *History:  
     1.Date: 2019/10/27
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
    void Mirror(TreeNode *pRoot) {
        if(pRoot==nullptr || (pRoot->left==nullptr && pRoot->right==nullptr))
            return;
        TreeNode* pNode = pRoot->left;
        pRoot->left = pRoot->right;
        pRoot->right = pNode;
        if(pRoot->right != nullptr)
            Mirror(pRoot->right);
        if(pRoot->left != nullptr)
            Mirror(pRoot->left);
    }
};
