#ifndef UTILS_HPP
#define UTILS_HPP

#include <iostream>
#include <filesystem>
#include <fstream>
#include <cryptopp/cryptlib.h>
#include <cryptopp/hex.h>
#include <cryptopp/files.h>
#include <cryptopp/filters.h>
#include <cryptopp/sha.h>

void create_file(std::string file_name, std::string file_path);

std::string gen_sha(std::string input);

#endif
