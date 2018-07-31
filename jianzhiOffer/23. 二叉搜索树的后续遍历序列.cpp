/**
* 23. 二叉搜索树的后续遍历序列.cpp
* @author jiashen
* @description 
* @created Tue Jul 24 2018 06:06:24 GMT+0800 (CST)
* @copyright 
* @last-modified Tue Jul 24 2018 06:06:25 GMT+0800 (CST)
*/

/**
 * @brief 
 * 递归法，根节点肯定是最后一个，右子树根节点是最后第二个，找到左子树根节点，在这之后如果还存在大于根节点的数，则不符合二叉搜索树的要求。
 */
class Solution {
public:
    bool VerifySquenceOfBST(vector<int> sequence) {
        if(sequence.size()==0)  return false;
        return VerifySubSquence(sequence, 0, sequence.size()-1);
    }

    bool VerifySubSquence(vector<int> sequence, int start, int end)
    {
        if(start>=end)  return true;
        int root_value = sequence[end];
        int r_idx = end-1;
        int find = false;
        int l_idx = -1;
        for(int i=end-2; i>=start; i--)
        {
            if(sequence[i]<root_value)
            {
                find = true;
                l_idx = i;
            }
            if(find && sequence[i]>root_value)
                return false;
        }
        return VerifySubSquence(sequence, start, l_idx) && VerifySubSquence(sequence, l_idx+1, r_idx);
    }
};