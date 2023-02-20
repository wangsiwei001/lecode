//
// Created by 10593 on 2022/10/8.
//

#include <vector>
#include <numeric>
#include <stack>
#include <vector>
#include "ListNode.cpp"
#include "unordered_map"
using namespace std;
class Node {
public:
    int val;
    Node* next;
    Node* random;

    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};

class Solution {
public:
/*
 * 724.寻找数组的中心下标
 */
//int Solution::pivotIndex(vector<int> &nums) {
//    int sum = accumulate(nums.begin(), nums.end(),0);
//    int a = 0;
//    for (int i = 0; i < nums.size(); ++i) {
//        if (2 * a +nums[i] == sum){
//            return i;
//        }
//        a += nums[i];
//    }
//    return -1;
//}
/*
 * 121. 买卖股票的最佳时机
 */
//int Solution::maxProfit(vector<int> &prices) {
//    //暴力法超时
////    int maxProfit = 0;
////    for (int i = 0; i < prices.size(); ++i) {
////        for (int j = i+1; j < prices.size(); ++j) {
////            maxProfit = max(maxProfit,prices[j] - prices[i]);
////        }
////    }
////    return maxProfit;
//
//    int inf = 1e9;
//    int minV = inf,maxV = 0;
//    for (const auto &item : prices){
//        maxV = max(item - minV,maxV);
//        minV = min(minV,item);
//    }
//    return maxV;
//}
/**
    剑指 Offer 24. 反转链表
*/
    ListNode *reverseList(ListNode *head) {
        ListNode *cur = head, *pre = nullptr;
        while (cur != nullptr) {
            ListNode *tmp = cur->next; // 暂存后继节点 cur.next
            cur->next = pre;           // 修改 next 引用指向
            pre = cur;                 // pre 暂存 cur
            cur = tmp;                 // cur 访问下一节点
        }
        return pre;
    }

/**剑指 Offer 35. 复杂链表的复制
 **/
    unordered_map<Node *, Node *> cachedNode;
    Node *copyRandomList(Node *head) {
        if (head == nullptr){
            return nullptr;
        }

        if (!cachedNode.count(head)){
            Node *copynode = new Node(head->val);
            cachedNode[head] = copynode;
            copynode->next = copyRandomList(head->next);
            copynode->random = copyRandomList(head->random);
        }
        return cachedNode[head];
    }

    Node* copyRandomList1(Node* head) {
        if (head == nullptr) {
            return nullptr;
        }


        for (Node* node = head; node != nullptr; node = node->next->next) {
            Node* nodeNew = new Node(node->val);
            nodeNew->next = node->next;
            node->next = nodeNew;
        }

        for (Node *node = head;node != nullptr;node = node->next->next) {
            Node *copyNode = node->next;
            copyNode->random = (copyNode->random != nullptr) ? node->random->next : nullptr;
        }
        Node * headNew = head->next;
        for (Node *node = head;node != nullptr; node = node->next) {
            Node *nodeNew = node->next;
            node->next = node->next->next;
            nodeNew->next = (node->next != nullptr)? nodeNew->next->next : nullptr;
        }
        return headNew;
    }

};