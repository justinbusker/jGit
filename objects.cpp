#include <iostream>
#include "utils.hpp"
#include <filesystem>

void create_object(std::string file_path, std::string type){
	std::string file_contents = get_file_contents(file_path);
	std::string object_header = type + std::to_string(file_contents.size()) + '\0';
	std::string object = object_header + file_contents;
	std::cout << object;
	std::string sha_code = gen_sha(object);
	std::filesystem::create_directories("./.jgit/objects/" + sha_code.substr(0,2));
	write_to_file("./.jgit/objects/" + sha_code.substr(0,2) + "/" + sha_code.substr(2), object);
}

void create_blob(std::string file_path){
	create_object(file_path, "blob");
}

void create_commit(std::string file_path){
	create_object(file_path, "commit");
}
