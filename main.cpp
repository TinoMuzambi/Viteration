// MZMTIN002

#include <string>
#include <map>
#include <vector>
#include <iostream>

using namespace std;

double P() {
    return 1.0;
}

int R(int s, char a) {
    if (s == 1 && a == 'R') {
        return 50;
    }
    else if (s == 5 && a == 'U') {
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

vector<char> possibleActions(int s) {
    if (s == 0) {
        return {'D', 'R'};
    }
    else if (s == 1) {
        return {'D', 'L', 'R'};
    }
    else if (s == 2) {
        return {};
    }
    else if (s == 3) {
        return {'U', 'R'};
    }
    else if (s == 4) {
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

double valueFunction(int state, vector<double> values) {
    for (int i = 0; i < values.size(); ++i) {
        double currMax = 0;
        for (auto action : possibleActions(i)) {

        }
    }
}

int main() {
    vector<double> values = {0, 0, 0, 0, 0, 0};

    return 0;
}