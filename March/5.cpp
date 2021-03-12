/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution
{
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB)
    {
        ListNode *trav = headA;
        ListNode *trav1 = headB;
        int len = 0, len1 = 0;
        while (trav1)
        {
            len1++;
            trav1 = trav1->next;
        }
        while (trav)
        {
            len++;
            trav = trav->next;
        }
        if (len < len1)
        {
            int k = len1 - len;
            while (k--)
            {
                headB = headB->next;
            }
            cout << headB->val << " " << headA->val << endl;
            while (headA != headB)
            {
                headA = headA->next;
                headB = headB->next;
            }
            return headA;
        }
        else
        {
            int k = len - len1;
            while (k--)
            {
                headA = headA->next;
            }
            while (headA != headB)
            {
                headA = headA->next;
                headB = headB->next;
            }
            return headA;
        }
    }
};