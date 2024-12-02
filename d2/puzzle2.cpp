#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

// int helper(unordered_map<int,int> & umap, vector<int> & report, int& removed, int j){
//     //check if it's a duplicate
//     if (umap[report[j]]){
//         if (removed >= 0)
//             return -1;
//         removed = j;
//     }

//     //calculate difference with the previous value
//     int diff;
//     if (removed == j-1){
//         if (j == 1)
//             return 0;
//         else
//             diff = report[j] - report[j-2];
//     }else
//         diff = report[j] - report[j-1];
    

//     //if the absolute value of the difference is greater than 3, remove one of the elements'
//     if (abs(diff) > 3){
//         if (removed>= 0){
//             return -1;
//         }

//         if (j < report.size()-1 && abs(report[j+1]- report[j-1]) <= 3){
//             removed = j;
//             return 0;
//         } else if (j > 1 && abs(report[j]- report[j-2]) <=3){
//             removed = j-1;
//            return 0;
//         } else{
//             return -1;
//         }
//     }

//     return 1;
// }

// int problemDampener(){
//     string line;
//     vector<vector<int>> reports;
//     while (getline(cin, line)){
//         stringstream ss(line);
//         int num;
//         vector<int> report;
//         while (ss >> num){
//             report.push_back(num);
//         }
//         reports.push_back(report);
//     }

//     int ans = 0;
//     int diff;
//     unordered_map<int,int> umap;
//     for (int i = 0; i < reports.size(); i++){
//         umap.clear();
//          int n = reports[i].size();
//         if (n <= 2){
//             ans++;
//             continue;
//         }
//         umap[reports[i][0]] = 1;
//         int removed = -1; int increasing = -1; bool halt = false;

//         for (int j = 1; j < 3; j++){
//             int status = helper(umap, reports[i], removed, j);
//             if (status == -1){
//                 halt = true;
//                 break;
//             } else if (status == 0){
//                 continue;
//             } else{
//                 if (j-1 == removed){
//                     if (j > 1 && increasing == -1)
//                         increasing = reports[i][j] > reports[i][j-2];
//                     else if ((increasing == 0 && reports[i][j] > reports[i][j-2]) || (increasing == 1 && reports[i][j] < reports[i][j-2])){
//                         if (n == 3){
//                             halt = true;
//                             break;
//                         }
//                         bool inc = reports[i][j+1] > reports[i][j];
//                         if (reports[i][j-2] < reports[i][j] == inc){
//                             removed = 
//                         }
//                     }
//                 } else{
//                     increasing = reports[i][j] < reports[i][j-1];
//                 }
//             }

//         }
//         if (!halt){
//             for (int j = 1; j < n; j++){

//                 int status = helper(umap, reports[i], removed, j);
//                 umap[reports[i][j]] = 1;

//             }
//         }
//     }
//     return ans;
// }


bool puzzle1Algo(vector<int> report, int skip){
    bool increasing;
    int diff;
    if (report.size() <= 1)
        return true;
    
    int start = 2;
    if (skip == 0)
        increasing = report[1] < report[2];
    else if (skip == 1)
        increasing = report[0] < report[2];
    else{
        increasing = report[0] < report[1];
        start = 1;
    }

    for (int j = start; j < report.size(); j++){
        if (j == skip)
            continue;
        if (j-1 == skip){
            diff = report[j] - report[j-2];
        }else
            diff = report[j] - report[j-1];
        
        if (increasing){
            if (diff < 0 )
                return false;
        } else{
            if (diff > 0)
                return false;
        }
        diff = abs(diff);
        
        if (diff > 3 || diff < 1)
            return false;
    }
    return true;
}


int problemDampener_brute(){
    string line;
    vector<vector<int>> reports;
    while (getline(cin, line)) {
        stringstream ss(line);       // Create a stringstream to parse the line
        int num;
        vector<int> report;
        while (ss >> num) {
            report.push_back(num);
        }
        reports.push_back(report);
    }

    int ans = 0;
    bool increasing; int diff;
    for (int i = 0; i < reports.size(); i++){
        if (reports[i].size() <= 2){
            ans++;
            continue;
        }
        for (int k = 0; k < reports.size(); k++){
            if (puzzle1Algo(reports[i], k)){
                ans++;
                break;
            }
        }
    }
    return ans;
}

int main(){
    int problem_dampener = problemDampener_brute();
    cout << problem_dampener;
    return 0;
}