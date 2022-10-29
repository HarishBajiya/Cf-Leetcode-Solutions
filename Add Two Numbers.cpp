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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* newList=new ListNode(); //new list banayi
        ListNode* temp=newList; // new list ko traverse krne ke liye temp banaya
        int carry=0;
        while(l1 != NULL || l2 != NULL || carry==1){  // if anyof these matches tab tak krte rahenge
            int sum=0;  
            if(l1 != NULL){  // it handles null wala bhi case as 5 and null add--5
                sum+=l1->val;
                l1=l1->next;
            }
            
            if(l2 != NULL){
                sum+=l2->val;
                l2=l2->next;
            }
            sum+=carry;   //add carry to sum
            carry=sum/10;
            int dig=sum%10;
            ListNode* node=new ListNode(dig);  //adding that digit by creating new node
            temp->next=node;  //temp ke next mein node dalao
            temp=temp->next;  //temp ko aaghe badhao
        }
        
        return newList->next;  //new list ka head return kr do
    }
};
