//https://practice.geeksforgeeks.org/problems/rearrange-characters/0

#include <iostream>
#include <map>
using namespace std;

map <char, int> Freq;
bool rearrangeable (string s)
{
    Freq.clear();
    for (char ch: s)
        Freq[ch]++;
    int max_freq = 0;
    for (auto& m: Freq)
        max_freq = max (max_freq, m.second);

    return max_freq <= (s.size() + 1) / 2;
}

int main() {
    int N; cin >> N;
    for (int i = 0; i < N; i++)
    {
        string s; cin >> s;
        cout << rearrangeable (s) << endl;
    }
	return 0;
}
