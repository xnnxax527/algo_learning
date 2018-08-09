/**
* 28. 数组中出现次数超过一半的数字.cpp
* @author jiashen
* @description 
* @created Sat Aug 04 2018 22:05:23 GMT+0800 (CST)
* @copyright 
* @last-modified Sat Aug 04 2018 22:05:24 GMT+0800 (CST)
*/

/**
 * @brief 
 * 开辟map的方法.
 */
class Solution {
public:
    int MoreThanHalfNum_Solution(vector<int> numbers) {
        if(numbers.size()==0)   return 0;
        map<int, int> num_map;
        int max_v = numbers[0]; int max_num = 1;
        num_map.insert(pair<int, int>(numbers[0], 1));
        for(int i=1; i<numbers.size(); i++)
        {
            auto it = num_map.find(numbers[i]);
            // number not in map
            if(it==num_map.end())
                num_map.insert(pair<int, int>(numbers[i], 1));
            else
                it->second +=1;
            // update max infor
            if(it->second>max_num)
            {
                max_v = it->first;
                max_num = it->second;
            }
        }
        if(max_num >= (numbers.size()/2+1))
            return max_v;
        else
            return 0;
    }
};