
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

struct CompareDistance {
    bool operator()(const std::pair<int, int>& a, const std::pair<int, int>& b) {
        return (a.first * a.first + a.second * a.second) > (b.first * b.first + b.second * b.second);
    }
};

bool compare(const std::pair<int, int>& a, const std::pair<int, int>& b) {
    return (a.first * a.first + a.second * a.second) > (b.first * b.first + b.second * b.second);
}


template <typename T>
void printArray(std::vector<T> values) {
    std::cout << "["; 
    for (int i = 0; i < values.size(); i++) {
        std::cout << values[i]; 
        if (values.size() - 1 > i) {
            std::cout << ", "; 
        }
    }
    std::cout << "]" << std::endl; 
}

int main() {

    // set<int> s1; 
    // std::pair<std::set<int>::iterator, bool> ret1 = s1.insert(10); 
    // std::pair<std::set<int>::iterator, bool> ret2 = s1.insert(10); 

    // cout << *ret1.first << "----value \n" << endl; 
    // cout << ret1.second << "----insert success?\n" << endl; 
    // cout << *ret2.first << "----value\n" << endl; 
    // cout << ret2.second << "----insert success?\n" << endl; 

    // s1.insert(20); 
    // s1.insert(12);
    // s1.insert(122);
    // s1.insert(12222);
    // s1.insert(112);
    // s1.insert(126);

    // std::set<int>::iterator ret = s1.lower_bound(100); 

    // cout << *ret << endl; 

    // string s3 = "aabbccddeeffgghhiiiiii"; 
    // cout << s3.size(); 

    // string s = "224135"; 
    // string ret = s.substr(0, 0); 
    // cout << ret.size() << endl; 

    //     cout << (((int)s[i] - 48) % 2 == 1) << endl; 
    // }
    
    // for (int i = 97; i < 123; i++) {
    //     cout << (char)i << " -- " << i << endl;; 
    // }

    // cout << (('0'))-48 << endl;; 
    // cout << (('1'))-48 << endl;; 
    // cout << (('2'))-48 << endl;; 
    // cout << (('3'))-48 << endl;; 
    // cout << (('4'))-48 << endl;; 

    // std::vector<int> vec = {9, 5, 4, 1, 1, 3, 7};
    // printArray(vec); 
    // make_heap(vec.begin(), vec.end()); 
    // printArray(vec); 
    // vec.push_back(100); 
    // push_heap(vec.begin(), vec.end()); 
    // printArray(vec); 

    // cout << (int)'b' << endl; // 98 -- 1x
    // cout << (int)'a' << endl; // 97 -- 1x
    // cout << (int)'l' << endl; // 108 -- 2x
    // cout << (int)'o' << endl; // 111 -- 2x
    // cout << (int)'n' << endl; // 110 -- 1x

    // for (auto &&i : s1)
    // {
    //     cout << i << '\n'; 
    // }
    // cout << endl ; 
    
    // std::set<int>::iterator it = s1.end(); 
    // std::set<int>::reverse_iterator rit = s1.rend();  

    // cout << *std::prev(it) << endl << endl; 

    // cout << *std::next(it) << endl << endl; 

    // cout << s1.size() << endl ; 
    // int n = 0; 

    // auto printer = [&](int value) {
    //     cout << "some randome val=" << n << endl; 
    // }; 
    // for (int i = 0; i < 5; i++) {
    //     printer(i); 
    // }

    // auto getBits = [](int value) {
    //     int cnt = 0; 
    //     for (int i = 0; i < 14; i++) {
    //         if (value & (1 << i)) cnt++; 
    //     }
    //     return cnt; 
    // }; 

    // priority_queue<int, std::vector<int>,  std::greater<int> > heap; 
    // heap.push(10); 
    // heap.push(12); 
    // heap.push(31); 
    // heap.push(3); 


    // // priority que holding points: 
    // priority_queue<
    //     std::pair<int, int>, 
    //     std::vector<std::pair<int, int>>, 
    //     CompareDistance
    // > pointsq; 
    
    // cout << heap.top() << endl; 

    // auto isSub = [] (string sub, string word) {
    //     int sidx = 0; 
    //     for (int i = 0; i < word.size(); i++) {
    //         if (sub[sidx] == word[i]) sidx++; 

    //         if (sidx == sub.size()) return true; 
    //     }
    //     return false; 
    // }; 

    // cout << (isSub("wwa", "dfkl;afdkj;lkjl") ? "true" : "false") << endl; 

    // string s = "10000"; 
    // int cnt = 0; 
    // for (int i = 0; i < s.size(); i++) {
    //     if (s[i] >= '0' && s[i] <= '9') {
    //         cnt = (cnt*10) + (s[i] - '0'); 
    //     }
    // }
    // cout << cnt + 1 << endl ; 

    int i = 40; 
    int leftover = 40 % 35; 
    cout << "leftover: " << leftover << endl; 

    cout << "\n"; 

    return 0;
}
