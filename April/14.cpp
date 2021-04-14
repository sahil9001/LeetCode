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
    ListNode* partition(ListNode* head, int x) {
        if(head==NULL) return head;
        int flag = 1;
        while(flag == 1){
            flag = 0;
            ListNode* curr = head;
            while(curr->next!=NULL){
                if(curr->val==x && curr->next->val<x){
                    int temp = curr->next->val;
                    curr->next->val = curr->val;
                    curr->val = temp;
                    flag = 1;
                }
                
                else if(curr->val>x && curr->next->val<x){
                    int temp = curr->next->val;
                    curr->next->val = curr->val;
                    curr->val = temp;
                    flag = 1;
                }
                curr = curr->next;
            }
        }
        return head;
    }
};
