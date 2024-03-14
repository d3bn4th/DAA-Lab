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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<int, vector<int>, greater<int>> pq;
        for(ListNode* it : lists) {
            ListNode* temp = it;
            while(temp) {
                pq.push(temp->val);
                temp = temp ->next;
            }
        }
        ListNode* ansHead = NULL;
        ListNode* temp = NULL;
        ListNode* prev = NULL
        if(!pq.empty()){
            ansHead = new ListNode(pq.top());
            pq.pop();
            temp = ansHead;
        }
        while(!pq.empty()){
            ListNode* newNode = new ListNode(pq.top());
            pq.pop();
            temp->next = newNode;
            temp = newNode;
        }
        return ansHead;
    }
};