#include <bits/stdc++.h>

using namespace std;
map<int, set<int>> ans;

void check(map<string, vector<int>> &m, string &a, int num) {
    for (int i = 0; i < a.size(); ++i) {
        int l = i - 1;
        int r = i + 1;
        while (l >= 0 && r < a.size() && a[l] == a[r]) {
            --l;
            ++r;
        } 
        if (l >= 0 && r == a.size()) {
            string curr = "";
            int j = l;
            while (j >= 0) {
                curr.push_back(a[j]);
                --j;
            }
            if (m.find(curr) != m.end()) {
                for (j = 0; j < m[curr].size(); ++j) {
                    ans[num].insert(m[curr][j]);
                }
            }
        }
        if (l == -1 && r < a.size()) {
            string curr = "";
            int j = a.size() - 1;
            while (j >= r) {
                curr.push_back(a[j]);
                --j;
            }
            if (m.find(curr) != m.end()) {
                for (j = 0; j < m[curr].size(); ++j) {
                    ans[m[curr][j]].insert(num);
                }
            }
        }
        l = i;
        r = i + 1;
        while (l >= 0 && r < a.size() && a[l] == a[r]) {
            --l;
            ++r;
        } 
        if (l >= 0 && r == a.size()) {
            string curr = "";
            int j = l;
            while (j >= 0) {
                curr.push_back(a[j]);
                --j;
            }
            if (m.find(curr) != m.end()) {
                for (j = 0; j < m[curr].size(); ++j) {
                    ans[num].insert(m[curr][j]);
                }
            }
        }
        if (l == -1 && r < a.size()) {
            string curr = "";
            int j = a.size() - 1;
            while (j >= r) {
                curr.push_back(a[j]);
                --j;
            }
            if (m.find(curr) != m.end()) {
                for (j = 0; j < m[curr].size(); ++j) {
                    ans[m[curr][j]].insert(num);
                }
            }
        }
    }
}

int main() {
    int n;
    cin >> n;
    vector<string> a(n);
    map<string, vector<int>> m;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        m[a[i]].push_back(i + 1);
    }
    for (int i = 0; i < n; ++i) {
        check(m, a[i], i + 1);
    }
    for (int i = 1; i <= n; ++i) {
        if (!ans[i].empty()) {
            set<int>::iterator it = ans[i].begin();
            while (it != ans[i].end()) {
                if (i != (*it))
                    cout << i << " " << (*it) << endl;
                ++it;
            }
        }
    }
}