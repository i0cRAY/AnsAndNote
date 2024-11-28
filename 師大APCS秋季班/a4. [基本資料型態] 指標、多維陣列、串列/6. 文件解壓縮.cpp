#include <bits/stdc++.h>
using namespace std;

bool isAlpha(char c) {
    return isalpha(c);
}

string decompress(vector<string> &lines) {
    vector<string> words;
    string res = "";

    for (const string &line : lines) {
        size_t i = 0;
        while (i < line.size()) {
            if (isdigit(line[i])) {
                string num = "";
                while (i < line.size() && isdigit(line[i])) {
                    num += line[i++];
                }
                int idx = stoi(num) - 1;
                if (idx >= 0 && idx < words.size()) {
                    res += words[idx];
                    string word = words[idx];
                    words.erase(words.begin() + idx);
                    words.insert(words.begin(), word);
                }
            } else if (isAlpha(line[i])) {
                string word = "";
                while (i < line.size() && isAlpha(line[i])) {
                    word += line[i++];
                }
                res += word;
                words.insert(words.begin(), word);
            } else {
                res += line[i++];
            }
        }
        res += '\n';
    }
    return res;
}

int main() {
    vector<string> lines;
    string line;

    while (getline(cin, line)) {
        if (line == "0") break;
        lines.push_back(line);
    }

    cout << decompress(lines);
    return 0;
}
