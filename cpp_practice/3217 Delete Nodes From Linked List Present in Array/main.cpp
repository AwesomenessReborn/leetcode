// https://leetcode.com/problems/delete-nodes-from-linked-list-present-in-array/?envType=daily-question&envId=2024-09-06

#include <map>
#include <math.h>
#include <algorithm>
#include <iostream>
#include <array>
#include <iterator> 
#include <vector>
#include <ios>
#include <limits>
#include <sstream> 
#include <string> 

#include <set>
#include <unordered_set>
#include <map>
#include <unordered_map>
#include <queue>

using namespace std; 

static auto _ = [](){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return nullptr;
}();

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
}; 

class Solution {
public:
    ListNode* modifiedList(vector<int>& nums, ListNode* head) {
        unordered_set<int> values(nums.begin(), nums.end()); 
        if (head == nullptr) return nullptr;

        while (head != nullptr && values.count(head->val)) {
            ListNode* temp = head;
            head = head->next;
            delete temp; 
        }

        if (head == nullptr) return nullptr;

        ListNode* cur = head;

        while (cur != nullptr && cur->next != nullptr) {
            if (values.count(cur->next->val)) {
                ListNode* tmp = cur->next;
                cur->next = cur->next->next; 
                delete tmp; 
            } else {
                cur = cur->next; 
            }
        }

        return head;
    }
};
