/**
* 4.重建二叉树.cpp
* @author jiashen
* @description 
* @created Thu Jun 21 2018 23:36:02 GMT+0800 (CST)
* @copyright 
* @last-modified Thu Jun 21 2018 23:36:02 GMT+0800 (CST)
*/

/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

/**
 * @brief 
 * 根据前序遍历和中序遍历的特点，前序遍历的第一个节点必然为根节点，而中序遍历中该值左边数组为其左子树，右边数组为其右子树，以此可以进行分治。
 * 通过递归调用可以实现，这里没有额外的空间开销。
 * 要注意会存在start_vin > end_vin，return NULL
 */
class Solution {
public:

    TreeNode* reConstructBinaryTree(vector<int> pre,vector<int> vin) {
        TreeNode* res = recurConstruct(pre, vin, 0, 0, vin.size()-1);
        return res;
    }

    TreeNode* recurConstruct(vector<int> pre, vector<int> vin, int curr, int start_vin, int end_vin)
    {
        if( start_vin > end_vin )   return NULL;
        TreeNode* root = new TreeNode(pre[curr]);
        int idx = -1;
        for(int i=start_vin; i<=end_vin; i++)
        {
            if(pre[curr] == vin[i])
            {
                idx = i;
                break;
            }
        }
        int left_nums = idx - start_vin;
        root->left = recurConstruct(pre, vin, curr+1, start_vin, idx-1);
        root->right = recurConstruct(pre, vin, curr+left_nums+1, idx+1, end_vin);
        return root;
        
    }
};