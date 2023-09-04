#include "printer.hpp"
#include <iostream>
#include <cmath>

class PrinterCout : public Printer {
public:
    void print() const override {
        std::cout << "print from lib1" << std::endl;
    }
};

extern "C" std::unique_ptr<Printer> create() {
    return std::make_unique<PrinterCout>();
}
