/**
* 29. 最小的K个数.cpp
* @author jiashen
* @description 
* @created Sat Aug 04 2018 22:43:34 GMT+0800 (CST)
* @copyright 
* @last-modified Sat Aug 04 2018 22:43:44 GMT+0800 (CST)
*/

/**
 * @brief 
 * 先排序，后取，复杂度O(nlogn)
 */
class Solution {
public:
    vector<int> GetLeastNumbers_Solution(vector<int> input, int k) {
        vector<int> res;
        if(input.empty() || k>input.size()) return res;
        sort(input.begin(), input.end());
        for(int i=0; i<k; i++)
            res.push_back(input[i]);
        return res;
    }
};



/**
 * @brief 
 * 基于最大堆实现， 好处是只需要维护k大小的数组，在处理海量数据时很节省存储空间
 * 思路： 先堆对input[0-k-1]构建最大堆，后遍历[k-input.size()]，如果小于堆顶元素，就剔除堆顶元素，将新元素放在根节点，对根节点重新进行最大堆的构建
 * 这样可以保证最后最小的k个数在堆里，之后按堆排序的思想，输出排序的结构.
 */
class Solution {
public:
    vector<int> GetLeastNumbers_Solution(vector<int> input, int k) {
        vector<int> heap;
        if(input.empty() || k<=0 || input.size() < k) return heap;
        for(int i=0; i<k; i++)
        {
            heap.push_back(input[i]);
        }
        for(int i=k/2-1; i>=0; i--) {
            buildMaxHeap(heap, i, k);
        }
        for(int m=k; m<input.size(); m++) {
            if(input[m] < heap[0])
            {
                swap(input[m], heap[0]);
                buildMaxHeap(heap, 0, k);
            }
        }
        for(int i=k-1; i>=0; i--)
        {
            swap(heap[0], heap[i]);
            buildMaxHeap(heap, 0, i);
        }
        return heap;
    }
    void buildMaxHeap(vector<int> &vec, int i, int size) {
        int child = 2 * i + 1;
        while(child < size)
        {
            if(child + 1 < size && vec[child + 1] > vec[child])
                child++;
            if(vec[i] < vec[child]) {
                swap(vec[i], vec[child]);
                i = child;
                child = 2 * i + 1;
            }
            else
                break;
        }

    }
};

/**
 * @brief 
 * 基于快速排序的partition的思想，找到partition点，左边的就是topK.
 */
class Solution {
public:
    vector<int> GetLeastNumbers_Solution(vector<int> input, int k) {
        vector<int> res;
        if(input.size() == 0 || input.size() < k || k<=0)   return res;
        int start = 0;
        int end = input.size()-1;
        int index = Partition(input, start, end);
        while(index != k-1) {
            if(index < k-1) {
                start = index + 1;
                index = Partition(input, start, end);
            } else {
                end = index - 1;
                index = Partition(input, start, end);
            }
        }
        for(int i=0; i<k; i++) {
            res.push_back(input[i]);
        }
        // sort(res.begin(), res.end());
        return res;
    }
    int Partition(vector<int> &vec, int start, int end) {
        int privot = vec[end];
        int nums = start;
        for(int i = start; i < end; i++)
        {
            if(vec[i] < privot) {
                swap(vec[i], vec[nums]);
                nums++;
            }
        }
        swap(vec[nums], vec[end]);
        return nums;
    }
};
