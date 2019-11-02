/*********************************************************************************
  *Copyright(C),xxx-xxx
  *FileName:   24FindPath.cpp
  *Author:  chenyu
  *Version:  1.0
  *Date:  2019/11/02
  *Description:  Input the union node of a binary tree and an integer to print out 
                 the path where the sum of the node values in the binary tree is the 
                 input integer. 
                 A path is defined as a path from the root node of the tree to the 
                 next node until the leaf node passes. 
                 (Note: In the list of return values, the array with a large array 
                 length is ahead)
  *Others:  NewCoderOffer24
  *Code List: 
  *History:  
     1.Date: 2019/11/02
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
    vector<vector<int> > vec;
    void getPathVec(TreeNode* root, vector<int> arr, int sum){
        if(root == nullptr) return;
        
        arr.push_back(root->val);
        if(sum==root->val && root->left==nullptr && root->right==nullptr)
            vec.push_back(arr);
        
        if(root->left)
            getPathVec(root->left, arr, sum - root->val);
        if(root->right)
            getPathVec(root->right, arr, sum - root->val);
        
        sum += root->val;
        arr.pop_back();
    }
    
    void ArrSort(){
        int veclen = vec.size();
        for(int i = 0; i < veclen; ++i){
            for(int j = veclen-1; j > i; --j){
                if(vec[i].size() <  vec[j].size())
                    vec[i].swap(vec[j]);
            }
        }
    }
    
    vector<vector<int> > FindPath(TreeNode* root,int expectNumber) {
        vector<int> arr;
        getPathVec(root, arr, expectNumber);
        ArrSort();
        return vec;
    }
};