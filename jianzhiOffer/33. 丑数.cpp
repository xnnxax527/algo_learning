/**
* 33. 丑数.cpp
* @author xnnxax
* @description 
* @created Sun Aug 12 2018 14:36:59 GMT+0800 (CST)
* @copyright Zhejiang University
* @last-modified Sun Aug 12 2018 14:36:59 GMT+0800 (CST)
*/

/*
 *
 * @brief
 * 遍历法，复杂度太大
 */
class Solution {
public:
    int GetUglyNumber_Solution(int index) {
        if(index == 1)  return 1;
        int count = 1;
        int number = 1;
        while(count < index) {
            number++;
            if(isUgly(number))
                count++;
        }
        return number;
    }
    bool isUgly(int num) {
        while(num%2 == 0)
            num = num/2;
        while(num%3 == 0)
            num = num/3;
        while(num%5 == 0)
            num = num/5;
        return (num == 1)?true:false;
    }
};

/*
 * @brief
 * 空间换时间，丑数总是由丑数*(2/3/5)得到，因此可以从之前丑数得到新的丑数，省去不是丑数部分的运算.
 * 这里idx_2, idx_3, idx_5表示的意思是考虑三个序列，分别是包含2, 3, 5的丑数序列。
 * 每次只要在三种到当前位置的丑数哪个最小插入就好。 idx代表了包含这个2/3/5的丑数中这些数字的数量
 */
class Solution {
public:
    int GetUglyNumber_Solution(int index) {
        if(index < 7)   return index;
        vector<int> res(index, -1);
        res[0] = 1;
        int idx_2 = 0; int idx_3 = 0; int idx_5 = 0;
        for(int i=1; i<index; i++) {
            res[i] = min(res[idx_2] * 2, min(res[idx_3] * 3, res[idx_5] * 5));
            if(res[i] == res[idx_2] * 2)  idx_2++;
            if(res[i] == res[idx_3] * 3)  idx_3++;
            if(res[i] == res[idx_5] * 5)  idx_5++;
        }
        return res[index-1];
    }
};