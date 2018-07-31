/**
* 20. 包含min函数的栈.cpp
* @author jiashen
* @description 
* @created Mon Jul 23 2018 15:49:00 GMT+0800 (CST)
* @copyright 
* @last-modified Mon Jul 23 2018 15:49:01 GMT+0800 (CST)
*/

/**
 * @brief 
 * 辅助栈存储栈数据的最小值
 */
class Solution {
public:
    stack<int> stk;
    stack<int> min_stk;
    void push(int value) {
        stk.push(value);
        if(min_stk.empty() || (!min_stk.empty() && value<=min_stk.top()))
            min_stk.push(value);
    }
    void pop() {
        int v = stk.top();
        stk.pop();
        if(v == min_stk.top())
            min_stk.pop();
    }
    int top() {
        return stk.top();
    }
    int min() {
        return min_stk.top();
    }
};