/**
* 24. 二叉树中和为某一值的路径.cpp
* @author jiashen
* @description 
* @created Tue Jul 24 2018 06:35:37 GMT+0800 (CST)
* @copyright 
* @last-modified Tue Jul 24 2018 06:35:37 GMT+0800 (CST)
*/

/*
struct TreeNode {
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
	TreeNode(int x) :
			val(x), left(NULL), right(NULL) {
	}
};*/

/**
 * @brief 
 * 带记忆的dfs，经典!!
 */
class Solution {
public:
	vector<vector<int>> res;
	vector<int> tmp;
    vector<vector<int>> FindPath(TreeNode* root,int expectNumber) {
		if(root)
			dfs(root, expectNumber);
		return res;

    }
	void dfs(TreeNode* root,int expectNumber)
	{
		tmp.push_back(root->val);
		// leaf node
		if(!root->left && !root->right && root->val == expectNumber)
				res.push_back(tmp);
		else
		{
			if( root->left )	dfs(root->left, expectNumber-root->val);
			if( root->right)	dfs(root->right, expectNumber-root->val);
		}
		tmp.pop_back();

	}
};