#include <iostream>
#include <regex>
#include <string>

using namespace std;

int recoveredMul(){
    string file = "";
    string line;
    while (getline(cin, line)){
        file += line;
    }

    regex pattern (R"(mul\((\d+),(\d+)\))");
    sregex_iterator begin(file.begin(), file.end(), pattern);
    sregex_iterator end;
    int ans = 0;
    for (auto it = begin; it != end; ++it) {
        smatch match = *it;
        int num1 = stoi(match[1]);
        int num2 = stoi(match[2]);

        ans += num1*num2;
    }
    return ans;
}

int main(){
    int recovered_mul = recoveredMul();
    cout << recovered_mul;
    return 0;
}