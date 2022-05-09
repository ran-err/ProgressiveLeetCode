//
// Created by raner on 2022/5/7.
//
#include <cstdio>
#include <vector>
//#include <ranges>  // CPP20，用来逆序范围for
using namespace std;

struct ListNode{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    // 几乎没有next和val只知其一的情况，除了在初始化存储某种信息的头节点时
    // 如 ListNode *l {new ListNode(size)};
    ListNode(int x) : val(x), next(nullptr) {}
    // 但是 ListNode *l {new ListNode(nullptr)}; 和 ListNode *l {new ListNode()}; 效果是一样的
    // 所以如下构造函数更加“没用”，这里按照LeetCode的方式只给出三种构造函数
    // ListNode(ListNode *next) : val(0), next(next) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode* ListizeAtHead(const vector<int> &v = {}) {
    ListNode *l {new ListNode()};

    // 头插法创建链表并保持顺序
    for (int i {int(v.size()) - 1}; i >= 0; --i) {
//        l->next = new ListNode(v[i], l->next);
        // 使用Insert()的写法
        void Insert(ListNode* l, int val);
        Insert(l, v[i]);
    }
    // CPP20写法，需要 #include <ranges>，现在还没办法使用 - 20220509
//    for (auto i : v | std::views::reverse) {
//        l->next = new ListNode(i, l->next);
//    }

    // 头插法创建链表并忽略顺序（逆序）
//    for (auto i : v) {
//        l->next = new ListNode(i, l->next);
//    }

    return l;
}

ListNode* ListizeAtTail(const vector<int> &v = {}) {
    ListNode *l {new ListNode()}, *pre {l};

    // 尾插法创建链表并保持顺序
    for (auto i : v) {
        pre->next = new ListNode(i, pre->next);
        pre = pre->next;
    }

    // 尾插法创建链表并逆序
//    for (int i {int(v.size()) - 1}; i >= 0; --i) {
//        pre->next = new ListNode(v[i], pre->next);
//        pre = pre->next;
//    }

    return l;
}

void PrintList(ListNode* l) {
    printf("l: ");
    while (l->next != nullptr) {
        printf("%d ", l->next->val);
        l = l->next;
    }
    printf("\n");
}

bool IsEmpty(ListNode* l) {
    if (l->next == nullptr) return true;
    else return false;
}

void PrintEmpty(ListNode* l) {
    if (IsEmpty(l)) printf("Empty\n");
    else printf("Not empty\n");
}

void Insert(ListNode* l, int val) {
    // 头插一个值为val的节点
    l->next = new ListNode(val, l->next);
}

ListNode* Search(ListNode* l, int key) {
    while (l->next != nullptr && l->next->val != key) {
        l = l->next;
    }
    // 因为短路机制，下面这个判断需要和while中的顺序相同
    if (l->next == nullptr) return nullptr;
    else return l->next;
}

void PrintSearch(ListNode*l, int key) {
    if (Search(l, key) != nullptr) printf("Key %d found.\n", key);
    else printf("Key %d not found.\n", key);
  }

void Delete(ListNode* l, ListNode* p) {
    // 删除p指向的节点
    if (p == nullptr) return;  // 与Search()连用时没找到则不删除，否则会报错
    while (l->next != p) {
        l = l->next;
    }
    l->next = p->next;
    delete p;
}

int main() {
    vector<int> v {1, 2, 3, 4};
    ListNode *l {ListizeAtHead()};
    PrintEmpty(l);
    delete l;
    l = ListizeAtHead(v);
    PrintList(l);
    PrintEmpty(l);
    int key {4};
    PrintSearch(l, key);
    key = 5;
    PrintSearch(l, key);
    Delete(l, Search(l, 3));
    PrintList(l);
    Delete(l, Search(l, 1));
    PrintList(l);
    Delete(l, Search(l, 5));
    PrintList(l);
    Delete(l, Search(l, 2));
    PrintList(l);
    Delete(l, Search(l, 4));
    PrintList(l);

    return 0;
}
