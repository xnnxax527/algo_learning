/**
* 15.反转链表.cpp
* @author jiashen
* @description 
* @created Wed Jul 11 2018 16:58:26 GMT+0800 (CST)
* @copyright 
* @last-modified Wed Jul 11 2018 16:58:26 GMT+0800 (CST)
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
 * 反转链表，非常经典的题，维护pre, curr, next三个指针，每次翻转单个结点.
 */
class Solution {
public:
    ListNode* ReverseList(ListNode* pHead) {
        if(!pHead)  return NULL;
        ListNode* pre = NULL;
        ListNode* curr = pHead;
        ListNode* next = NULL;
        while(curr)
        {
            next = curr->next;
            curr->next = pre;
            pre = curr;
            curr = next;
        }
        return pre;
    }
};