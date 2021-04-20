/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
    private:
    vector<int> ans;
public:
    void preo(Node* root){
        if((root->children).size()==0) {
            return;
        }
        for(auto x:root->children){
            ans.push_back(x->val);
            preo(x);
        }
        return ;
    }
    vector<int> preorder(Node* root) {
        if(!root) return ans;
        ans.push_back(root->val);
        preo(root);
        return ans;
    }
};
