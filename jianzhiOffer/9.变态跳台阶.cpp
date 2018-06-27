/**
* 9.变态跳台阶.cpp
* @author jiashen
* @description 
* @created Tue Jun 26 2018 16:16:58 GMT+0800 (CST)
* @copyright 
* @last-modified Tue Jun 26 2018 16:16:59 GMT+0800 (CST)
*/

/**
 * @brief 
 * F(0) = 0, F(1) = 1, F(2) = F(0) + F(1)
 * F(N) = F(N-1) + F(N-2) + ... + F(0)
 * 迭代解法， 按动态规划的思想，也会退化为迭代。时间复杂度O(n^2)
 */
class Solution {
public:
    int jumpFloorII(int number) {
        if(number<=0) return number;
        vector<int> v_arr(number, 1);
        for(int i=0; i<number; i++)
        {
            for(int j=0; j<i; j++)
                v_arr[i] += v_arr[j];
        }
        return v_arr[number-1];
    }
};

/**
 * @brief 
 * 找规律。 这道题可以根据规律得到一个递推公式，更加简单.
 * F(0) = 0, F(1) = 1, F(2) = 2, F(3) = 1+ F(1) + F(2) = 4
 * F(n) = 2^(n-1), n>=1, F(0) = 0
 */
class Solution {
public:
    int jumpFloorII(int number) {
        if(number<=0) return number;
        int res = 0;
        res = pow(2, number-1);
        return res;
    }
};