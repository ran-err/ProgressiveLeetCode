//
// Created by raner on 2021/12/12.
//
#include <cstdio>
#include <vector>

struct ListNode {
     int val;
     ListNode *next;
     ListNode() : val(0), next(nullptr) {}
     ListNode(int x) : val(x), next(nullptr) {}
     ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode *res = new ListNode(), *pre = res;
        int carry{0};
        for (; l1 != nullptr and l2 != nullptr; l1 = l1 -> next, l2 = l2 -> next) {
            int n = l1 -> val + l2 -> val + carry;
            carry = n / 10;
            n %= 10;
            ListNode *p = new ListNode(n);
            pre -> next = p;
            pre = pre -> next;
        }
        if (l1 == nullptr)
            while (l2 != nullptr) {
                int n = l2 -> val + carry;
                carry = n % 10;
                n /= 10;
                ListNode *p = new ListNode(n);
                pre -> next = p;
                pre = pre -> next;
            }
        if (l2 == nullptr)
            while (l1 != nullptr) {
                int n = l1 -> val + carry;
                carry = n % 10;
                n /= 10;
                ListNode* p = new ListNode(n);
                pre -> next = p;
                pre = pre -> next;
            }
        if (carry != 0) {
            ListNode *p = new ListNode(carry);
            pre -> next = p;
            pre = pre -> next;
        }

        pre = res;
        res = res -> next;
        free(pre);
        return res;
    }
};

//ListNode* Listize(std::vector<int> num){
//    ListNode *l = new ListNode(), *pre = l;
//    for (int i : num) {
//        ListNode *p = new ListNode(i);
//        pre -> next = p;
//        pre = pre -> next;
//    }
//    pre = l;
//    l = l -> next;
//    free(pre);
//    return l;
//}

ListNode* Listize(std::vector<int> num){
    ListNode *l {nullptr};
    for (int i {int(num.size()) - 1}; i >= 0; --i) {
        l = new ListNode(num[i], l);
    }
    return l;
}

// 在C++20中大概可以有以下写法，但是leetcode只支持C++14
// 所以头插法只能使用普通for循环完成
//for (auto& x : reverse(range)) {
//    foo(x);
//}

void PrintList(ListNode* l) {
    while (l != nullptr) {
        printf("%d ", l -> val);
        l = l -> next;
    }
    printf("\n");
}

int main(){
    std::vector<int> n1{2, 4, 3}, n2{5, 6, 4};
    ListNode *l1 = Listize(n1), *l2 = Listize(n2);
    PrintList(l1);
    PrintList(l2);
    Solution s = Solution();
    ListNode *res = s.addTwoNumbers(l1, l2);
    PrintList(res);

    return 0;
}
