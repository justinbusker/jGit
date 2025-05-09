#include <iostream>
#include <filesystem>
#include <fstream>
#include "utils.hpp"

namespace jgit {

int init(){
	if (check_init()){
		std::cerr << "jgit already initialized!" << std::endl;
		return 1;
	}
	std::filesystem::create_directories("./.jgit/objects");
	std::filesystem::create_directories("./.jgit/refs/heads");

	create_file("HEAD", "./.jgit/");

	return 0;
}


}
