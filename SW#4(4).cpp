#include <iostream>
#include <vector>
#include <sstream>
using namespace std;

double genNum(string dscr = "") {
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
            std::cout << "it`s NaN" << std::endl;
        }
    }
    return numberValue;
}



inline vector<double> sq(const double a, const double b, const double c) {
    std::vector<double> roots;
    double x1;
    double x2;
    double &root1 = x1;
    double &root2 = x2;
    if (a != 0) {
        auto descr = [a, b, c](){
            return (pow(b, 2) - 4 * a * c);
        };
        x1 = (-b + sqrt(descr())) / (2 * a);
        x2 = (-b - sqrt(descr())) / (2 * a);
        if (descr() > 0) {
            roots = { root1, root2, 2 };
        }
        else if (descr() == 0) {
            roots = { root1, 1 };
        } else {
            roots = { 0 };
        }
        return roots;
    }
    if(b) {
        root1 = -c/b;
        roots = { root1, 1 };
    } else {
        c ? roots = { root1=0, 1} : roots = { -1 };
    }
    return roots;
}

int main()
{
    auto a = genNum("a");
    auto b = genNum("b");
    auto c = genNum("c");
    vector<double> result = sq(a, b, c);
    for(double value: result)
    {
        std::cout << value << " ";
    }
    return 0;
}
