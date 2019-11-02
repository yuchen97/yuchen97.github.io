/*********************************************************************************
  *Copyright(C),xxx-xxx
  *FileName:   17HasSubtree.cpp
  *Author:  chenyu
  *Version:  1.0
  *Date:  2019/10/25
  *Description:  Input two binary trees A, B to determine if B is a substructure of A. 
                 (ps: We agree that an empty tree is not a substructure of any tree)
  *Others:  NewCoderOffer17
  *Code List: 
  *History:  
     1.Date: 2019/10/25
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
    bool HasSubtree(TreeNode* pRoot1, TreeNode* pRoot2)
    {
        bool flag = false;
        if(pRoot1!=nullptr && pRoot2!=nullptr){
            if(pRoot1->val == pRoot2->val){
                flag = Tree1HaveTree2(pRoot1, pRoot2);
            }
            if(!flag)
                flag = HasSubtree(pRoot1->left, pRoot2);
            if(!flag)
                flag = HasSubtree(pRoot1->right, pRoot2);
        }
        return flag;
    }
    bool Tree1HaveTree2(TreeNode* pRoot1, TreeNode* pRoot2){
        if(pRoot2 == nullptr)
            return true;
        if(pRoot1 == nullptr)
            return false;
        if(pRoot1->val != pRoot2->val)
            return false;
  
        return Tree1HaveTree2(pRoot1->left, pRoot2->left)&&
            Tree1HaveTree2(pRoot1->right, pRoot2->right);
    }
};