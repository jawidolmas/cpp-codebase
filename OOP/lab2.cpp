#include <iostream>
#include <cmath>
#include <iomanip>
#include <string>

struct Product {
    std::string name;
    int stock;
    double price;
};

bool assertEqualInt(int actual, int expected, const char* name, int testNo) {
    if (actual == expected) {
        std::cout << "Passed Test " << testNo << " (" << name << ") Result: " << actual << "\n";
        return true;
    }
    std::cout << "Failed Test " << testNo << " (" << name << ") "
        << "Expected " << expected << " but got " << actual << "\n";
    return false;
}

bool assertNear(double actual, double expected, double eps, const char* name, int testNo) {
    if (std::fabs(actual - expected) <= eps) {
        std::cout << "Passed Test " << testNo << " (" << name << ") Result: " << actual << "\n";
        return true;
    }
    std::cout << "Failed Test " << testNo << " (" << name << ") "
        << "Expected " << expected << " but got " << actual << "\n";
    return false;
}

double stockValue(Product);
double discountedPrice(Product, double);
int remainingStock(Product, int);
int maxAffordable(Product, double);
double orderTotal(Product, int);

int main() {
    std::cout << std::fixed << std::setprecision(6);
    int t = 1;

    Product p1;
    p1.name = "Kalem";
    p1.stock = 100;
    p1.price = 7.5;

    // As we know struct works as class, the only difference is the private and public, which struct is public. 
    // The reasong that we can see difference in p1, p2, p3 while getting the same result, p2 and p3 is directly initialized as constructor. 
    // So, when we are creating the object, we decalred as well as initiallized the value in it. 
    // Of course, when the order of values like 40, "defter", 32.0 changes, the compiler will throw an error of mismatch.

    Product p2 = {"Defter", 40, 32.0};
    Product p3 = {"Silgi", 0, 4.25};

    assertNear(stockValue(p1), 750.0, 1e-9, "stockValue(p1)", t++);
    assertNear(stockValue(p2), 1280.0, 1e-9, "stockValue(p2)", t++);
    assertNear(stockValue(p3), 0.0, 1e-9, "stockValue(p3) empty stock", t++);

    assertNear(discountedPrice(p2, 25.0), 24.0, 1e-9, "discountedPrice(p2,25)", t++);
    assertNear(discountedPrice(p1, 10.0), 6.75, 1e-9, "discountedPrice(p1,10)", t++);
    assertNear(discountedPrice(p2, 120.0), 32.0, 1e-9, "discountedPrice(p2,120) invalid rate", t++);
    assertNear(discountedPrice(p2, -5.0), 32.0, 1e-9, "discountedPrice(p2,-5) invalid rate", t++);

    assertEqualInt(remainingStock(p2, 15), 25, "remainingStock(p2,15)", t++);
    assertEqualInt(remainingStock(p1, 1), 99, "remainingStock(p1,1)", t++);
    assertEqualInt(remainingStock(p2, 55), 0, "remainingStock(p2,55) more than stock", t++);

    assertEqualInt(maxAffordable(p1, 50.0), 6, "maxAffordable(p1,50)", t++);
    assertEqualInt(maxAffordable(p2, 100.0), 3, "maxAffordable(p2,100)", t++);
    assertEqualInt(maxAffordable(p1, 1000.0), 100, "maxAffordable(p1,1000) limited by stock", t++);

    assertNear(orderTotal(p1, 4), 30.0, 1e-9, "orderTotal(p1,4)", t++);
    assertNear(orderTotal(p1, 10), 67.5, 1e-9, "orderTotal(p1,10) 10% discount", t++);
    assertNear(orderTotal(p1, 49), 330.75, 1e-9, "orderTotal(p1,49) 10% discount", t++);
    assertNear(orderTotal(p1, 50), 300.0, 1e-9, "orderTotal(p1,50) 20% discount", t++);
    assertNear(orderTotal(p2, 41), 0.0, 1e-9, "orderTotal(p2,41) more than stock", t++);

    return 0;
}

double stockValue(Product p) {
    return p.price * p.stock;
}

double discountedPrice(Product p, double percent) {
    if(percent > 100 || percent < 0){
        return p.price;
    } 
    double discount = p.price * (1 - percent / 100);
    return discount;
    
}

int remainingStock(Product p, int sold) {
    if(sold > p.stock){
        return 0;
    }
    int remaining = p.stock - sold;
    return remaining;
}

int maxAffordable(Product p, double budget) {
    int alinabilacak = budget/p.price;
    if(alinabilacak > p.stock){
        return p.stock;
    }
    return alinabilacak;
}

double orderTotal(Product p, int quantity) {
    if(quantity < 0 || quantity > p.stock) return 0.0;
    double discount  = 0.0;

    if(quantity >= 50){
         discount = 20.0;
    }else if(quantity >= 10){
        discount = 10.0;
    }
    return p.price * quantity * (1.0-discount/100.0);
}