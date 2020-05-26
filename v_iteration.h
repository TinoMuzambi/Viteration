// MZMTIN002

#ifndef ASSIGNMENT_6_V_ITERATION_H
#define ASSIGNMENT_6_V_ITERATION_H

#include <string>
#include <map>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;
namespace MZMTIN002 {
    class v_iteration {
    private:
        double GAMMA;
        double THETA;
        map<string, double> values;
    public:
        int R(string s, char a);    // Reward function. Reward for being in state s and taking action a.

        vector<char> possibleActions(string s);     // Returns all possible actions from state s

        string nextState(string s, char a);     // Returns next state from current state given action a.

        bool convergedEnough(map<string, double> values, map<string, double> oldValues);    // Determine when to stop iterations by some value THETA.

        void doValueIteration();    // Iterate to find optimum values for each state
    };
}
#endif //ASSIGNMENT_6_V_ITERATION_H
