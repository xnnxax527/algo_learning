/**
* 34. 第一次只出现一次的字符.cpp
* @author xnnxax
* @description 
* @created Sun Aug 12 2018 15:56:19 GMT+0800 (CST)
* @copyright Zhejiang University
* @last-modified Sun Aug 12 2018 15:56:19 GMT+0800 (CST)
*/


class Solution {
public:
    int FirstNotRepeatingChar(string str) {
        map<char, int> map_;
        for(int i=0; i<str.size(); i++)
            map_[str[i]]++;
        for(int i=0; i<str.size(); i++) {
            if(map_[str[i]] == 1)
                return i;
        }
        return -1;
    }
};