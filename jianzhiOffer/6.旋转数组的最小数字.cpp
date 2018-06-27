/**
* 6.旋转数组的最小数字.cpp
* @author jiashen
* @description 
* @created Mon Jun 25 2018 13:16:43 GMT+0800 (CST)
* @copyright 
* @last-modified Mon Jun 25 2018 13:16:43 GMT+0800 (CST)
*/

/**
 * @brief 
 * 暴力做法，直接遍历，时间复杂度是O(n)
 */
class Solution {
public:
    int minNumberInRotateArray(vector<int> rotateArray) {
        int nums = rotateArray.size();
        if(nums==0) return 0;
        for(int i=1; i<nums; i++)
        {
            if(rotateArray[i]<rotateArray[0])
                return rotateArray[i];
        }
        return rotateArray[0];
    }
};

/**
 * @brief 
 * 二分法，因为非递减，所以相等的时候需要遍历. 时间复杂度O(logn)
 */
class Solution {
public:
    int minNumberInRotateArray(vector<int> rotateArray) {
        int nums = rotateArray.size();
        if(nums==0) return 0;
        int start = 0; int end = nums-1;
        while(start<end)
        {
            int mid = start + (end-start)/2;
            // must in (mid, end]
            if(rotateArray[mid]>rotateArray[end])
                start = mid+1;
            // can't determained
            else if(rotateArray[mid]==rotateArray[end])
                end = end-1;
            // must in [start, mid]
            else if(rotateArray[mid]<rotateArray[end])
                end = mid;
        }
        return rotateArray[start];
    }
};