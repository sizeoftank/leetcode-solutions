class Solution {
public:
    static ListNode *quickSort(ListNode *head, ListNode *end){
        if (head->next==NULL || head->next->next == NULL || head->next==end)
            return NULL;
        ListNode *ptr = head->next;
        ListNode *pivot = head->next;
        ListNode *pivot_tail = head->next;
        while (ptr->next != end) {
            ListNode *node = ptr->next;
            if (node->val < pivot->val){
                ptr->next = node->next;
                node->next = head->next;
                head->next = node;
            }
            else if (node->val == pivot->val && pivot_tail==ptr){
                ptr = ptr->next;
                pivot_tail = pivot_tail->next;
            }
            else{
                ptr = ptr->next;
            }
        }
        quickSort(head, pivot);
        quickSort(pivot_tail, end);
        return head;
    }


    static ListNode *sortList(ListNode *head) {
        ListNode * head_list = new ListNode(0);
        head_list->next = head;
        quickSort(head_list, (ListNode*) NULL);
        return head_list->next;
    }
};
