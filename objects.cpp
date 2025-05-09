#include <iostream>
#include "utils.hpp"
#include <filesystem>

void create_blob(std::string file_path){
	std::string file_contents = get_file_contents(file_path);
	std::string blob_header = "blob " + std::to_string(file_contents.size()) + '\0';
	std::string blob = blob_header + file_contents;
	std::cout << blob;
	std::string sha_code = gen_sha(blob);
	std::filesystem::create_directories("./.jgit/objects/" + sha_code.substr(0,2));
	write_to_file("./.jgit/objects/" + sha_code.substr(0,2) + "/" + sha_code.substr(2), blob);
}


