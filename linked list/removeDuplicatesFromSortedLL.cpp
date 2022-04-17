// Given the head of a sorted linked list, delete all duplicates such that each element appears only once. Return the linked list sorted as well.
// Input: head = [1,1,2]
// Output: [1,2]
// Input: head = [1,1,2,3,3]
// Output: [1,2,3]

// https://www.youtube.com/watch?v=p10f-VpO4nE&list=PLot-Xpze53ldVwtstag2TL4HQhAnC8ATf&index=76

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
class Solution
{
public:
    ListNode *deleteDuplicates(ListNode *head)
    {
        ListNode *temp;
        temp = head;

        while (temp != NULL and temp->next != NULL)
        {
            if (temp->val == temp->next->val)
                temp->next = temp->next->next;
            else
                temp = temp->next;
        }
        return head;
    }
};