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
    ListNode* middleNode(ListNode* head) {
        ListNode* slow=head;
         ListNode* fast=head;
         while(fast!=NULL && fast->next!=NULL)
         {
            slow=slow->next;
            fast=fast->next->next;
         }

        return slow;
    }
};

/*
SLOW POINTER AND FAST POINTER METHOD THAT IS TORTOISE ALGO JISME HUM SLOW 1STEP CHLEGA OR FAST 2 STEP CHLEGA WESE JAHA FAST NULL POCHA
WAHA JAHA SLOW HOGA WO HUMARA MIDDLE NODE HOGA
*/
