#include <iostream>
#include <vector>
#include <sstream>
#include <string>

using namespace std;

int safeReports(){
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
    bool increasing;
    int diff;
    for (int i = 0; i < reports.size(); i++){
        if (reports[i].size() <= 1)
            ans++;
        else
            increasing = reports[i][0] < reports[i][1];

        for (int j = 1; j < reports[i].size(); j++){
            diff = reports[i][j] - reports[i][j-1];
            
            if (increasing){
                if (diff < 0 )
                    break;
            } else{
                if (diff > 0)
                    break;
            }
            diff = abs(diff);
            
            if (diff > 3 || diff < 1)
                break;
            
            if (j == reports[i].size()-1)
                ans++;
        }
    }
    return ans;
}

int main(){
    int number_of_safe_reports = safeReports();
    cout << number_of_safe_reports;
    return 0;
}