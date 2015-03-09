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
        ListNode *addTwoNumbers(ListNode *l1,ListNode *l2) {
            if(l1==NULL)
                return l2;
            if(l2==NULL)
                return l1;
            int add=0,num;
            ListNode *p=l1,*q=l2;
            while(p!=NULL&&q!=NULL)
            {
                num=p->val+q->val+add;
                add=0;
                if(num>9)
                {
                    add=1;
                    num-=10;
                }
                p->val=q->val=num;
                if(p->next==NULL&&q->next==NULL&&add)
                {
                    ListNode *temp;
                    temp->val=add;
                    temp->next=NULL;
                    p->next=temp;
                    return l1;
                }
                p=p->next;
                q=q->next;
            }
            if(p!=NULL)
            {   
                while(add)
                {
                    num=p->val+add;
                    add=0;
                    if(num>9)
                    {
                        add=1;
                        num-=10;
                    }
                    p->val=num;
                    if(p->next==NULL)
                        break;
                    p=p->next;
                }
                if(add)
                {
                    ListNode *temp2;
                    temp2->val=add;
                    temp2->next=NULL;
                    p->next=temp2;
                }
                return l1;
            }
            else
            {
                 while(add)
                {
                    num=q->val+add;
                    add=0;
                    if(num>9)
                    {
                        add=1;
                        num-=10;
                    }
                    q->val=num;
                    if(q->next==NULL)
                        break;
                    q=q->next;
                }
                if(add)
                {
                    ListNode *temp3;
                    temp3->val=add;
                    temp3->next=NULL;
                    q->next=temp3;
                }
                 return l2;
            }
        }
};

