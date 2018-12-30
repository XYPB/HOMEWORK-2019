#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

/*重点还是在于链表的几个重点操作，添加这一类的操作都是在队尾进行的，所以可以使用while循环先找到队尾（单向链表），再用new添加*/

ListNode* Sum(ListNode* l1, ListNode* l2)
{
        vector<long long> Num1, Num2;
        vector<vector<long long>> Num;
        while(l1 != NULL)
        {
            Num1.push_back(l1->val);
            l1 = l1->next;
        }
        while(l2 != NULL)
        {
            Num2.push_back(l2->val);
            l2 = l2->next;
        }
        int len1 = (int)Num1.size();
        int len2 = (int)Num2.size();
        Num.push_back(Num1);
        Num.push_back(Num2);
        int longer = 0;
        int maxlen = 0, minlen = 0;
        if (len1 > len2)
        {
            maxlen = len1;
            minlen = len2;
            longer = 0;
        }
        else
        {
            minlen = len1;
            maxlen = len2;
            longer = 1;
        }
        vector<int> sum;
        int sw = 0;
        for (int i = 0; i <= maxlen; i++)
        {
            if (i < minlen)
            {
                int s = Num1[i] + Num2[i] + sw;
                sum.push_back(s % 10);
                sw = s / 10;
            }
            else if (i < maxlen)
            {
                int s = Num[longer][i] + sw;
                sum.push_back(s % 10);
                sw = s / 10;
            }
            else
                if (sw != 0)
                    sum.push_back(sw);
        }
        ListNode *mus = new ListNode(sum[0]);
        for (int i = 1; i < (int)sum.size(); i++)
        {
            ListNode *next = mus;
            while (next->next != NULL)
                next = next->next;
            ListNode *next1;
            next1 = new ListNode(sum[i]);
            next->next = next1;
        }
        return mus;
}

ListNode* removeNthFromEnd(ListNode* head, int n) 
{
    int length = 1;
    ListNode* p = head;
    while (p->next != NULL)
    {
        length++;
        p = p->next;
    }
    if (length == 1)
        return NULL;
    int trueN = length - n + 1;
    if (trueN == 1)
        return head->next;
    ListNode* bkTail,* bkHead;
    p = head;
    for (int i = 1; i < trueN + 1; i++)
    {
        if (i == trueN - 1)
            bkTail = p;
        else if (i == trueN)
            bkHead = p->next;
        else
            p = p->next;
    }
    bkTail->next = bkHead->next;
    return head;
}

ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) 
{
    ListNode* ansH = new ListNode(0);
    ListNode* ans = ansH;
    while (l1 != NULL || l2 != NULL)
    {
        if (l1 == NULL)
        {
            ans->next = l2;
            l2 = l2->next;
        }
        else if (l2 == NULL)
        {
            ans->next = l1;
            l1 = l1->next;
        }
        else 
        {
            if (l1->val < l2->val)
            {
                ans->next = l1;
                l1 = l1->next;
            }
            else
            {
                ans->next = l2;
                l2 = l2->next;
            }
        }
        ans = ans->next;
    }
    return ansH->next;
}

ListNode* mergeKLists(vector<ListNode*>& lists) 
{
    vector<ListNode*> nlists;
    while (lists.size() > 1)
    {
        for (int i = 0; i < (int)lists.size() / 2; i++)
            nlists.push_back(mergeTwoLists(lists[2 * i], lists[2 * i + 1]));
        if (lists.size() % 2 == 1)
            nlists.push_back(lists[lists.size() - 1]);
        lists = nlists;
        nlists.clear();
    }
    return lists[0];
}

int main()
{
	ListNode *l1;
	ListNode *l2;
    l2 = new ListNode(1);
	l1 = new ListNode(1);
	l2->next = new ListNode(4);
	l1->next = new ListNode(3);
    l2->next->next = new ListNode(5);
	l1->next->next = new ListNode(4);
    ListNode *l;
    l = new ListNode(2);
    l->next = new ListNode(6);
    //
    vector<ListNode *> b = {l1, l2, l};
    ListNode *ll = mergeKLists(b);
    ListNode *x = removeNthFromEnd(l, 2);
    ListNode *a = Sum(l1, l2);
	return 0;
}