#include <algorithm>
#include <iostream>
#include <string>
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


double secondTask(double x, int n, double y = 1, int i = 1) {
    if (n >= i) {
        y *= (x + i);
        i++;
        y = secondTask(x, n, y, i);
    }
    return y;
}

struct TaskResult {
    bool success;
    double max;
    double min;
};

TaskResult firstTask(std::vector<double>& vec, double inp) {
    TaskResult result;
    result.success = true;
    
    try {
        vec.push_back(inp);
        //result.max = *std::max_element(vec.begin(), vec.end());
        //result.min = *std::min_element(vec.begin(), vec.end());
        auto max = [](const std::vector<double>& v) {
            double maxValue = v[0];
            for (size_t i = 1; i < v.size(); i++) {
                if (v[i] > maxValue) {
                    maxValue = v[i];
                }
            }
            return maxValue;
        };

        auto min = [](const std::vector<double>& v) {
            double minValue = v[0];
            for (size_t i = 1; i < v.size(); i++) {
                if (v[i] < minValue) {
                    minValue = v[i];
                }
            }
            return minValue;
        };
        result.max = max(vec);
        result.min = min(vec);
    } catch (...) {
        result.success = false;
    }

    return result;
}

int main() {
    double a = genNum("a");
    double b = genNum("b");
    cout << secondTask(a, b) << endl;
    //vector<double> values;
   /* while (true) {
        double inp = genNum("num");
        if(inp)
        {
            TaskResult result = firstTask(values, inp);

            if (!result.success) {
                std::cout << "Error: The entered value is not a number or is outside the valid range" << std::endl;
            } else {
                std::cout << "max: " << result.max << std::endl;
                std::cout << "min: " << result.min << std::endl;
            }
        } else
        {
            break;
        }
        
    }*/

    return 0;
}
