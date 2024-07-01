#include <iostream>
#include <string>
#include "Encoder.h"

int main()
{
    std::string input_text = "eqey qbxm mbia mwxm xues mcms bqix wuew ahwy mv";
    std::string input_key = "hide";

    auto new_text = encoding(input_text, input_key);

    std::cout << new_text << "\n\n\n";

    std::string input_text2;
    std::cout << "Please insert a text: ";
    std::getline(std::cin, input_text2);

    std::string input_key2;
    std::cout << "Please insert a key: ";
    std::getline(std::cin, input_key2);
    std::cout << "\n\n";

    auto new_text2 = decoding(input_text2, input_key2);
    std::cout << new_text2 << '\n';
}
