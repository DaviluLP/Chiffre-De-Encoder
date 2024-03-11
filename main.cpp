#include <iostream>
#include "Encoder.h"

int main()
{
    char inputText[] = {"eqey qbxm mbia mwxm xues mcms bqix wuew ahwy mv"};
    char inputKey[] = {"hide"};

    Encoder* encoder = new Encoder;

    encoder->encoding(inputText, inputKey);
    return 0;
}
