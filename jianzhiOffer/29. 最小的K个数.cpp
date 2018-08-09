/**
* 29. 最小的K个数.cpp
* @author jiashen
* @description 
* @created Sat Aug 04 2018 22:43:34 GMT+0800 (CST)
* @copyright 
* @last-modified Sat Aug 04 2018 22:43:44 GMT+0800 (CST)
*/

/**
 * @brief 
 * 先排序，后取，复杂度O(nlogn)
 */
class Solution {
public:
    vector<int> GetLeastNumbers_Solution(vector<int> input, int k) {
        vector<int> res;
        if(input.empty() || k>input.size()) return res;
        sort(input.begin(), input.end());
        for(int i=0; i<k; i++)
            res.push_back(input[i]);
        return res;
    }
};