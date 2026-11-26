/*
 * Nesne Tabanli Programlama I Lab. - Lab03-B : Thermostat testleri
 *
 * Bu dosyayi DEGISTIRMEYINIZ. Yalnizca 4. gorevi (balanceWith) tamamladiginizda
 * asagidaki BALANCEWITH_TESTLERI degerini 1 yapiniz.
 */

#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

#include "Thermostat.h"

#define BALANCEWITH_TESTLERI 1

// =====================================================================
//   TEST FONKSIYONLARI
// =====================================================================

bool assertEqualBool(bool actual, bool expected, const char* name, int testNo) {
    if (actual == expected) {
        std::cout << "Passed Test " << testNo << " (" << name << ")\n";
        return true;
    }
    std::cout << "Failed Test " << testNo << " (" << name << ") "
        << "Expected " << (expected ? "true" : "false")
        << " but got " << (actual ? "true" : "false") << "\n";
    return false;
}

bool assertEqualString(const std::string& actual, const std::string& expected, const char* name, int testNo) {
    if (actual == expected) {
        std::cout << "Passed Test " << testNo << " (" << name << ")\n";
        return true;
    }
    std::cout << "Failed Test " << testNo << " (" << name << ") "
        << "Expected \"" << expected << "\" but got \"" << actual << "\"\n";
    return false;
}

bool assertNear(double actual, double expected, double eps, const char* name, int testNo) {
    double diff = actual - expected;
    if (diff < 0) {
        diff = -diff; // mutlak deger
    }
    if (diff <= eps) {
        std::cout << "Passed Test " << testNo << " (" << name << ")\n";
        return true;
    }
    std::cout << "Failed Test " << testNo << " (" << name << ") "
        << "Expected " << expected << " but got " << actual << "\n";
    return false;
}

// =====================================================================
//   YARDIMCI FONKSIYONLAR
//   Kurucunun temperature'a deger verip vermedigini her derleyicide
//   yakalamak icin kullanilir. Fonksiyon iki kez cagrilir; ikinci cagrida
//   yeni nesne ayni bellek alaninda olusur. Kurucu temperature'a deger
//   vermezse onceki cagridan kalan 29.5 (ya da anlamsiz bir sayi) gorunur.
// =====================================================================

double newDefaultTemperature() {
    Thermostat thermostat;
    double temperature = thermostat.getTemperature();
    thermostat.setTemperature(29.5);
    return temperature;
}

double newInvalidTemperature() {
    Thermostat thermostat("Test", 99.0);
    double temperature = thermostat.getTemperature();
    thermostat.setTemperature(29.5);
    return temperature;
}

// =====================================================================
//   TESTLER
// =====================================================================

