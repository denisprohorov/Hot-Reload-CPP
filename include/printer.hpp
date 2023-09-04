#pragma once
#include "memory"

class Printer {
public:
    Printer() {}

    virtual ~Printer() {}

    virtual void print() const = 0;
};

typedef std::unique_ptr<Printer> create_t();
