/**
* 3.从头到尾打印链表.cpp
* @author jiashen
* @description 
* @created Tue Jun 19 2018 00:22:55 GMT+0800 (CST)
* @copyright 
* @last-modified Tue Jun 19 2018 00:22:57 GMT+0800 (CST)
*/


/**
*  struct ListNode {
*        int val;
*        struct ListNode *next;
*        ListNode(int x) :
*              val(x), next(NULL) {
*        }
*  };
*/

/**
 * @brief 
 * 基于栈的解决思路，先压入栈，再存入vector.
 */
class Solution {
public:
    vector<int> printListFromTailToHead(ListNode* head) {
        stack<int> stk;
        vector<int> res;
        while(head)
        {
            stk.push(head->val);
            head = head->next;
        }
        while(!stk.empty())
        {
            res.push_back(stk.top());
            stk.pop();
        }
        return res;
    }
};

/**
 * @brief 
 * 解决思路2:反转链表输出
 * 先反转链表，然后遍历，O(2n)复杂度
 */

class Solution {
public:
    vector<int> printListFromTailToHead(ListNode* head) {
        ListNode* pre = NULL;
        ListNode* next = NULL;
        ListNode* curr = head;
        // reverse the list, after reverse, the head is in pre.
        while(curr)
        {
            next = curr->next;
            curr->next = pre;
            pre = curr;
            curr = next;
        }
        vector<int> res;
        while(pre)
        {
            res.push_back(pre->val);
            pre = pre->next;
        }
        return res;
    }
};