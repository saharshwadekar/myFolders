#include <iostream>
#include <vector>

using namespace std;

int maxBagsSold(int n, int m, const vector<pair<int, int>>& customers, const vector<pair<int, int>>& riceBags) {
    int maxBags = 0;

    for (const auto& customer : customers) {
        for (const auto& bag : riceBags) {
            if (bag.second <= customer.second && bag.first >= customer.first) {
                maxBags++;
                break;  // Move to the next customer once a suitable bag is found
            }
        }
    }

    return maxBags;
}

int main() {
    int n, m;
    cin >> n >> m;

    vector<pair<int, int>> customers(n);
    for (int i = 0; i < n; i++) {
        cin >> customers[i].first >> customers[i].second;
    }

    vector<pair<int, int>> riceBags(m);
    for (int i = 0; i < m; i++) {
        cin >> riceBags[i].first >> riceBags[i].second;
    }

    int result = maxBagsSold(n, m, customers, riceBags);
    cout << result << endl;

    return 0;
}
