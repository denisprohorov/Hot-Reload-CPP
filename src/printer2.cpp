#include "printer.hpp"
#include <iostream>
#include <cmath>

class PrinterCerr : public Printer {
public:
    void print() const override {
        std::cerr << "print from lib2 " << std::endl;
    }
};

extern "C" std::unique_ptr<Printer> create() {
    return std::make_unique<PrinterCerr>();
}
