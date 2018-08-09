/**
* 26. 二叉搜索树与双向链表.cpp
* @author jiashen
* @description 
* @created Thu Aug 02 2018 00:54:51 GMT+0800 (CST)
* @copyright 
* @last-modified Thu Aug 02 2018 00:54:51 GMT+0800 (CST)
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
 * 非递归版本的中序遍历
 * 利用栈来存储，每次修改当前遍历节点和前一遍历节点的指针指向。
 */
class Solution {
public:
    TreeNode* Convert(TreeNode* pRootOfTree)
    {
		if(pRootOfTree == NULL)	return NULL;
        TreeNode* pNewRoot;
		TreeNode* curr = pRootOfTree;
		TreeNode* pre;
		stack<TreeNode*> stack;
		bool isRoot = false;
		while(curr!=NULL || !stack.empty())
		{
			while(curr!=NULL)
			{
				stack.push(curr);
				curr = curr->left;
			}
			curr = stack.top();
			stack.pop();
			if(!isRoot)
			{
				pNewRoot = curr;
				pre = curr;
				isRoot = true;
			}
			else
			{
				pre->right = curr;
				curr->left = pre;
				pre = curr;
			}
			curr = curr->right;

		}
		return pNewRoot;
    }
};