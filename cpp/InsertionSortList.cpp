class Solution {
public:
    ListNode *insertionSortList(ListNode *head) {
        if (head==NULL || head->next==NULL)
            return head;
        ListNode* headList = new ListNode(1<<(sizeof(int)*8-1));
        headList->next = head;
        ListNode* previousNode = head;
        while (previousNode->next){
            ListNode* insertNode = previousNode->next;
            ListNode* insertPosPrev = headList;
            bool flag = false;
            while (insertPosPrev->next != insertNode){
                if (insertPosPrev->next->val > insertNode->val ){
                    previousNode->next = insertNode->next;
                    insertNode->next = insertPosPrev->next;
                    insertPosPrev->next = insertNode;
                    flag = true;
                    break;
                }
                insertPosPrev = insertPosPrev->next;
            }
            if (!flag)
                previousNode = previousNode->next;
        }
        return headList->next;
    }
};