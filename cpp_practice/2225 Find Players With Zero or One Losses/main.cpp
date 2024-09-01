// https://leetcode.com/problems/find-players-with-zero-or-one-losses/description/?envType=problem-list-v2&envId=eeyho3um

#include <map>
#include <math.h>
#include <algorithm>
#include <iostream>
#include <array>
#include <vector>
#include <ios>

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

// class Solution {
// public:
//     vector<vector<int>> findWinners(vector<vector<int>>& matches) {

//         map<int, array<int, 2>> fq;        // player #  ----- wins/losses 
//         for (auto match : matches) {
//             fq[match[0]][0]++; 
//             fq[match[1]][1]++; 
//         }

//         vector<vector<int>> ans; 
//         ans.push_back({}); 
//         ans.push_back({}); 
//         for (auto it = fq.begin(); it != fq.end(); ++it) {
//             if (it->second[1] == 1) ans[1].push_back(it->first); 
//             if (it->second[1] == 0) ans[0].push_back(it->first); 
//         }

//         return ans; 
//     }
// };


class solution {
public:
    vector<vector<int>> findwinners(vector<vector<int>>& matches) {
        unordered_map<int, int> wins;  // player id -- count
        unordered_map<int, int> loss; 
        
        for (vector<int> match : matches) {
            wins[match[0]]++;
            loss[match[1]]++; 
        }

        vector<vector<int>> ans(2); 
        for (const auto& [player, win_count] : wins) {
            if (loss[player] == 0) {
                ans[0].push_back(player);
            }
        }
        
        for (const auto& [player, loss_count] : loss) {
            if (loss_count == 1) {
                ans[1].push_back(player);
            }
        }

        sort(ans[0].begin(), ans[0].end()); 
        sort(ans[1].begin(), ans[1].end()); 

        return ans; 
    }
};


int main(int argc, char const *argv[])
{

    return 0;
}
