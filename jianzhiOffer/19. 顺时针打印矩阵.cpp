/**
* 19. 顺时针打印矩阵.cpp
* @author jiashen
* @description 
* @created Mon Jul 23 2018 13:30:17 GMT+0800 (CST)
* @copyright 
* @last-modified Mon Jul 23 2018 13:30:18 GMT+0800 (CST)
*/

/**
 * @brief 
 * 一圈一个规律打印，排除重复打印的情况
 */
class Solution {
public:
    vector<int> printMatrix(vector<vector<int>> matrix) {
        vector<int> res;
        int rows = matrix.size();
        int cols = matrix[0].size();
        int count = 0;
        while(2*count<min(rows, cols))
        {
            int j = 0+count;
            // left to right
            for(int i=0+count; i<cols-count; i++)
                res.push_back(matrix[j][i]);
            // top to down
            j = cols-count-1;
            for(int i=1+count; i<rows-count; i++)
                res.push_back(matrix[i][j]);
            if(rows-2*count != 1)
            {
                // right to left
                j = rows-count-1;
                for(int i=cols-count-2; i>=0+count; i--)
                res.push_back(matrix[j][i]);
            }
            if(cols-2*count !=1)
            {
                // down to top
                j = 0+count;
                for(int i=rows-count-2; i>0+count; i--)
                res.push_back(matrix[i][j]);
            }
            count++;
        }
        return res;
    }
};