// MIT License
//
// Copyright (c) 2021 Ferhat Geçdoğan All Rights Reserved.
// Distributed under the terms of the MIT License.
//

#ifndef FASHTSUM_FASHTSUM_HPP
#define FASHTSUM_FASHTSUM_HPP

#include <iostream>
#include <string>

class FashtSum {
public:
    std::string filename, data, sum;
public:
    FashtSum() = default;
    ~FashtSum()= default;

    void read(const std::string filename) noexcept;
    bool check() noexcept;
};

#endif // FASHTSUM_FASHTSUM_HPP
