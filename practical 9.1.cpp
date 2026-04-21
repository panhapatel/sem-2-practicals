#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int n;

    cout << "Enter number of elements: ";
    cin >> n;

    vector<int> v(n);

    cout << "Enter elements:\n";
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }


    vector<int> v1 = v;
    reverse(v1.begin(), v1.end());

    cout << "\nReversed using std::reverse(): ";
    for (int x : v1) {
        cout << x << " ";
    }


    vector<int> v2 = v;

    auto start = v2.begin();
    auto end = v2.end() - 1;

    while (start < end) {

        int temp = *start;
        *start = *end;
        *end = temp;

        start++;
        end--;
    }

    cout << "\nReversed manually using iterators: ";
    for (int x : v2) {
        cout << x << " ";
    }

    return 0;
}
