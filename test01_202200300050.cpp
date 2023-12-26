#include <iostream>
#include <iterator>
using namespace std;

template<class T>
void perm(T a[], int left, int right) {
    if (left == right) {
        for (int i = 0; i < right; i++) {
            cout << a[i] << ",";
        }
        cout << a[right] << endl;
    } else {
        for (int i = left; i <= right; i++) {
            swap(a[left], a[i]);
            perm(a, left + 1, right);
            swap(a[left], a[i]);
        }
    }
}

int main() {
    int a[20];
    cout << "Input" << endl;
    int m, len = 0;
    for (int i = 0; i < 20; i++) {
        cin >> m;
        if (m == 0) break;
        a[i] = m;
        len++;
    }

    cout << "Output" << endl;
    perm(a, 0, len - 1);
    cout << "end" << endl;

    return 0;
}
