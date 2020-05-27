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
    cout << "Optimal values:" << endl;
    vIteration.doValueIteration();

    cout << "\n2. Optimal policy:" << endl;
    vIteration.getOptPolicy();

    cout << "\n3. It is possible to change the reward function such that V* changes"
            "\nbut the optimal policy remains unchanged. As long as the reward for"
            "\ngoing from s6 to s3 is at least 1.58 times the reward for going from"
            "\ns2 to s3, the optimal values will change and the policy will remain"
            "\nthe same. For example, if we change the reward for going from s6 to"
            "\ns3 to 79 (1.58 * 50), the optimal values are:"
            "\ns1 - 40.45"
            "\ns2 - 50.56"
            "\ns3 - 0"
            "\ns4 - 50.56"
            "\ns5 - 63.2"
            "\ns6 - 79"
            "\nbut the optimal policy remains unchanged." << endl;

    return 0;
}