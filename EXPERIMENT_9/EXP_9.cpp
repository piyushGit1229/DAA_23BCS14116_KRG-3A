// piyush kumar varma uid 23bcs14116

#include <iostream>
#include <vector>
#include <string>

using namespace std;

vector<int> findOccurrences(const string& text, const string& pattern) {
    vector<int> positions;
    int n = text.length();
    int m = pattern.length();

    for (int i = 0; i <= n - m; i++) {
        int j;
        for (j = 0; j < m; j++) {
            if (text[i + j] != pattern[j])
                break;
        }
        if (j == m)
            positions.push_back(i);
    }
    return positions;
}

int main() {
    string text, pattern;
    cout << "Enter text: ";
    getline(cin, text);

    cout << "Enter pattern: ";
    getline(cin, pattern);

    vector<int> result = findOccurrences(text, pattern);

    if (result.empty())
        cout << "Pattern not found" << endl;
    else {
        cout << "Pattern found at indices: ";
        for (int pos : result)
            cout << pos << " ";
        cout << endl;
    }

    return 0;
}
