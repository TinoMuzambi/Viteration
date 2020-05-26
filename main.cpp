// MZMTIN002

#include <string>
#include <unordered_map>
#include <vector>

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

vector<string> nextStates(const string& s, char a) {
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

bool convergedEnough(unordered_map<string, int> oldValues, unordered_map<string, int> values, double GAMMA) {
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
    unordered_map<string, int> values; // Initialising
    values["s1"] = 0;
    values["s2"] = 0;
    values["s3"] = 0;
    values["s4"] = 0;
    values["s5"] = 0;
    values["s6"] = 0;

    vector<char> actions;
    actions.push_back('L');
    actions.push_back('R');
    actions.push_back('U');
    actions.push_back('D');

    double GAMMA = 0.8;
    bool converged = false;

    while (!converged) {
        unordered_map<string, int> oldValues = values;
        for (auto state : values) {
            double best_EV = 0.0;
            for (auto action : possibleActions(state.first)) {
                double EV = 0.0;
                for (auto ns : nextStates(state.first, action)) {
                    EV += P() * oldValues[ns];
                }
                best_EV = EV > best_EV ? EV : best_EV;
            }
            values[state.first] = R2(state.first) + GAMMA * best_EV;
        }

    }

    return 0;
}