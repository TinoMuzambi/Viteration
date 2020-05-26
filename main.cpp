// MZMTIN002

#include <string>
#include <map>
#include "v_iteration.h"

using namespace std;

int main() {
    map<string, double> values; // Initialising values of states to be 0.
    values["s1"] = 0;
    values["s2"] = 0;
    values["s3"] = 0;
    values["s4"] = 0;
    values["s5"] = 0;
    values["s6"] = 0;

    double GAMMA = 0.8; // Setting parameters for value iteration.
    double THETA = 1e-4;

    MZMTIN002::v_iteration vIteration(GAMMA, THETA, values);
    vIteration.doValueIteration();

    return 0;
}