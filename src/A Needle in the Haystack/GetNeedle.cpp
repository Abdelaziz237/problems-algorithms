#include <vector>
#include <string>
#include <iostream>
#include "../algorithms/KMP.cpp"

using namespace std;

void getNeedleFromHaystack() {
    string needle, haystack;
    int needle_length;
    while (cin >> needle_length) {
        cin >> needle;
        cin >> haystack;

        vector<int> indices = KMPSearch(needle_length, haystack, needle);

        for (int index : indices) {
            cout << index << endl;
        }
        cout << endl;
    }
}

