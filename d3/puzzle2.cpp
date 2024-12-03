#include <iostream>
#include <regex>
#include <string>

using namespace std;

void recoveredMul(string str, int& ans){
    regex pattern (R"(mul\((\d+),(\d+)\))");
    sregex_iterator begin(str.begin(), str.end(), pattern);
    sregex_iterator end;

    for (auto it = begin; it != end; ++it) {
        smatch match = *it;
        int num1 = stoi(match[1]);
        int num2 = stoi(match[2]);

        ans += num1*num2;
    }
}

int reviewedMul(){
    string file = "";
    string line;
    while (getline(cin, line)){
        file += line;
    }
    regex pattern_do_dont (R"((don't\(\))|(do\(\)))");

    sregex_iterator begin(file.begin(), file.end(), pattern_do_dont);
    sregex_iterator end;

    int ans = 0;
    bool enabled = true;
    int start = 0;
    for (auto it = begin; it != end; ++it) {
        smatch match = *it;
        string command = match[0];
        int position = match.position(0);

        if (enabled){
            recoveredMul(file.substr(start, position - start), ans);
        }
        start = position + command.length();
        if (command == "do()")
            enabled = true;
        else
            enabled = false;
    }
    return ans;
}

int main(){
    int reviewed_mul = reviewedMul();
    cout << reviewed_mul;
    return 0;
}