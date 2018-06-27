/**
* 7.斐波那契数列.cpp
* @author jiashen
* @description 
* @created Mon Jun 25 2018 15:44:34 GMT+0800 (CST)
* @copyright 
* @last-modified Mon Jun 25 2018 15:44:35 GMT+0800 (CST)
*/

/**
 * @brief 
 * 递归，复杂度过大不能通过，重复计算浪费
 */
class Solution {
public:
    int Fibonacci(int n) {
        if(n<=1)    return n;
        return Fibonacci(n-1)+Fibonacci(n-2);
    }
};

/**
 * @brief 
 * 迭代， 额外开辟了一个数组， 空间浪费
 */
class Solution {
public:
    int Fibonacci(int n) {
        if(n<=1)    return n;
        else{
            vector<int> v_arr(n+1, 0);
            v_arr[0]=0;
            v_arr[1]=1;
            for(int i=2; i<n+1; i++)
                v_arr[i] = v_arr[i-1]+v_arr[i-2];
            return v_arr[n];
        }
    }
};

/**
 * @brief 
 * 动态规划，只维护2个int表示F[n], F[n-1]，避免空间开销.
 */
class Solution {
public:
    int Fibonacci(int n) {
        int a=0;
        int b=1;
        while(n--)
        {
            int tmp = a+b;
            a = b;
            b = tmp;
        }
        return a;
    }
};