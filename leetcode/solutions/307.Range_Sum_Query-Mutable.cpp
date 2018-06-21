/**
* 307.Range Sum Query - Mutable.cpp
* @author jiashen
* @description 
* @created Mon Jun 18 2018 18:02:07 GMT+0800 (CST)
* @copyright 
* @last-modified Mon Jun 18 2018 18:02:19 GMT+0800 (CST)
*/

/**
 * @brief 
 * 根据查询和更新的频率，考虑三种情况:
 * 1. 多查询 - 查询 >> 更新， 此时考虑存储的是各区间和的结果，查询时间复杂度是O(1), 更新时间复杂度是0(n)
 * 2. 多更新 - 更新 >> 查询， 此时考虑存储的是原数组的值， 查询时间复杂度是O(n)， 更新时间复杂度是O(1)
 * 3. 查询与更新等价， 此时考虑Segment Tree(线段树)， 查询和更新的复杂度都是O(logn)
 */


/**
 * @brief 
 * Naive Approach. time complex sum: O(n), update: O(1). top70.61%
 */
class NumArray {
public:
    NumArray(vector<int> nums) {
        arr = nums;
    }
    
    void update(int i, int val) {
        if(i>=0 && i<arr.size())
            arr[i] = val;
    }
    
    int sumRange(int i, int j) {
        int sum_res = 0;
        if(i>=0 && i<arr.size() && j>=i && j<arr.size())
        {
            for(int k=i; k<=j; k++)
                sum_res += arr[k];
        }
        return sum_res;
    }
private:
    vector<int> arr;
};

/**
 * @brief 
 * TODO: Solution based on segment tree.
 */
