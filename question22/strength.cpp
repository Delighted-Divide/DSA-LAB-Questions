#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void solve(){
    int n; 
    cout << "Enter the number of People: ";
    cin>>n;
    vector<int> v(n);
    for(int i = 0; i < n; i++) {
        cout << "Enter the Height of Person " << i + 1 << ": ";
        cin >> v[i];
    }

    vector<int> v2 = v;
    sort(v2.rbegin(), v2.rend());
    int max1 = v2[0], max2 = v2[1];

    for(int i = 0; i < n; i++) {
        if(v[i] != max1) cout << v[i] - max1 << " ";
        
        else cout << v[i] - max2 << " ";
    }
}

int main(){
    int t = 1;
    cout << "Enter the number of test cases: ";
    cin >> t;
    for(int i = 1; i <= t; i++){
        solve(); 
        cout << '\n';
    }
    return 0;
}