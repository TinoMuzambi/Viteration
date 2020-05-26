// MZMTIN002

#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

double P() {
    return 1.0;
}

int R(const string& s, char a, const string& s2) {
    if (s == "s2" && s2 == "s3") {
        return 50;
    }
    else if (s == "s6" && s2 == "s3") {
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


    }

    return 0;
}