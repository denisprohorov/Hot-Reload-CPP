#include "printer.hpp"
#include <iostream>
#include <dlfcn.h>
#include <sys/stat.h>

class LoaderLib {
private:
    struct stat t_stat;

    time_t lastCreateTime = 0;
    void *lib = nullptr;
    create_t *create_lib_obj = nullptr;

    std::string libFileName;

public:
    LoaderLib(std::string_view libFileName) : libFileName(libFileName) {}

    ~LoaderLib(){
        if (lib) { dlclose(lib); }
    }

    std::unique_ptr<Printer> load_create() {
        stat(libFileName.c_str(), &t_stat);
        if (!lib || lastCreateTime != t_stat.st_ctime) {
            std::cout << "Load lib: " << libFileName << std::endl;
            if (lib) { dlclose(lib); }

            lib = dlopen(libFileName.c_str(), RTLD_NOW);
            if (!lib) {
                std::cerr << "Cannot load from " << libFileName << " library: " << dlerror() << '\n';
                return nullptr;
            }
            // reset errors
            dlerror();
            create_lib_obj = (create_t *) dlsym(lib, "create");
            const char *dlsym_error = dlerror();
            if (dlsym_error) {
                std::cerr << "Cannot load from " << libFileName << "symbol create: " << dlsym_error << '\n';
                return nullptr;
            }
            lastCreateTime = t_stat.st_ctime;
        }

        std::unique_ptr<Printer> poly = create_lib_obj();
        return std::move(poly);
    }
};

int main() {
    LoaderLib printerlib("libhot_reloading.so");
    LoaderLib printerlib2("libhot_reloading2.so");

    for (int i = 0;; ++i) {
        std::cout << "Enter library 0 (lib1) or 1 (lib2)" << std::endl;
        bool action;
        std::cin >> action;
        LoaderLib *loader;
        if (!action) loader = &printerlib;
        else loader = &printerlib2;
        std::unique_ptr<Printer> printer = loader->load_create();
        if(!printer){
            std::cout << "Can't load lib. Action: " << action << std::endl;
            continue;
        }
        printer->print();
    }
}