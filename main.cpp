// MZMTIN002

#include <string>
#include <map>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

double P() {
    return 1.0;
}

int R(const string& s, char a) {
    if (s == "s2" && a == 'R') {
        return 50;
    }
    else if (s == "s6" && a == 'U') {
        return 100;
    }
    return 0;
}

int R2(const string& s) {
    if (s == "s3") {
        return 100;
    }
    return 0;
}

vector<char> possibleActions(const string& s) {
    if (s == "s1") {
        return {'D', 'R'};
    }
    else if (s == "s2") {
        return {'D', 'L', 'R'};
    }
    else if (s == "s3") {
        return {};
    }
    else if (s == "s4") {
        return {'U', 'R'};
    }
    else if (s == "s5") {
        return {'U', 'L', 'R'};
    }
    return {'U', 'L'};
}

string nextState(const string& s, char a) {
    if (s == "s1" && a == 'D') {
        return "s4";
    }
    else if (s == "s1" && a == 'R') {
        return "s2";
    }
    else if (s == "s2" && a == 'D') {
        return "s5";
    }
    else if (s == "s2" && a == 'L') {
        return "s1";
    }
    else if (s == "s2" && a == 'R') {
        return "s3";
    }
    else if (s == "s3") {
        return "";
    }
    else if (s == "s4" && a == 'U') {
        return "s1";
    }
    else if (s == "s4" && a == 'R') {
        return "s5";
    }
    else if (s == "s5" && a == 'U') {
        return "s2";
    }
    else if (s == "s5" && a == 'L') {
        return "s4";
    }
    else if (s == "s5" && a == 'R') {
        return "s6";
    }
    else if (s == "s6" && a == 'U') {
        return "s3";
    }
    return "s5";
}

bool convergedEnough(const map<string, int>& oldValues, const map<string, int>& values, double GAMMA) {
    double sum = 0;
    double sum2 = 0;
    for (const auto& i : oldValues) {
        sum += i.second;
    }
    for (const auto& i : values) {
        sum2 += i.second;
    }
    return sum2 - sum < GAMMA;
}

int main() {
    map<string, int> values; // Initialising
    values["s1"] = 0;
    values["s2"] = 0;
    values["s3"] = 0;
    values["s4"] = 0;
    values["s5"] = 0;
    values["s6"] = 0;

    double GAMMA = 0.8;
    bool converged = false;
    int count = 0;

    while (!converged) {
        map<string, int> oldValues = values;
        for (const auto& state : values) {
            double curr_max = 0.0;
            vector<double> new_max;
            for (auto action : possibleActions(state.first)) {
                double max_neighbour = 0;
                    if (oldValues[nextState(state.first, action)] > max_neighbour) {
                        max_neighbour = oldValues[nextState(state.first, action)] ;
                    }
                new_max.push_back(R(state.first, action) + GAMMA * max_neighbour);
            }
            if (!new_max.empty()) {
                curr_max = *max_element(new_max.begin(), new_max.end());
            }
            values[state.first] = curr_max;
        }
        count++;
        converged = convergedEnough(oldValues, values, GAMMA);
    }

    for (const auto& x : values) {
        cout << x.first << " " << x.second << endl;
    }
    cout << count << endl;

    return 0;
}