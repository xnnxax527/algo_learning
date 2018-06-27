/**
* 11.二进制中1的个数.cpp
* @author jiashen
* @description 
* @created Thu Jun 28 2018 00:42:56 GMT+0800 (CST)
* @copyright 
* @last-modified Thu Jun 28 2018 00:42:57 GMT+0800 (CST)
*/

/**
 * @brief 
 * 考虑负数是补码表示，即负数的补码就是2^32与负数的和, 111...111 - 负数的原码
 * 因此只需要新建一个long数为2^32, 如果为非负数，直接取n， 反之取2^32+n.
 * 剩下的就是移位按位与.
 */
class Solution {
public:
     int  NumberOf1(int n) {
        long num = (n>=0)?n:(pow(2,32)+n);
        int res = 0;
        while(num)
        {
            if(num&1)
                res++;
            num = num >> 1;
        }
        return res;
     }
};

/**
 * @brief 
 * 更好的解法？
 */