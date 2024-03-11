
#include <iostream>
#include <cstdint>

#include "Encoder.h"

void Encoder::encoding(char text[], char key[]) {
    std::uint32_t lenText = 0;
    std::uint32_t lenKey = 0;

    while(key[lenKey] != '\0') {
        if(key[lenKey] >= 'a' && key[lenKey] <= 'z') {
            key[lenKey] -= 32;
        }
        ++lenKey;
    }

    ++lenKey;

    std::uint32_t chiffre[lenKey]{};

    while(text[lenText] != '\0') {
        if(text[lenText] >= 'a' && text[lenText] <= 'z') {
            text[lenText] -= 32;
        }
        ++lenText;
    }

    ++lenText;

    char chiffreText[lenText]{};

    std::cout << key << " " << lenKey << " | " << text << " " << lenText << "\n";

    for (std::uint32_t i = 0; i < lenKey; i++) {
        for(std::uint32_t j = 0; j < 26; j++) {
            if('A' + j == key[i]) {
                chiffre[i] = j + 1;
                break;
            }
        }
    }

    std::uint32_t index = 0;
    std::uint32_t chIndex = 0;

    while (text[index] != '\0') {

        if (text[index] >= 'A' && text[index] <= 'Z') {

            chiffreText[index] = text[index];

            for (std::uint32_t i = 0; i < chiffre[chIndex]; i++) {

                --chiffreText[index];

                if(chiffreText[index] < 'A') {
                    chiffreText[index] = 'Z';
                }
            }
            ++chIndex;

            if (chIndex == lenKey -1) {
                chIndex = 0;
            }
        }
        else {
            chiffreText[index] = ' ';
        }

        ++index;
    }

    std::cout << chiffreText << "\n";
}

