// Given the head of a linked list, rotate the list to the right by k places.

// Input: head = [1,2,3,4,5], k = 2
// Output: [4,5,1,2,3]

// Input: head = [0,1,2], k = 4
// Output: [2,0,1]

// https://www.youtube.com/watch?v=9VPm6nEbVPA&list=PLgUwDviBIf0r47RKH7fdWN54AbWFgGuii&index=13

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
    ListNode *rotateRight(ListNode *head, int k)
    {
        if (head == NULL || head->next == NULL || k == 0)
            return head;
        ListNode *end, *temp1, *temp2 = head;
        end = head;
        temp1 = head;
        int size = 1;
        // finding size of linkedlist
        while (temp1->next != NULL)
        {
            temp1 = temp1->next;
            size++;
        }
        k = k % size;
        if (k == 0)
            return head;

        for (int i = 1; i < k; i++)
            end = end->next;
        while (end->next != NULL)
        {
            temp2 = temp2->next;
            end = end->next;
        }
        temp1 = head;
        while (temp1->next != temp2)
            temp1 = temp1->next;
        end->next = head;
        head = temp2;
        temp1->next = NULL;
        return head;
    }
};