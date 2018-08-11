/**
* 30. 连续子数组的最大和.cpp
* @author jiashen
* @description 
* @created Mon Aug 06 2018 23:29:05 GMT+0800 (CST)
* @copyright 
* @last-modified Mon Aug 06 2018 23:29:05 GMT+0800 (CST)
*/

/*
 * @brief 
 * 动态规划，这里的sum[i]指以i为结尾(取到这个数的)的最大和，
 * sum_[i+1] = max(sum_[i]+array[i+1], array[i+1])， 必然要取到最后这个数，最后在遍历所有的sum_
 */
class Solution {
public:
    int FindGreatestSumOfSubArray(vector<int> array) {
        if(array.size() == 0)   return 0;
        vector<int> sum_(array.size(), -1);
        sum_[0] = array[0];
        int max_res = sum_[0];
        for(int i=1; i<array.size(); i++)
        {
                sum_[i] = max(sum_[i-1]+array[i], array[i]);
                max_res = max(max_res, sum_[i]);
        }
        return max_res;
    }
};