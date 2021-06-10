#include <bits/stdc++.h>

using namespace std;

vector<map<int, int>> depth;

void out_map(map<int, int> &a) {
    map<int, int>::iterator it = a.begin();
    while (it != a.end()) {
        cout << (*it).first << " "; 
        ++it;
    }
    cout << endl;
}

void down(vector<vector<int>> &g, int v, int parent) {
    for (int i = 0; i < g[v].size(); ++i) {
        if (g[v][i] != parent) {
            down(g, g[v][i], v);
            depth[v][(*depth[g[v][i]].rbegin()).first + 1] += 1;
        }
    }
    if (depth[v].empty()) {
        depth[v][0] = 1;
    }
}

void parent_count(vector<vector<int>> &g, int v, int parent) {
    if (parent != -1) {
        int curr_depth = (*depth[v].rbegin()).first + 1;
        int parent_depth = (*depth[parent].rbegin()).first;
        if (curr_depth != parent_depth || (*depth[parent].rbegin()).second > 1) {
            depth[v][parent_depth + 1] += 1;
        } else {
            if (depth[parent].size() > 1) {
                depth[v][(*(++depth[parent].rbegin())).first + 1] += 1;
            } else {
                depth[v][1] += 1;
            }
        }
    }
    for (int i = 0; i < g[v].size(); ++i) {
        if (g[v][i] != parent) {
            parent_count(g, g[v][i], v);
        }
    }
}

int main() {
    int n;
    cin >> n;
    vector<vector<int>> g(n);
    for (int i = 0; i < n - 1; ++i) {
        int a, b;
        cin >> a >> b;
        g[a - 1].push_back(b - 1);
        g[b - 1].push_back(a - 1);
    }
    depth.resize(n);
    down(g, 0, -1);
    parent_count(g, 0, -1);
    for (int i = 0; i < n; ++i) {
        cout << (*depth[i].rbegin()).first << " ";
    }
    cout << endl;
}