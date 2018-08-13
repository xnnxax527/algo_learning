/**
* 32. 把数组排成最小的数.cpp
* @author xnnxax
* @description 
* @created Sun Aug 12 2018 14:31:04 GMT+0800 (CST)
* @copyright Zhejiang University
* @last-modified Sun Aug 12 2018 14:31:04 GMT+0800 (CST)
*/

bool Compare(const int &a, const int &b) {
    string s1 = to_string(a) + to_string(b);
    string s2 = to_string(b) + to_string(a);
    return s1 < s2;
}

/*
 * @brief
 * 定义vector比较规则，重写vector compare函数
 * 对于a, b，排序规则:
 *        ab < ba,  a < b
 *        ab > ba,  a > b
 *        ab == ba, a = b
 */
class Solution {
public:
    string PrintMinNumber(vector<int> numbers) {
        sort(numbers.begin(), numbers.end(), Compare);
        string res = "";
        for(int i=0; i<numbers.size(); i++) {
            res += to_string(numbers[i]);
        }
        return res;
    }
};