#include <iostream>
#include <set>
#include <vector>
using namespace std;

int main() {
    int n;

    cout << "Enter number of elements: ";
    cin >> n;

    set<int> s;

    cout << "Enter elements:\n";
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        s.insert(x);
    }

    cout << "\nUnique elements (using set): ";
    for (auto it = s.begin(); it != s.end(); it++) {
        cout << *it << " ";
    }


    vector<int> v(s.begin(), s.end());

    cout << "\nConverted to vector: ";
    for (int x : v) {
        cout << x << " ";
    }

    return 0;
}
