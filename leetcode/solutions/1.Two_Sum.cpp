/**
* 1.Two_Sum.cpp
* @author jiashen
* @description 
* @created Sat Jun 16 2018 17:38:37 GMT+0800 (CST)
* @copyright 
* @last-modified Sat Jun 16 2018 17:38:37 GMT+0800 (CST)
*/

/**
 * @brief 
 * 思路：用hash_map存储数组index, 遍历数组，在map中搜索target-nums[i]， hashmap find复杂度O(1)
 * using hashmap, time complex O(n), speed 9ms top92.29%
 */
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> hash_map;
        for(int i=0; i<nums.size(); i++)
            hash_map[nums[i]] = i;
        vector<int> res;
        for(int i=0; i<nums.size(); i++)
        {
            int sub_t = target - nums[i];
            auto it = hash_map.find(sub_t);
            if( it != hash_map.end() && it->second != i)
            {
                res.push_back(i);
                res.push_back(it->second);
                break;
            }
        }
        return res;
    }
};