#include <iostream>
#include <cmath>
#include <iomanip>

bool assertEqualInt(int actual, int expected, const char* name, int testNo) {
    if (actual == expected) {
        std::cout << "Passed Test " << testNo << " (" << name << ") Result: " << actual << "\n";
        return true;
    }
    std::cout << "Failed Test " << testNo << " (" << name << ") "
        << "Expected " << expected << " but got " << actual << "\n";
    return false;
}

/*
    eps is the tolerance, how close the result has to be to the expected value to count as a pass.
    It's needed because double arithmetic is usually not exact.

*/


bool assertNear(double actual, double expected, double eps, const char* name, int testNo) {
    if (std::fabs(actual - expected) <= eps) {
        std::cout << "Passed Test " << testNo << " (" << name << ") Result: " << actual << "\n";
        return true;
    }
    std::cout << "Failed Test " << testNo << " (" << name << ") "
        << "Expected " << expected << " but got " << actual << "\n";
    return false;
}

int isMultiple(int first, int second);
int max3(int, int, int);
double triangleArea(double, double);
double fahrenheitToC(double);
int isValidTriangle(double, double, double);

int main() {
    std::cout << std::fixed << std::setprecision(6);
    int t = 1;

    assertEqualInt(isMultiple(12, 4), 1, "isMultiple(12,4)", t++);
    assertEqualInt(isMultiple(12, 5), 0, "isMultiple(12,5)", t++);
    assertEqualInt(isMultiple(-12, 4), 1, "isMultiple(-12,4)", t++);
    assertEqualInt(isMultiple(7, 0), 0, "isMultiple(7,0)", t++);

    assertEqualInt(max3(3, 9, 2), 9, "max3(3,9,2)", t++);
    assertEqualInt(max3(-2, -5, -1), -1, "max3(-2,-5,-1)", t++);
    assertEqualInt(max3(7, 7, 1), 7, "max3(7,7,1)", t++);

    assertNear(triangleArea(3.0, 4.0), 6.0, 1e-9, "triangleArea(3,4)", t++);
    assertNear(triangleArea(5.0, 3.0), 7.5, 1e-9, "triangleArea(5,3)", t++);
    assertNear(triangleArea(-3.0, 4.0), 0.0, 1e-9, "triangleArea(-3,4)", t++);
    assertNear(triangleArea(-3.0, -4.0), 0.0, 1e-9, "triangleArea(-3,-4)", t++);

    assertNear(fahrenheitToC(32.0), 0.0, 1e-9, "fahrenheitToC(32)", t++);
    assertNear(fahrenheitToC(212.0), 100.0, 1e-9, "fahrenheitToC(212)", t++);
    assertNear(fahrenheitToC(98.6), 37.0, 1e-9, "fahrenheitToC(98.6)", t++);

    assertEqualInt(isValidTriangle(3.0, 4.0, 5.0), 1, "isValidTriangle(3,4,5)", t++);
    assertEqualInt(isValidTriangle(1.0, 2.0, 3.0), 0, "isValidTriangle(1,2,3) degenerate", t++);
    assertEqualInt(isValidTriangle(1.0, 10.0, 2.0), 0, "isValidTriangle(1,10,2)", t++);
    assertEqualInt(isValidTriangle(-3.0, 4.0, 5.0), 0, "isValidTriangle(-3,4,5) invalid side", t++);

    return 0;
}

int isMultiple(int a, int b) {
    if(b == 0) return 0;
    if(a % b == 0){
        return 1;
    }
    return 0;
}

int max3(int a, int b, int c) {
    int max = a;

    if (b > max) max = b;
    if (c > max) max = c;

    return max;
}

double triangleArea(double base, double height) {
    if(base <= 0 || height <= 0) return 0.0;
    return (base * height) / 2;
}

double fahrenheitToC(double f) {

    return (f - 32.0) * 5.0 / 9.0;
}

int isValidTriangle(double a, double b, double c) {
    return a > 0.0 && b > 0.0 && c > 0.0 && a+b > c && a+c > b && b+c > a;
}