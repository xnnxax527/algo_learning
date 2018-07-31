/**
* 22. 从上往下打印二叉树.cpp
* @author jiashen
* @description 
* @created Tue Jul 24 2018 05:42:22 GMT+0800 (CST)
* @copyright 
* @last-modified Tue Jul 24 2018 05:42:22 GMT+0800 (CST)
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
 * 递归解法, 如果当前节点的左右子树存在，先分别打印，再考虑左右子树。
 */
class Solution {
public:
    vector<int> PrintFromTopToBottom(TreeNode* root) {
        vector<int> res;
        if(root==NULL)  return res;
        res.push_back(root->val);
        RecurPrint(root, res);
        return res;
    }
    void RecurPrint(TreeNode* root, vector<int> &res)
    {
        if(root->left)
            res.push_back(root->left->val);
        if(root->right)
            res.push_back(root->right->val);
        if(root->left)
            RecurPrint(root->left, res);
        if(root->right)
            RecurPrint(root->right, res);
    }
};

/**
 * @brief 
 * 很明显的广度优先遍历(bfs)
 */
class Solution {
public:
    vector<int> PrintFromTopToBottom(TreeNode* root) {
        vector<int> res;
        if(root==NULL)  return res;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty())
        {
            TreeNode* node = q.front();
            q.pop();
            res.push_back(node->val);
            // left and right
            if(node->left)
                q.push(node->left);
            if(node->right)
                q.push(node->right);
        }
        return res;
    }
};