#include <iostream>
using namespace std;

int main() {
    int x1, y1, x2, y2, x, y;

    cin >> x1 >> y1 >> x2 >> y2 >> x >> y;

    string result;

    if (x < x1) {
        if (y > y2) {
            result = "NW";
        } else if (y < y1) {
            result = "SW";
        } else {
            result = "W";
        }
    } else if (x > x2) {
        if (y > y2) {
            result = "NE";
        } else if (y < y1) {
            result = "SE";
        } else {
            result = "E";
        }
    } else {
        if (y > y2) {
            result = "N";
        } else if (y < y1) {
            result = "S";
        }
    }

    cout << result << endl;

    return 0;
}
