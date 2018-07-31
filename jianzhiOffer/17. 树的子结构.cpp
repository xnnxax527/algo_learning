/**
* 17. 树的子结构.cpp
* @author jiashen
* @description 
* @created Mon Jul 23 2018 13:01:22 GMT+0800 (CST)
* @copyright 
* @last-modified Mon Jul 23 2018 13:01:24 GMT+0800 (CST)
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
 * 思路：对于A树每个节点，首先判断对于当前节点开始，B树是不是它的子树，另外需要判断对于当前节点的左右子树，B树是不是他们的子树
 * 因此函数分，判断是否为当前节点子树的isSubTree 和 判断当前树是否含有子树HasSubtree两个
 */
class Solution {
public:
    bool HasSubtree(TreeNode* pRoot1, TreeNode* pRoot2)
    {
        if(pRoot1 == NULL || pRoot2 == NULL)  return false;
        // 对当前节点判断是否为当前节点开始的子树，并判断是否为左右子树的子树.
        return isSubTree(pRoot1, pRoot2) || HasSubtree(pRoot1->left, pRoot2) || HasSubtree(pRoot1->right, pRoot2);
    }

    bool isSubTree(TreeNode* p1, TreeNode* p2)
    {
        // 因为一开始有判断p2为空的情况，所以这里p2为空，必然是已经遍历完了.
        if(p2 == NULL)  return true;
        if(p1 == NULL)    return false;
        if(p1->val == p2->val)
        {
            return isSubTree(p1->left, p2->left) && isSubTree(p1->right, p2->right);
        }
        else    return false;
    }
};