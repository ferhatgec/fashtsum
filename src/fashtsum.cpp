// MIT License
//
// Copyright (c) 2021 Ferhat Geçdoğan All Rights Reserved.
// Distributed under the terms of the MIT License.
//
// I know there's no compression algorithm.
// That's just an example.

#include "../include/fashtsum.hpp"
#include "../libs/fasht/include/fasht.hpp"
#include <fstream>

void FashtSum::read(const std::string filename) noexcept {
    std::ifstream input(filename);

    for(std::string temp; std::getline(input, temp);
        this->data.append(temp + "\n"))
        ; input.close();

    this->filename = filename;
}

bool FashtSum::check() noexcept {
    if(!this->data.empty()) {
        this->sum = fasht::h(this->data);

        std::cout << this->filename << " \x1b[1;93m" << this->sum << "\x1b[0m\n";

        return true;
    } return false;
}

int main(int argc, char** argv) noexcept {
    if(argc < 2) {
        std::cout << "fashtsum - front-end of fasht\n" <<
                    argv[0] << " file1 ...\n";
        return 1;
    }

    std::vector<std::string> args(argv, argv + argc); args.erase(args.begin());

    FashtSum init;

    for(auto file : args) {
        init.read(file);
        init.check();

        init.data.clear();
        init.sum.clear();
        init.filename.clear();
    }
}