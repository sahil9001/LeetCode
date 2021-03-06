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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if(head==NULL) return head;
        ListNode* curr = head;
        int len = 0;
        while(curr!=NULL){
            curr = curr->next;
            len++;
        }
        curr = head;
        if(len == 1) return NULL;
        if(len == n) {
            head = head->next;
            return head;
        }
        for(int i=0;i<len-n-1;i++){
             curr = curr->next;
        }
        curr->next= curr->next->next;
        return head;
    }
};
