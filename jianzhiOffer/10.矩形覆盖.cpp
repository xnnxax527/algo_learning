/**
* 10.矩形覆盖.cpp
* @author jiashen
* @description 
* @created Tue Jun 26 2018 16:34:21 GMT+0800 (CST)
* @copyright 
* @last-modified Tue Jun 26 2018 16:34:22 GMT+0800 (CST)
*/

/**
 * @brief 
 * 斐波那契数列变种的应用，直接给出动态规划的解法. 要注意横竖是不一样的
 * 分析规律， F(0) = 0, F(1) = 1, F(2) = 2, F(3) = 3, F(N) = F(N-1) + F(N-2)
 * 
 */
class Solution {
public:
    int rectCover(int number) {
        if(number<=1)   return number;
        int a = 1;
        int b = 2;
        while(--number)
        {
            int tmp = b;
            b = a+b;
            a = tmp;
        }
        return a;
    }
};