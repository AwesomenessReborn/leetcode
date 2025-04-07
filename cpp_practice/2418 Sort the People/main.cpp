
#include <map>
#include <iostream>
#include <array>
#include <vector>
#include <set>
#include <ios>

using namespace std; 

static auto _ = [](){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return nullptr;
}();

class Solution {
public:
    vector<string> sortPeople(vector<string>& names, vector<int>& heights) {
        map<int, string, std::greater<int>> peop; 

        for (size_t i = 0; i < names.size(); i++)
        {
            peop[heights[i]] = names[i]; 
        }

        vector<string> out; 
        out.reserve(names.size()); 
        map<int, string>::iterator it; 
        for (it = peop.begin(); it != peop.end(); it++) {
            out.push_back((*it).second); 
        }
        
        return out; 
    }
};

int main(int argc, char const *argv[])
{
    Solution sol; 

    vector<string> names1 = {"Mary", "John", "Emma"};
    vector<int> heights1 = {180, 165, 170};

    vector<string> names2 = {"Alice", "Bob", "Bob"};
    vector<int> heights2 = {155, 185, 150};
    
    vector<string> result1 = sol.sortPeople(names1, heights1);
    cout << "Sorted names (Test case 1): ";
    for (const auto& name : result1) {
        cout << name << " ";
    }
    cout << endl;

    vector<string> result2 = sol.sortPeople(names2, heights2);
    cout << "Sorted names (Test case 2): ";
    for (const auto& name : result2) {
        cout << name << " ";
    }
    cout << endl;

    return 0;
}
