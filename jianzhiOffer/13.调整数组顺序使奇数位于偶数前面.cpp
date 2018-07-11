/**
* 13.调整数组顺序使奇数位于偶数前面.cpp
* @author jiashen
* @description 
* @created Thu Jun 28 2018 01:17:54 GMT+0800 (CST)
* @copyright 
* @last-modified Thu Jun 28 2018 01:17:54 GMT+0800 (CST)
*/

/**
 * @brief 
 * 冒泡排序的应用
 * 因为是稳定的，所以考虑排序中的方法，冒泡是稳定的，如何稳定？只有左边大于右边才交换，在这里是左边是偶数，右边是奇数才交换.
 * 复杂度是O(n^2)
 */
class Solution {
public:
    void reOrderArray(vector<int> &array) {
        for(int i=array.size()-1; i>=1; i--)
            for(int j=0; j<i; j++)
                if(array[j]%2==0 && array[j+1]%2!=0)
                    swap(array[j], array[j+1]);
    }
};

/**
 * @brief 
 * 新开临时数组的方法
 * 时间复杂度是O(3n), 空间开销是O(n)
 */

class Solution {
public:
    void reOrderArray(vector<int> &array) {
        int odds = 0;
        for(int i=0; i<array.size(); i++)
            if(array[i]%2)  odds++;
        vector<int> tmp_arr(array.size(), 0);
        int i=0; int j= odds;
        for(int k=0; k<array.size(); k++)
        {
            if(array[k]%2)  tmp_arr[i++] = array[k];
            else    tmp_arr[j++] = array[k];
        }
        for(int i=0; i<array.size(); i++)
            array[i] = tmp_arr[i];
    }
};