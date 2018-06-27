/**
* 12.数值的整数次方.cpp
* @author jiashen
* @description 
* @created Thu Jun 28 2018 01:08:34 GMT+0800 (CST)
* @copyright 
* @last-modified Thu Jun 28 2018 01:08:37 GMT+0800 (CST)
*/

/**
 * @brief 
 * 迭代常规解法，时间复杂度是O(n)
 * 主要考虑一些细节，1.base和exponent都为0 2.exponent小于0
 */
class Solution {
public:
    double Power(double base, int exponent) {
        // maybe it's error
        if(base==0 && exponent==0)  return 0;
        double res = 1.0;
        if(exponent<0)
        {
            base = 1.0/base;
            exponent = -exponent;
        }
        for(int i=0; i<exponent; i++)
            res = res*base;
        return res;
    }
};