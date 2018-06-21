/**
* 2.替换空格.cpp
* @author jiashen
* @description 
* @created Mon Jun 18 2018 21:28:05 GMT+0800 (CST)
* @copyright 
* @last-modified Mon Jun 18 2018 21:28:05 GMT+0800 (CST)
*/

/**
 * @brief 
 * 从前往后计算' '数量，从后往前替换，替换位置与' '数量相关. 
 */
class Solution {
public:
	void replaceSpace(char *str,int length) {
        int cnt = 0;
        for(int i=0; i<length; i++)
        {
            if(str[i] == ' ')
                cnt++;
        }
        for(int i=length-1; i>=0; i--)
        {
            if(str[i] != ' ')
                str[i+2*cnt] = str[i];
            else
            {
                cnt--;
                str[i+2*cnt] = '%';
                str[i+2*cnt+1] = '2';
                str[i+2*cnt+2] = '0'; 
            }
        }
        return;
	}
};