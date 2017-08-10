/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *rotateRight(ListNode *head, int k) {
        ListNode *ptr_a = head;
        ListNode *ptr_b = head;
        ListNode *rtn_head = NULL;
        if (head==NULL || head->next== NULL)
            return head; 
        int len = 0;
        for (ListNode *p = head; p; p=p->next)
            len = len + 1;
        k = k%len;
        if (!k)
            return head;
        for (int i = 0; i < k; i++){
            ptr_b = ptr_b->next;
            if (!ptr_b)
                return head;
        }
        while (ptr_b->next){
            ptr_b = ptr_b->next;
            ptr_a = ptr_a->next;
        }
        ptr_b->next = head;
        rtn_head = ptr_a->next;
        ptr_a->next = NULL;
        return rtn_head;
    }
};