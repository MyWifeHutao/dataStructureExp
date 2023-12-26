#include<bits/stdc++.h>
using namespace std;

const int N = 1e5+10;
int p[N];
vector<int> sets[N];

int find(int x) {
    if(p[x] != x) p[x] = find(p[x]);
    return p[x];
}

int main() {
    int n, m;
    cout << "Input" << endl;
    cin >> n >> m;

    for(int i = 1; i <= n; i++) p[i] = i;

    while(m--) {
        int a, b;
        char ch;
        cin >> ch >> a >> ch >> b >> ch;
        if (a>=b)
        {
            p[find(a)] = find(b);
        }else{
            p[find(b)] = find(a);
        }
        

    }

    for(int i = 1; i <= n; i++) {
        sets[find(i)].push_back(i);
    }
    cout << "Output" << endl;
    for(int i = 1; i <= n; i++) {

        if(!sets[i].empty()) {
            cout << "(";
            for(int j = 0; j < sets[i].size(); j++) {
                if(j != 0) cout << ",";
                cout << sets[i][j];
            }
            cout <<")" << endl;
        }
    }
    cout << "end" << endl;
    return 0;
}
