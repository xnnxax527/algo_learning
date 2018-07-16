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