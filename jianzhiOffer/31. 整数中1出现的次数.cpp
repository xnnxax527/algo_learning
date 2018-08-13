/**
* 31. 整数中1出现的次数.cpp
* @author xnnxax
* @description 
* @created Sat Aug 11 2018 22:56:55 GMT+0800 (CST)
* @copyright Zhejiang University
* @last-modified Sat Aug 11 2018 22:56:56 GMT+0800 (CST)
*/

/*
 * @brief
 * 暴力法，每个数字按位考虑
 */
class Solution {
public:
    int NumberOf1Between1AndN_Solution(int n)
    {
        int total_nums = 0;
        for(int i=1; i<=n; i++)
        {
            int k = i;
            while(k) {
                if(k%10 == 1)   total_nums++;
                k = k/10; 
            }
        }
        return total_nums;
    }
};

/*
 * @brief
 * 找规律，按位考虑，分析每位为0/1/>=1三种情况
 */
class Solution {
public:
    int NumberOf1Between1AndN_Solution(int n)
    {
        int count = 0;
        for(int i = 1; i <= n; i *= 10) {
            int h = n / i; int l = n % i;
            int curr = h%10;
            if(curr == 0) {
                count += h/10 * i;
            } else if(curr == 1) {
                count += h/10 * i + l+1;
            } else {
                count += (h/10 + 1) * i;
            }
        }
        return count;
    }
};