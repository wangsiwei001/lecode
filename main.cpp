#include <iostream>
#include "Solution.h"
using namespace std;
int main() {
    Solution solution;
    vector<int> v ;
    v.push_back(7);
    v.push_back(1);
    v.push_back(5);
    v.push_back(3);
    v.push_back(6);
    v.push_back(4);
    cout << solution.maxProfit(v) << endl;
    return 0;
}
