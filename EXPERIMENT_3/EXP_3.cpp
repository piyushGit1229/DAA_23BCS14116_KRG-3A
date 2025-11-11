// piyush kumar varma uid 23bcs14116

#include <iostream>
#include <vector>
#include <map>

using namespace std;

int main() {
    int n;
    cout << "Enter number of elements in the array: ";
    cin >> n;

    vector<int> arr(n);
    cout << "Enter elements in the array: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    map<int, int> freq;

    for (int elmnt : arr) {
        freq[elmnt]++;
    }

    cout << "\nFrequency of elements:" << endl;
    for (auto& entry : freq) {
        cout << entry.first << ": " << entry.second << endl;
    }

    return 0;
}
