#include <iostream>
#include "distance_calc.hpp"
#include <string>
#include <fstream>

int main(int argc, char **argv) {
    if(argc == 1) {
        std::cerr << "Usage: --file filename --file filename [--print_length]" << std::endl;
        return EXIT_FAILURE;
    }
    std::string file1_name, file2_name;
    bool print_file_lenght = false;
    for(int i = 1; i < argc; ++i) {
        std::string arg(argv[i]);
        if(arg == "--file") {
            ++i;
            if(i == argc) {
                std::cerr << "Expected an argument after --file." << std::endl;
                return EXIT_FAILURE;
            }
            if(file1_name.empty()) {
                file1_name = argv[i];
            }
            else if(file2_name.empty()) {
                file2_name = argv[i];
            }
            else {
                std::cerr << "Can't compare more than 2 files." << std::endl;
                return EXIT_FAILURE;
            }
        }
        else if(arg == "--print_length") {
            print_file_lenght = true;
        }
        else {
            std::cerr << "Unknown argument " << arg << std::endl;
            std::cerr << "Usage: --file filename --file filename [--print_length]" << std::endl;
            return EXIT_FAILURE;
        }
    }
    std::ifstream file1(file1_name, std::ios::binary), file2(file2_name, std::ios::binary);
    if(!file1.is_open() || !file2.is_open()) {
        if(!file1.is_open()) {
            std::cerr << "Wrong usage! Argument " << file1_name << " should be a file." << std::endl;
        }
        if(!file2.is_open()) {
            std::cerr << "Wrong usage! Argument " << file2_name << " should be a file." << std::endl;
        }
        return EXIT_FAILURE;
    }
    using it = std::istreambuf_iterator<char>;
    std::cout << "### Bit humming distance between " << file1_name << " and " << file2_name << " ###" << std::endl;
    std::cout << calculate_distance(it(file1), it(), it(file2), it()) << std::endl;
    if(print_file_lenght) {
        file1.clear();
        file1.seekg(0, std::ios::beg);
        std::cout << "### File " << file1_name << " length ###" << std::endl;
        std::cout << std::distance(it(file1), it()) << std::endl;
        file2.clear();
        file2.seekg(0, std::ios::beg);
        std::cout << "### File " << file2_name << " length ###" << std::endl;
        std::cout << std::distance(it(file2), it()) << std::endl;
    }
    return EXIT_SUCCESS;
}
