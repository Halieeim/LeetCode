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
        if(!head || !head->next) return head;
        ListNode* cur = head;
        ListNode* h;
        bool flag = false;
        vector<int> v1, v2;
        while(cur){
            if(cur->val == x) flag = true;
            if(!flag && cur->val < x){
                v1.push_back(cur->val);
            }
            else if(flag && cur->val < x){
                v1.push_back(cur->val);
            }
            else{
                v2.push_back(cur->val);
            }
            cur = cur->next;
        }
        int idx = v1.size();
        v1.insert(v1.end(), v2.begin(), v2.end());
        h = new ListNode(v1[0]);
        cur = h;
        for(int i = 1; i < v1.size(); i++){
            cur->next = new ListNode(v1[i]);
            cur = cur->next;
        }
        return h;
    }
};