#include <iostream>
#include "utils.hpp"

void create_blob(std::string file_path){
	std::string file_contents = get_file_contents(file_path);
	std::string blob_header = "blob " + std::to_string(file_contents.size()) + '\0';
	std::string blob = blob_header + file_contents;
	std::cout << blob;

	std::cout << gen_sha(blob) << std::endl;

}
