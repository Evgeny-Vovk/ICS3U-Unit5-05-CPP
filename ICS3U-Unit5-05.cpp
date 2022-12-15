// Copyright(c) 2022 Evgeny Vovk All rights reserved.
//
// Created by : Evgeny Vovk
// Created on : December 2022
// ICS3U-Unit5-05.cpp File, learning functions with parameters in C++.

#include <algorithm>
#include <iostream>
#include <string>

std::string mailAddress(
    std::string fullName, std::string streetNumber, std::string streetName,
    std::string city, std::string province, std::string postalCode,
    int apartmentNumberInt = 0, std::string apartmentNumber = "") {
    // variables
    std::string(address);
    address = fullName + "\n";
    if (apartmentNumberInt != 0) {
        address += apartmentNumber + "-";
    }
    address += streetNumber + " " + streetName + "\n" +
    city + " " + province + " " + postalCode;

    std::for_each(address.begin(), address.end(),
    [](char& c) { c = ::toupper(c); });

    return address;
}

int main() {
    // creating variables
    std::string(apartmentNumber) = "";
    std::string(fullName);
    std::string(question);
    std::string(streetNumber);
    std::string(streetName);
    std::string(city);
    std::string(province);
    std::string(postalCode);
    std::string(address);
    int apartmentNumberInt;
    int streetNumberInt;

    // input
    std::cout << "full name: ";
    getline(std::cin, fullName);
    std::cout << "question: ";
    getline(std::cin, question);
    std::for_each(question.begin(), question.end(),
    [](char& c) { c = ::toupper(c); });
    if (question == "Y" || question == "YES") {
        std::cout << "apartment number: ";
        getline(std::cin, apartmentNumber);
    } else {
        apartmentNumberInt = 0;
    }
    std::cout << "street number: ";
    getline(std::cin, streetNumber);
    std::cout << "street name: ";
    getline(std::cin, streetName);
    std::cout << "city: ";
    getline(std::cin, city);
    std::cout << "province: ";
    getline(std::cin, province);
    std::cout << "postal code: ";
    getline(std::cin, postalCode);
    std::cout << "\n";

    // process
    try {
        if (apartmentNumberInt != 0) {
            apartmentNumberInt = std::stoi(apartmentNumber);
        }
        streetNumberInt = std::stoi(streetNumber);

        address = mailAddress(fullName, streetNumber,
        streetName, city, province, postalCode, apartmentNumberInt,
        apartmentNumber);
        std::cout << address;
    } catch (std::invalid_argument) {
        std::cout << "Invalid input, please try again.";
    }

    std::cout << "\n\n\nDone.\n";
}
