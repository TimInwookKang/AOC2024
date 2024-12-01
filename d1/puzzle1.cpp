#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int sumOfDifference(){
    vector<int> left;
    vector<int> right;
    int num1; int num2;
    while (cin >> num1 >> num2){
        left.push_back(num1);
        right.push_back(num2);
    }
    sort(left.begin(), left.end());
    sort(right.begin(), right.end());

    int sum = 0;
    for (int i = 0; i < left.size(); i++){
        sum += abs(right[i] - left[i]);
    }
    return sum;
}

int main(){
    int sum_of_diff = sumOfDifference();
    cout << sum_of_diff;
    return 0;
}