/**
* 18. 二叉树的镜像.cpp
* @author jiashen
* @description 
* @created Mon Jul 23 2018 13:22:48 GMT+0800 (CST)
* @copyright 
* @last-modified Mon Jul 23 2018 13:22:48 GMT+0800 (CST)
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
 * 递归解法
 */
class Solution {
public:
    void Mirror(TreeNode *pRoot) {
        if(pRoot == NULL)   return;
        TreeNode *tmp = pRoot->left;
        pRoot->left = pRoot->right;
        pRoot->right = tmp;
        Mirror(pRoot->left);
        Mirror(pRoot->right);
        return;
    }
};