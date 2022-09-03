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
        ListNode *temp1;
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

        int count = 1;
        ListNode *newHead, *newEnd;
        temp1 = head;

        while (temp1->next != NULL)
        {
            if (count == size - k)
            {
                newEnd = temp1;
                newHead = temp1->next;
            }
            count++;
            temp1 = temp1->next;
        }
        temp1->next = head;
        newEnd->next = NULL;
        return newHead;
    }
};