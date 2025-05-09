#ifndef UTILS_HPP
#define UTILS_HPP

#include <iostream>

bool check_init();

std::string get_file_contents(std::string file_path);

void create_file(std::string file_name, std::string file_path);

void write_to_file(std::string file_path, std::string content);

std::string gen_sha(std::string input);

#endif
