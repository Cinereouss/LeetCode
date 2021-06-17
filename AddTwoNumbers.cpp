#include <iostream>
#include <iterator>
#include <map>
#include <vector>

using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};

void insertData(ListNode*& pHead, ListNode*& pTail, vector<int> data) {
    for (int i = 0; i < data.size(); ++i) {
        ListNode* temp = new ListNode(data[i]);
        if (pHead == NULL) {
            pHead = pTail = temp;
        } else {
            pTail->next = temp;
            pTail = pTail->next;
        }
    }
}

ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
    ListNode* resHead = NULL;
    ListNode* resTail = NULL;
    int memory_num = 0;
    int sum = 0;

    while (l1 || l2 || memory_num > 0) {
        sum += memory_num;
        if (l1) {
            sum += l1->val;
            l1 = l1->next;
        }
        if (l2) {
            sum += l2->val;
            l2 = l2->next;
        }

        ListNode* temp = new ListNode(sum % 10);
        if (resHead == NULL) {
            resHead = resTail = temp;
        } else {
            resTail->next = temp;
            resTail = resTail->next;
        }
        memory_num = sum / 10;
        sum = 0;
    }

    return resHead;
}

int main() {
    /*
        You are given two non-empty linked lists representing two non-negative
       integers. The digits are stored in reverse order, and each of their nodes
       contains a single digit. Add the two numbers and return the sum as a
       linked list. You may assume the two numbers do not contain any leading
       zero, except the number 0 itself.

        Example 1:
            Input: l1 = [2,4,3], l2 = [5,6,4]
            Output: [7,0,8]
            Explanation: 342 + 465 = 807.
        Example 2:
            Input: l1 = [0], l2 = [0]
            Output: [0]
        Example 3:
            Input: l1 = [9,9,9,9,9,9,9], l2 = [9,9,9,9]
            Output: [8,9,9,9,0,0,0,1]

        Constraints:
            The number of nodes in each linked list is in the range [1, 100]. 0
       <= Node.val <= 9 It is guaranteed that the list represents a number that
       does not have leading zeros.
    */

    /*Clone data for test*/
    ListNode* l1Head = NULL;
    ListNode* l1Tail = NULL;
    vector<int> l1Data = {2, 4, 3};
    insertData(l1Head, l1Tail, l1Data);

    ListNode* l2Head = NULL;
    ListNode* l2Tail = NULL;
    vector<int> l2Data = {5, 6, 4};
    insertData(l2Head, l2Tail, l2Data);

    addTwoNumbers(l1Head, l2Head);

    return 0;
}