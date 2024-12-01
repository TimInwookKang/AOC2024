#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

int similarityScore(){
    vector<int> left;
    vector<int> right;
    unordered_map<int, int> umap;
    int num1; int num2;
    while (cin >> num1 >> num2){
        left.push_back(num1);
        right.push_back(num2);
    }

    for (int i : right){
        umap[i]++;
    }
    int sum = 0;
    for (int i : left){
        sum += umap[i]*i;
    }
    return sum;
}

int main(){
    int similarity_score = similarityScore();
    cout << similarity_score;
    return 0;
}