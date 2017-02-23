/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {//如果存在环的话，以2前进的指针和以1前进的指针肯定会遇上
public:
    ListNode *detectCycle(ListNode *head) {
        ListNode* fast=head;
        ListNode* slow=head;
        ListNode* entery=head;
        if(head==NULL||head->next==NULL)
            return NULL;
        
        while(fast->next&&fast->next->next)//设定退出条件
        {
            slow=slow->next;
            fast=fast->next->next;
            
            if(slow==fast)
            {
                while(slow!=entery)
                {
                    slow=slow->next;
                    entery=entery->next;
                }
                
                return entery;
            }
                
        }
        return NULL;
        
        
    }
};
