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
 * TODO
 */