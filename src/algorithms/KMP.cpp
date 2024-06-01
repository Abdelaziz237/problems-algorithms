#include <vector>
#include <string>

using namespace std;

void getLPS(int n, const string& pattern, vector<int>& lps) {
    lps[0] = 0;
    int i = 1;
    int l = 0;

    while (i < n) {
        if (pattern[i] == pattern[l]){
            l++;
            lps[i] = l;
            i++;
        } else {
            if (l != 0) l = lps[l-1];
            else {
                lps[i] = 0;
                i++;
            }
        }
    }
}

vector<int> KMPSearch(int n, const string& txt, const string& pattern) {
    vector<int> lps(n);
    vector<int> indices;

    getLPS(n, pattern, lps);

    int i = 0, j = 0;

    while (i < txt.length()) {
        if (txt[i] == pattern[j]) {
            i++; j++;
        }
        if (j == n) {
            indices.push_back(i - j);
            j = lps[j - 1];
        } else {
            if (i < txt.length() && txt[i] != pattern[j]) {
                if (j != 0) j = lps[j - 1];
                else i++;
            }
        }
    }
    return indices;
}