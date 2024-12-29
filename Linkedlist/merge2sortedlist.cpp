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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        if (list1 == NULL)
            return list2;
        if (list2 == NULL)
            return list1;

        ListNode* ans = new ListNode(-1);
        ListNode* mptr = ans;

        while (list1 && list2) {
            if (list1->val<=list2->val)
            {
                mptr->next=list1;
                mptr=list1;
                list1=list1->next;

            }
            else
            {
                mptr->next=list2;
                mptr=list2;
                list2=list2->next;
            }
        }

        if(list1)
        {
            mptr->next=list1;;
        }
        if(list2)
        {
            mptr->next=list2;
        }
        return ans->next;
    }
};
/*
2 POINTER LUNGA OR TRAVERSE KRUGA DONO LIST OR AGAR EK POINTER KA ELEMENT DUSRE SE CHOTA HAI TAB TAK AGAE BDEHNGE OR JESE BADA ELEMENT AYA
TABH POINTER SWAP KRDIYE OR US ELEMENT KI LINK DUSRE POINTER PAR LAGA DIYA

TC O(L1+L2)
SC O(1)
*/