int main() {
    std::cout << std::fixed << std::setprecision(2);
    int t = 1;      // test numarasi
    int passed = 0; // gecen test sayisi
    const double EPS = 1e-6;

    std::cout << "--- Kurucu ve get fonksiyonlari ---\n";
    Thermostat a; // varsayilan kurucu
    Thermostat b("Mutfak", 22.5); // parametreli kurucu
    Thermostat c("Banyo", 35.0); // gecersiz: 30'dan buyuk
    Thermostat d("Ofis", 10.0); // gecersiz: 16'dan kucuk
    passed += assertEqualString(a.getRoom(), "Bilinmiyor", "a.getRoom()", t++);
    passed += assertNear(a.getTemperature(), 20.0, EPS, "a.getTemperature()", t++);
    passed += assertEqualString(b.getRoom(), "Mutfak", "b.getRoom()", t++);
    passed += assertNear(b.getTemperature(), 22.5, EPS, "b.getTemperature()", t++);
    passed += assertEqualString(c.getRoom(), "Banyo", "c.getRoom()", t++);
    passed += assertNear(c.getTemperature(), 20.0, EPS, "c.getTemperature() - gecersiz sicaklik", t++);
    passed += assertNear(d.getTemperature(), 20.0, EPS, "d.getTemperature() - gecersiz sicaklik", t++);

    // Kurucular temperature'a her durumda deger vermeli (bkz. YARDIMCI FONKSIYONLAR)
    newDefaultTemperature();
    double temperature1 = newDefaultTemperature();
    passed += assertNear(temperature1, 20.0, EPS, "yeni Thermostat() -> 20", t++);
    newInvalidTemperature();
    double temperature2 = newInvalidTemperature();
    passed += assertNear(temperature2, 20.0, EPS, "yeni Thermostat(\"Test\", 99) -> 20", t++);

    std::cout << "\n--- setRoom ---\n";
    b.setRoom("Salon");
    passed += assertEqualString(b.getRoom(), "Salon", "b.setRoom(\"Salon\")", t++);

    std::cout << "\n--- setTemperature ---\n";
    passed += assertEqualBool(b.setTemperature(25.0), true, "b.setTemperature(25)", t++);
    passed += assertNear(b.getTemperature(), 25.0, EPS, "b.getTemperature() -> 25", t++);
    passed += assertEqualBool(b.setTemperature(30.0), true, "b.setTemperature(30) - ust sinir", t++);
    passed += assertEqualBool(b.setTemperature(30.5), false, "b.setTemperature(30.5)", t++);
    passed += assertEqualBool(b.setTemperature(15.5), false, "b.setTemperature(15.5)", t++);
    passed += assertNear(b.getTemperature(), 30.0, EPS, "b.getTemperature() degismemeli", t++);
    passed += assertEqualBool(b.setTemperature(16.0), true, "b.setTemperature(16) - alt sinir", t++);
    passed += assertNear(b.getTemperature(), 16.0, EPS, "b.getTemperature() -> 16", t++);

    std::cout << "\n--- increase / decrease ---\n";
    passed += assertEqualBool(b.decrease(0.5), false, "b.decrease(0.5) - 16'nin altina inemez", t++);
    passed += assertEqualBool(b.increase(4.5), true, "b.increase(4.5)", t++);
    passed += assertNear(b.getTemperature(), 20.5, EPS, "b.getTemperature() -> 20.5", t++);
    passed += assertEqualBool(b.increase(0.0), false, "b.increase(0)", t++);
    passed += assertEqualBool(b.increase(-1.0), false, "b.increase(-1)", t++);
    passed += assertEqualBool(b.increase(9.5), true, "b.increase(9.5) - tam 30", t++);
    passed += assertNear(b.getTemperature(), 30.0, EPS, "b.getTemperature() -> 30", t++);
    passed += assertEqualBool(b.increase(0.5), false, "b.increase(0.5) - 30'u asamaz", t++);
    passed += assertEqualBool(b.decrease(14.0), true, "b.decrease(14) - tam 16", t++);
    passed += assertNear(b.getTemperature(), 16.0, EPS, "b.getTemperature() -> 16", t++);
    passed += assertEqualBool(b.decrease(-2.0), false, "b.decrease(-2)", t++);
    passed += assertNear(b.getTemperature(), 16.0, EPS, "b.getTemperature() degismemeli", t++);

    std::cout << "\n--- Her nesnenin kendi verisi vardir ---\n";
    c.increase(1.5);
    passed += assertNear(c.getTemperature(), 21.5, EPS, "c.increase(1.5) sonrasi c", t++);
    passed += assertNear(b.getTemperature(), 16.0, EPS, "b etkilenmemeli", t++);
    passed += assertNear(a.getTemperature(), 20.0, EPS, "a etkilenmemeli", t++);

#if BALANCEWITH_TESTLERI
    std::cout << "\n--- balanceWith (4. gorev) ---\n";
    Thermostat x("Salon", 20.0);
    Thermostat y("Yatak Odasi", 25.0);
    x.balanceWith(y);
    passed += assertNear(x.getTemperature(), 22.5, EPS, "x.balanceWith(y) sonrasi x", t++);
    passed += assertNear(y.getTemperature(), 22.5, EPS, "x.balanceWith(y) sonrasi y", t++);
    Thermostat z("Cocuk Odasi", 16.0);
    x.balanceWith(z);
    passed += assertNear(x.getTemperature(), 19.25, EPS, "x.balanceWith(z) sonrasi x", t++);
    passed += assertNear(z.getTemperature(), 19.25, EPS, "x.balanceWith(z) sonrasi z", t++);
    passed += assertNear(y.getTemperature(), 22.5, EPS, "y etkilenmemeli", t++);
#endif

    int total = t - 1;
    std::cout << "\nSonuc: " << passed << " / " << total << " test gecti.\n";
    if (passed == total) {
#if BALANCEWITH_TESTLERI
        std::cout << "Tebrikler, tum testler gecti!\n";
#else
        std::cout << "Tebrikler! 4. gorev icin BALANCEWITH_TESTLERI degerini 1 yapiniz.\n";
#endif
    }
    return 0;
}