#include <iostream>
#include <vector>
#include <fstream>

using namespace std;

double findTheEndOfGarland(vector<double> lights, int n) {
    bool check;
    double left = 0, right = lights[0];
    while (right - left > 0.000001) {
        check = true;
        lights[1] = (right + left) / 2;
        for (int i = 2; i < n; ++i) {
            lights[i] = 2 + 2 * lights[i - 1] - lights[i - 2];
            if (lights[i] < 0) {
                check = false;
                break;
            }
        }
        if (check) {
            right = lights[1];
        } else {
            left = lights[1];
        }
    }
    return lights[n - 1];
}


int main() {
    ifstream in("garland.in");
    ofstream out("garland.out");
    int n;
    double A;
    in >> n >> A;
    vector<double> lights;
    lights.resize(n);
    lights[0] = A;
    out.precision(2);
    out << fixed << findTheEndOfGarland(lights, n);

}