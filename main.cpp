#include <iostream>
#include <string>
#include "Encoder.h"

int main()
{
    std::string input_text = "eqey qbxm mbia mwxm xues mcms bqix wuew ahwy mv";
    std::string input_key = "hide";

    auto new_text = encoding(input_text, input_key);

    std::cout << new_text << '\n';

    char key;
    std::cin >> key;
}
