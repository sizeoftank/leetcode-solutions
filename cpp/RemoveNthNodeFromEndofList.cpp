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
    ListNode *removeNthFromEnd(ListNode *head, int n) {
        ListNode *ptr_a = head;
        ListNode *ptr_b = head;
        if (head==NULL || head->next == NULL)
            return NULL;
        for (int i = 0; i < n; i++){
            ptr_b = ptr_b->next;
        }
        if (ptr_b==NULL){
            return head->next;
        }
        while (ptr_b->next){
            ptr_b = ptr_b->next;
            ptr_a = ptr_a->next;
        }

        ptr_a->next = ptr_a->next->next;
        return head;
    }
};