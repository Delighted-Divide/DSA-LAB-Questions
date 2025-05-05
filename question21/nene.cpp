#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class NeneGame {
private:
    vector<int> sequence;

public:
    void setSequence(const vector<int>& seq) {
        sequence = seq;
        sort(sequence.begin(), sequence.end());
    }

    int countWinners(int n) {
        vector<bool> players(n + 1, true); // 1-based indexing
        bool changed;
        
        do {
            changed = false;
            vector<int> toRemove;
            
            for (int pos : sequence) {
                if (pos > n) continue;
                
                int count = 0;
                for (int i = 1; i <= n; i++) {
                    if (players[i]) {
                        count++;
                        if (count == pos) {
                            toRemove.push_back(i);
                            break;
                        }
                    }
                }
            }
            
            if (!toRemove.empty()) {
                changed = true;
                for (int p : toRemove) {
                    players[p] = false;
                }
            }
        } while (changed);
        
        return count_if(players.begin() + 1, players.end(), [](bool b) { return b; });
    }
};

int main() {
    NeneGame game;
    vector<int> a;
    int k, q;
    
    cout << "Enter size of sequence (k): ";
    cin >> k;
    a.resize(k);
    cout << "Enter sequence elements: ";
    for (int i = 0; i < k; i++) cin >> a[i];
    game.setSequence(a);
    
    cout << "Enter number of queries (q): ";
    cin >> q;
    cout << "Enter queries (n_i values): ";
    while (q--) {
        int n;
        cin >> n;
        cout << game.countWinners(n) << " ";
    }
    
    return 0;
}