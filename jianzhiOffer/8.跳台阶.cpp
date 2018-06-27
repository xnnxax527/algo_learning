/**
* 8.跳台阶.cpp
* @author jiashen
* @description 
* @created Mon Jun 25 2018 16:25:52 GMT+0800 (CST)
* @copyright 
* @last-modified Mon Jun 25 2018 16:25:52 GMT+0800 (CST)
*/

/**
 * @brief 
 * F(1) = 1, F(2) = 2, F(3) = F(1) + F(2)
 * 斐波那契数列实例，动态规划
 */
class Solution {
public:
    int jumpFloor(int number) {
        int a=1;
        int b=2;
        while(--number)
        {
            int tmp = a+b;
            a = b;
            b = tmp;
        }
        return a;
    }
};