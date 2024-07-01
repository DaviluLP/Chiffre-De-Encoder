//
// Created by ludow on 11.03.2024.
//

#pragma once

#include <string>

[[nodiscard]] std::string encoding(std::string text, std::string key);

[[nodiscard]] std::string decoding(std::string text, std::string key);
