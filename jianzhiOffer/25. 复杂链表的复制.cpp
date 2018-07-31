/**
* 25. 复杂链表的复制.cpp
* @author jiashen
* @description 
* @created Wed Aug 01 2018 00:53:29 GMT+0800 (CST)
* @copyright 
* @last-modified Wed Aug 01 2018 00:53:29 GMT+0800 (CST)
*/

/*
struct RandomListNode {
    int label;
    struct RandomListNode *next, *random;
    RandomListNode(int x) :
            label(x), next(NULL), random(NULL) {
    }
};
*/

/**
 * @brief 
 * 1. 先拷贝整个元素，分别接于对应元素后面，先不考虑random, 比如A->B->C to A->A'->B->B'->C->C'
 * 2. 遍历链表，关联random元素， A'->random = A->random->next;
 * 3. 拆分两个链表, A->A'->B to A->B, A'
 */
class Solution {
public:
    RandomListNode* Clone(RandomListNode* pHead)
    {
        if(pHead==NULL) return NULL;
        RandomListNode* currHead = pHead;
        while(currHead)
        {
            // currHead at A, A->B
            // to A->A_copy->B, currHead to B
            RandomListNode* node = new RandomListNode(currHead->label);
            node->next = currHead->next;
            currHead->next = node;
            currHead = node->next;
        }
        currHead = pHead;
        while(currHead)
        {
            if(currHead->random)
                currHead->next->random = currHead->random->next;
            currHead = currHead->next->next;
        }
        RandomListNode* cloneHead = pHead->next;
        RandomListNode* tmp;
        currHead = pHead;
        while(currHead->next)
        {
            tmp = currHead->next;
            currHead->next = tmp->next;
            currHead = tmp;
        }
        return cloneHead;
    }
};