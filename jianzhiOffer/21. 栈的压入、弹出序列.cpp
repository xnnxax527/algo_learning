/**
* 21. 栈的压入、弹出序列.cpp
* @author jiashen
* @description 
* @created Tue Jul 24 2018 05:11:15 GMT+0800 (CST)
* @copyright 
* @last-modified Tue Jul 24 2018 05:11:15 GMT+0800 (CST)
*/

/**
 * @brief 
 * 模拟法
 */
class Solution {
public:
    bool IsPopOrder(vector<int> pushV,vector<int> popV) {
        if(pushV.size()==0) return false;
        stack<int> tmp_stk;
        int j=0;
        for(int i=0; i< pushV.size(); i++)
        {
            tmp_stk.push(pushV[i]);
            while(j<popV.size() && tmp_stk.top() == popV[j])
            {
                tmp_stk.pop();
                j++;
            }
        }
        return tmp_stk.empty();
    }
};