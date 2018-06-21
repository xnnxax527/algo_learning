/**
* 5.用两个栈来实现队列.cpp
* @author jiashen
* @description 
* @created Fri Jun 22 2018 00:24:13 GMT+0800 (CST)
* @copyright 
* @last-modified Fri Jun 22 2018 00:24:24 GMT+0800 (CST)
*/

/**
 * @brief 
 * 基本解法1, 适合pop操作较多的情况，push: O(n), pop: O(1)
 * 在push的时候维护处理, stack1一直维护top->bottom == front->behind.
 */
class Solution
{
public:
    // push is O(n)
    void push(int node) {
        while(!stack1.empty())
        {
            stack2.push(stack1.top());
            stack1.pop();
        }
        // add new value to the end.
        stack2.push(node);
        // put back to stack1. top is front, bottom is behind.
        while(!stack2.empty())
        {
            stack1.push(stack2.top());
            stack2.pop();
        }
    }
    // pop is O(1)
    int pop() {
        int res;
        if(stack1.empty())  return res;
        res = stack1.top();
        stack1.pop();
        return res;
    }

private:
    stack<int> stack1;
    stack<int> stack2;
};

/**
 * @brief 
 * 基本解法2， 适合push较多的情况， push:O(1), pop: O(n)
 * 在pop的时候才考虑，stack1一直维护top->bottom == behind->front.
 */
class Solution
{
public:
    void push(int node) {
        stack1.push(node);
    }

    int pop() {
        int res;
        if(stack1.empty())  return res;
        while(!stack1.empty())
        {
            stack2.push(stack1.top());
            stack1.pop();
        }
        // get front value;
        res = stack2.top();
        stack2.pop();
        while(!stack2.empty())
        {
            stack1.push(stack2.top());
            stack2.pop();
        }
        return res;
    }

private:
    stack<int> stack1;
    stack<int> stack2;
};

/**
 * @brief 
 * 基本解法3， 比较lazy的做法，不是死板的维护在一个stack中，而是根据操作有需要的时候移动.
 * 该方法适合频繁的相同操作，此时复杂度为O(1), 每次切换造成时间复杂度上代价为O(n).
 */
class Solution
{
public:
    void push(int node) {
        if(stack1.empty())
        {
            while(!stack2.empty())
            {
                stack1.push(stack2.top());
                stack2.pop();
            }
            stack1.push(node);
        }
        else
            stack1.push(node);
    }
    int pop() {
        int res;
        if(stack1.empty() && !stack2.empty())
        {
            res = stack2.top();
            stack2.pop();
        }
        else if(!stack1.empty() && stack2.empty())
        {
            while(!stack1.empty())
            {
                stack2.push(stack1.top());
                stack1.pop();
            }
            res = stack2.top();
            stack2.pop();
        }
        return res;
    }

private:
    stack<int> stack1;
    stack<int> stack2;
};
