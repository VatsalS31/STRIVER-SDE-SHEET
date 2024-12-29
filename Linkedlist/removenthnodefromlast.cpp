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
    int len(ListNode* &head)
    {
        ListNode*temp=head;
        int c=0;
        while(temp!=NULL)
        {
            temp=temp->next;
            c++;
        }
        return c;
    }
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* temp=head;
        if(temp==NULL || temp->next==NULL)
        {
            return NULL;
        }
        int last=len(head)-n;  //3
        if(last==0)
        {
            return head->next;
        }
        for(int i=0;i<last-1;i++)
        {
            temp=temp->next;
        }
        temp->next=temp->next->next;

       
       
        return head;
        
    }
};

/*
ISME ME LENGTH NIKALUNGA LL KI OR TOTAL ME SE N MINUS KRDUGA TOH AAGE SE US ELEMENT KI POSITION MILJYGI AND NORMAL TRAVERSE KRKE
US ELEMENT KE NEXT KO NEXT NEXT PE ASSIGN KRDUNGA..

*/
