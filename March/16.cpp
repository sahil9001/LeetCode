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
class Solution
{
public:
    ListNode *swapNodes(ListNode *head, int k)
    {
        vector<int> arr;
        while (head)
        {
            arr.push_back(head->val);
            head = head->next;
        }
        k--;
        int temp = arr[k];
        arr[k] = arr[arr.size() - k - 1];
        arr[arr.size() - k - 1] = temp;
        for (auto x : arr)
            cout << x << " ";
        cout << endl;
        ListNode *newnode = new ListNode(arr[0]);
        ListNode *save = newnode;

        for (int i = 1; i < arr.size(); i++)
        {
            ListNode *newn = new ListNode(arr[i]);
            newnode->next = newn;
            newnode = newn;
        }
        newnode->next = NULL;
        return save;
    }
};