
#include <iostream>
#include <queue>
using namespace std;

int kthSmallest(int a[], int n, int k) {

    if (k < 1 || k > n)
        return -1;

    priority_queue<int> pq;

    for (int i = 0; i < n; i++) {

        pq.push(a[i]);

        if ((int)pq.size() > k) {
            pq.pop();
        }
    }

    return pq.top();
}

int main() {

    int a[] = {7, 10, 4, 3, 20, 15};

    int n = sizeof(a) / sizeof(a[0]);
    int k = 3;

    cout << k << "-th smallest element: "
         << kthSmallest(a, n, k);

    return 0;
}
