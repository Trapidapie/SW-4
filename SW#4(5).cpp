#include <iostream>
#include <string>
#include <sstream>

using namespace std;

int genNum(string dscr = "") {
    std::string userInput;
    double numberValue;
    bool validInput = false;

    while (!validInput) {
        std::cout << "Enter value " + dscr + " :";
        std::cin >> userInput;
        std::istringstream iss(userInput);
        if (iss >> numberValue) {
            validInput = true;
        }
        else {
            std::cout << "is NaN" << std::endl;
        }
    }
    return numberValue;
}


double y(int x, int n) {
    double res = 0;
    if (x < 0) {
        for (int i = 1; i < n; i++) {
            for (int j = 1; j < n; j++) {
                res += 1.0 / (x - i - j);
            }
        }
    } else {
        res = 1;
        if (n > 4) {
            for (int i = 0; i < n - 3; i++) {
                res *= (-x - i);
            };
        } else {
            cout << "The cycle ended because n must be greater than 4" << endl;
            return -1;
        }
    };
    return res;
}

int main() {
    int n = genNum("n");
    while (n <= 0) {
        cout << "n must be bigger then 0";
        n = genNum("n");
    };
    auto x = genNum("x");
    auto b = genNum("b");
    auto h = genNum("h");
    double result = 0;
    while (x <= b) {
        cout << y(x, n) << endl;
        x += h;
    }
    return 1;
};
