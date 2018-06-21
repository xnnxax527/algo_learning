/**
* 二维数组中的查找.cpp
* @author jiashen
* @description 
* @created Mon Jun 18 2018 12:38:52 GMT+0800 (CST)
* @copyright 
* @last-modified Mon Jun 18 2018 12:39:37 GMT+0800 (CST)
*/

/**
 * @brief 
 * 考察题意，根据规则，从左下角开始搜索，在行方向，其右边的均比它大，其上边的均比它小.
 * 因此target如果较大，i--; target较小， j++;
 */
class Solution {
public:
    bool Find(int target, vector<vector<int>> array) {
        bool res = false;
        if( array.size() == 0 || array[0].size() == 0)
            return res;
        int rows = array.size()-1;
        int cols = array[0].size()-1;
        // from left bottom begin search.
        int i = rows; int j = 0;
        while(i >= 0 && i <= rows && j >= 0 && j <=cols)
        {
            if(target > array[i][j])
                j++;
            else if(target < array[i][j])
                i--;
            else
                // find
                return true;
        }
        return res;
    }
};