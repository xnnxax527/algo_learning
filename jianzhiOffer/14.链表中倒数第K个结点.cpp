/**
* 14.链表中倒数第K个结点.cpp
* @author jiashen
* @description 
* @created Wed Jul 11 2018 16:44:56 GMT+0800 (CST)
* @copyright 
* @last-modified Wed Jul 11 2018 16:44:56 GMT+0800 (CST)
*/

/*
struct ListNode {
	int val;
	struct ListNode *next;
	ListNode(int x) :
			val(x), next(NULL) {
	}
};*/

/**
 * @brief 
 * 采用双指针，指针A指向最终要输出的倒数第K个结点，指针B指向最后的结点，显然指针B走K-1, 形成距离为K-1的双指针
 */
class Solution {
public:
    ListNode* FindKthToTail(ListNode* pListHead, unsigned int k) {
        if(!pListHead)  return NULL;
        ListNode* delay_ptr = pListHead;
        ListNode* end_ptr = pListHead;
        // make k-1 decay
        for(int i=0; i<k-1; i++)
        {
            end_ptr = end_ptr->next;
            // 要注意判断能不能走K步，不能直接返回null, 不然会报错
            if(!end_ptr)    return NULL;
        }
        while(end_ptr->next)
        {
            end_ptr = end_ptr->next;
            delay_ptr = delay_ptr->next;
        }
        return delay_ptr;
    }
};