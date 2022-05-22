//
// Created by raner on 2022/5/14.
//
#include <cstdio>
#include <vector>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int val) : val(val), next(nullptr) {}
    ListNode(int val, ListNode *next) : val(val), next(next) {}
};

ListNode* ListizeAtHead (const vector<int> &v = {}) {
    // 头插法建表保持顺序
    ListNode *l {nullptr};
    for (int i = int(v.size()) - 1; i >= 0; --i) {
        ListNode *p {new ListNode(v[i], l)};
        l = p;
    }
    return l;
}

void PrintList(ListNode *l) {
    printf("l: ");
    while (l != nullptr) {
        printf("%d ", l->val);
        l = l->next;
    }
    printf("\n");
}

bool IsEmpty(ListNode *l) {
    if (l == nullptr) return true;
    else return false;
}

void PrintEmpty(ListNode *l) {
    if (IsEmpty(l)) printf("Empty\n");
    else printf("Not empty\n");
}

void Insert(int val) {

}

int main() {
    vector<int> v {1, 2, 3, 4};
    ListNode *l {ListizeAtHead()};
    PrintEmpty(l);
    delete l;
    l = ListizeAtHead(v);
    PrintList(l);
    PrintEmpty(l);
//    int key {4};
//    PrintSearch(l, key);
//    key = 5;
//    PrintSearch(l, key);
//    Delete(l, Search(l, 3));
//    PrintList(l);
//    Delete(l, Search(l, 1));
//    PrintList(l);
//    Delete(l, Search(l, 5));
//    PrintList(l);
//    Delete(l, Search(l, 2));
//    PrintList(l);
//    Delete(l, Search(l, 4));
//    PrintList(l);

    return 0;
}
