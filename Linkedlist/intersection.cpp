/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode *a=headA;
        ListNode *b=headB;

        while(a->next && b->next)
        {
            if(a==b)
            {
                return a;
            }

            a=a->next;
            b=b->next;
        }

        // when ll does not have any internsection point
        if(a->next==NULL && b->next==NULL && a!=b) return 0;

            if(a->next==0)
            {
                //b ll is bigger or equal than a
                // hame nikl na hai kitna bada hai 
                int blen=0;
                while(b->next!=NULL)
                {
                    blen++;
                    b=b->next;

                }

                // make the start same
                while(blen--)
                {
                    headB=headB->next;
                }
            }

            else
            {
                //a ll is bigger or equal than b
                // hame nikl na hai kitna bada hai 
                int alen=0;
                while(a->next!=NULL)
                {
                    alen++;
                    a=a->next;

                }

                // make the start same
                while(alen--)
                {
                    headA=headA->next;
                }
                
            }
            while(headA!=headB)
        {
            headA=headA->next;
            headB=headB->next;
        }

        return headA;

        

        

        
    }
};

/*
OPTIMAL APPRACH IS THAT KI CRAETE 2 DUMMY NODES AND ASSIGN IT TO HEAD OF 2 LL TRAVERSE THE FULL LL AND THE POINT IT REACHED NULL ASSIGN IT
TO OTHER DUMMY HEAD THAT IS AGRA D1 NULL POCHA TOH D2 WALE HEAD PAR ASSIGN KRDEGE...OR D2 POCHA TOH D1 WALE HEAD PAR OR USKE BAAD TARVERSE KRNA 
CHALU RAKHO EK POINT ESA AYGA KI D1,D2 SAME POINT PAR AJYGE..OR WAHI INTERSECTION NODE HOGA...

*/
