// MZMTIN002

#include <string>
#include <map>
#include <vector>
#include <iostream>

using namespace std;

double P() {
    return 1.0;
}

int R(const string& s, const string& s2) {
    if (s == "s2" && s2 == "s3") {
        return 50;
    }
    else if (s == "s6" && s2 == "s3") {
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

vector<string> nextStates(const string& s) {
    if (s == "s1") {
        return {"s2", "s4"};
    }
    else if (s == "s2") {
        return {"s1", "s3", "s5"};
    }
    else if (s == "s3") {
        return {};
    }
    else if (s == "s4") {
        return {"s1", "s5"};
    }
    else if (s == "s5") {
        return {"s2", "s4", "s6"};
    }
    return {"s3", "s5"};
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
            double old_max = 0.0;
            for (auto action : possibleActions(state.first)) {
                double new_max = 0.0;
                for (auto ns : nextStates(state.first)) {

                }
//                best_EV = EV > best_EV ? EV : best_EV;
            }
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