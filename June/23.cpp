/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* reverse(ListNode* head)
{
    ListNode* prev = NULL;   
    ListNode* curr = head;
 
    while (curr) {
        ListNode* next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    return prev;
}

    ListNode* reverseBetween(ListNode* head, int left, int right) {
        ListNode* revs = NULL;
        ListNode* revs_prev = NULL;
        ListNode* revend = NULL;
        ListNode* revend_next = NULL;
        ListNode* curr = head;
        if(left == right) return head;
        int i = 1;
        while(curr && i<=right){
            if(i<left){
                revs_prev = curr;
            }
            if(i==left){
                revs = curr;
            }
            if(i==right){
                revend = curr;
                revend_next = curr->next;
            }
            curr = curr->next;
            i++;
        }
        revend->next = NULL;
        revend = reverse(revs);
        if(revs_prev){
            revs_prev->next = revend;
        }
        else head = revend;
        revs->next = revend_next;
        return head;
    }
};
