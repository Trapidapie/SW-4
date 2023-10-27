#include <iostream>
#include <string>
#include <sstream>
#include <iomanip>
#include <fstream>

std::istream& getInt(std::istream& in, int& i) {
    std::string input;
    bool validInput = false;

    while (!validInput) {
        if (std::getline(in, input)) {
            std::istringstream iss(input);
            if (iss >> i) {
                validInput = true;
            } else {
                std::cout << "Invalid input. Please enter a valid integer value." << std::endl;
            }
        } else {
            in.clear();
            in.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Invalid input. Please enter a valid integer value." << std::endl;
        }
    }
    return in;
}

std::istream& getDouble(std::istream& in, double& d) {
    std::string input;
    bool validInput = false;

    while (!validInput) {
        if (std::getline(in, input)) {
            std::istringstream iss(input);
            if (iss >> d) {
                validInput = true;
            } else {
                std::cout << "Invalid input. Please enter a valid double value." << std::endl;
            }
        } else {
            in.clear();
            in.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Invalid input. Please enter a valid double value." << std::endl;
        }
    }
    return in;
}

double step(int n, int x) {
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
                res *= (x - i);
            }
        } else {
            res = std::numeric_limits<double>::quiet_NaN();
        }
    };
    return res;
}   

int main() {
    std::fstream fout("text.txt");
    int n;
    fout << "Enter the interval value: ";
    getInt(std::cin, n);
    double a;
    fout << "Enter start value: ";
    getDouble(std::cin, a);
    double b;
    fout << "Enter a boundary: ";
    getDouble(std::cin, b);
    double h;
    fout << "Enter a function step: ";
    getDouble(std::cin, h);
    while (a <= b) {
        if (std::isnan(step(n, a))) {
            fout << "The cycle ended because n must be greater than 4" << std::endl;
            break;
        }
        fout << step(n, a) << std::endl;
        a += h;
    }
    fout.close();
    return 0;
}
