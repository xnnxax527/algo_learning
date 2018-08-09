/**
* 27. 字符串的排列.cpp
* @author jiashen
* @description 
* @created Sat Aug 04 2018 16:15:32 GMT+0800 (CST)
* @copyright 
* @last-modified Sat Aug 04 2018 16:15:32 GMT+0800 (CST)
*/

/**
 * @brief 
 * 全排列问题，标准解法，交换遍历第k位可能的字符.
 */
class Solution {
public:
    vector<string> Permutation(string str) {
        vector<string> res;
        PermutationHelp(res, 0, str);
        return res;
    }
    void PermutationHelp(vector<string>& res, int k, string str)
    {
        if( k== str.size()-1 )  res.push_back(str);
        unordered_set<char> us;
        // fro zidian xu
        sort(str.begin()+k, str.end());
        for(int i=k; i<str.size(); i++)
        {
            if(us.find(str[i]) == us.end())
            {
                us.insert(str[i]);
                swap(str[i], str[k]);
                PermutationHelp(res, k+1, str);
                swap(str[i], str[k]); //fuwei
            }
        }
    }
};