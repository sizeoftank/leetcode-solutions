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
ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
    int lenA,lenB;
    ListNode* p;
    if (headA==NULL || headB==NULL)
        return NULL;
    lenA = 0;
    for (p = headA; p->next != NULL; p = p->next) {
        lenA++;
    }
    lenB = 0;
    for (p = headB; p->next != NULL; p = p->next) {
        lenB++;
    }
    ListNode* pa = headA;
    ListNode* pb = headB;
    if (lenA > lenB) {
        int n = lenA - lenB;
        for (int i = 0; i < n; i++){
            pa = pa->next;
        }
    }
    else if (lenB > lenA) {
        int n = lenB - lenA;
        for (int i = 0; i < n; i++){
            pb = pb->next;
        }
    }
    while (pa != pb){
        pa = pa->next;
        pb = pb->next;
    }
    return pa;
}
public:
    ListNode *detectCycle(ListNode *head) {
        ListNode* p1;
        ListNode* p2;
        ListNode* cut;
        if (!head || !head->next)
            return NULL;
        p1 = head;
        p2 = head->next;
        while (p1 && p2 && p2->next){
            if (p2->next==p1 || p2==p1)
            {
                cut = p1->next;
                ListNode* a = head;
                ListNode* b = p1->next;
                p1->next = NULL;
                ListNode *inter = getIntersectionNode(a, b);
                return inter;                
            }
            p1 = p1->next;
            p2 = p2->next->next;
        }
        return NULL;
    }
};