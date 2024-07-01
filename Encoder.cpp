
#include <iostream>
#include <cstdint>
#include <string>
#include <vector>

#include "Encoder.h"

static void to_upper_case(std::string& str)
{
    for (auto& c : str)
    {
        if (c >= 'a' && c <= 'z')
        {
            c -= 32;
        }
    }
}

static void index_upper(std::int32_t& index, auto const& size)
{
    ++index;

    if (index >= size)
    {
        index = 0;
    }
}

static void chiffre_generator(std::vector<uint32_t>& chiffre, std::string const& key)
{
    for (auto const& k : key)
    {
        chiffre.push_back(k - 64);
    }
}

std::string encoding(std::string text, std::string key)
{

    // Uppercase Letters
    to_upper_case(text);
    to_upper_case(key);

    std::vector<uint32_t> chiffre;
    chiffre_generator(chiffre, key);

    // Encoding Text
    std::string result{};
    std::int32_t index = 0;
    for (auto c : text)
    {
        if (!isspace(c))
        {
            c -= chiffre[index];
            if (c < 'A')
            {
                c += 26;
            }

            index_upper(index, chiffre.size());
        }

        result += c;
    }

    return result;
}

std::string decoding(std::string text, std::string key)
{
    // Uppercase Letters
    to_upper_case(text);
    to_upper_case(key);

    std::vector<uint32_t> chiffre;
    chiffre_generator(chiffre, key);

    // Decoding Text
    std::string result{};
    std::int32_t index = 0;
    for (auto c : text)
    {
        if (!isspace(c))
        {
            c += chiffre[index];
            if (c > 'Z')
            {
                c -= 26;
            }

            index_upper(index, chiffre.size());
        }

        result += c;
    }

    return result;
}


/*
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
*/
