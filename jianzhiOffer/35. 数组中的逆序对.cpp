/**
* 35. 数组中的逆序对.cpp
* @author xnnxax
* @description 
* @created Sun Aug 12 2018 16:03:41 GMT+0800 (CST)
* @copyright Zhejiang University
* @last-modified Sun Aug 12 2018 16:03:41 GMT+0800 (CST)
*/

/*
 * @brief
 * 遍历，复杂度太高
 */
class Solution {
public:
    int InversePairs(vector<int> data) {
        long long count = 0;
        for(int i=0; i<data.size(); i++) {
            for(int j=i+1; j<data.size(); j++) {
                if(data[i] > data[j])
                    count++;
            }
        }
        return (int)(count%1000000007);
    }
};