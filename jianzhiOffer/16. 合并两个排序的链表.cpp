/**
* 16. 合并两个排序的链表.cpp
* @author jiashen
* @description 
* @created Wed Jul 11 2018 17:10:13 GMT+0800 (CST)
* @copyright 
* @last-modified Wed Jul 11 2018 17:10:13 GMT+0800 (CST)
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
 * 非递归解法
 */
class Solution {
public:
    ListNode* Merge(ListNode* pHead1, ListNode* pHead2)
    {
        ListNode* head = new ListNode(0);
        ListNode* curr  = head;
        while(pHead1&&pHead2)
        {
            if(pHead1->val < pHead2->val)
            {
                curr->next = pHead1;
                curr = curr->next;
                pHead1 = pHead1->next;
            }
            else
            {                
                curr->next = pHead2;
                curr = curr->next;
                pHead2 = pHead2->next;    
            }
        }
        curr->next = (pHead1)?pHead1:pHead2;
        return head->next;
    }
};


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
 * 递归解法
 * 不需要额外开辟空间
 */
class Solution {
public:
    ListNode* Merge(ListNode* pHead1, ListNode* pHead2)
    {
        if(pHead1 == NULL)
            return pHead2;
        if(pHead2 == NULL)
            return pHead1;
        if(pHead1->val<pHead2->val)
        {
            pHead1->next = Merge(pHead1->next, pHead2);
            return pHead1;
        }
        else
        {
            pHead2->next = Merge(pHead1, pHead2->next);
            return pHead2;
        }
    }
};