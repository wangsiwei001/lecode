#include <iostream>
#include "Solution.cpp"
#include "Node.cpp"
using namespace std;
//int main() {
//    Solution solution;
//    vector<int> v ;
//    v.push_back(7);
//    v.push_back(1);
//    v.push_back(5);
//    v.push_back(3);
//    v.push_back(6);
//    v.push_back(4);
//    cout << solution.maxProfit(v) << endl;
//    return 0;
//}


//int main() {
//    int value = 0;
//    while (value >= 0) {
//        // Check for overflow
//        if (value == INT_MAX) {
//            printf("value = %d. Possible overflow!\n", value);
//        }
//        value++;
//    }
//    printf("Now, value = %d\n", value);
//    value = 0;
//    while (value <= 0) {
//        // Check for underflow
//        if (value == INT_MIN) {
//            printf("value = %d. Possible underflow!\n", value);
//        }
//        value--;
//    }
//    printf("Now, value = %d\n", value);
//    return 0;
//}

//剑指 Offer 35. 复杂链表的复制
int main() {
    Solution solution;
    Node *node = new Node(1);
    Node *node1 = new Node(2);
    Node *node2 = new Node(3);
    Node *node3 = new Node(4);
    Node *node4 = new Node(5);

    node->next = node1;
    node->random = node4;

    node1->next = node2;
    node1->random = node3;

    node2->next = node3;
    node2->random = node2;

    node3->next = node4;
    node3->random = node1;

    node4->next = nullptr;
    node4->random = node;

    Node *node5 = solution.copyRandomList1(node);

}