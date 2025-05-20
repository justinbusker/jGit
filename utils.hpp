#ifndef UTILS_HPP
#define UTILS_HPP

#include <iostream>

extern std::string jgit_path;

bool check_init();

std::string get_file_contents(std::string file_path);

void create_file(std::string file_name, std::string file_path);

void write_to_file(std::string file_path, std::string content, bool append);

std::string gen_sha(std::string input);

std::string get_jgit_path(std::string path);

bool is_jgit_dir(std::string path);

bool is_file_tracked(std::string file);

void add_to_tracked(std::string path, std::string sha);

std::string get_parent_hash();

std::vector<std::string> split(std::string file_path, char delimiter);
#endif
