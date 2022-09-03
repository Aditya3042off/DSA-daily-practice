// https://leetcode.com/problems/palindrome-linked-list/

// Given the head of a singly linked list, return true if it is a palindrome.

#include <bits/stdc++.h>
using namespace std;

// Definition for singly-linked list.
struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution
{
public:
    ListNode *reverseList(ListNode *head)
    {
        ListNode *prevnode = NULL, *curnode = head, *nextnode = head->next;

        while (curnode != NULL)
        {
            curnode->next = prevnode;

            prevnode = curnode;
            curnode = nextnode;
            if (curnode != NULL)
                nextnode = curnode->next;
        }

        return prevnode;
    }

    ListNode *findMiddle(ListNode *head)
    {
        ListNode *slow = head, *fast = head;

        while (fast->next != NULL and fast->next->next != NULL)
        {
            fast = fast->next->next;
            slow = slow->next;
        }

        return slow;
    }

    bool isPalindrome(ListNode *head)
    {
        if (head == NULL or head->next == NULL)
            return true;

        ListNode *middle = findMiddle(head);
        middle->next = reverseList(middle->next);

        ListNode *head1 = head, *head2 = middle->next;

        while (head1 != NULL and head2 != NULL)
        {
            if (head1->val != head2->val)
                return false;
            head1 = head1->next;
            head2 = head2->next;
        }
        return true;
    }
};