#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;

int main() {
    string S;
    cin >> S;

    unordered_map<char, int> freq;
    for (char c : S) {
        freq[c]++; 
    }

    int impares = 0;
    for (auto &p : freq) {
        if (p.second % 2 != 0) {
            impares++;
        }
    }

    if (impares <= 1) {
        cout << "Sim" << endl;
    } else {
        cout << "Nao" << endl;
    }

    return 0;
}