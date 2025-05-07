#include <iostream>
#include <filesystem>
#include <fstream>

namespace jgit {

// "Private" functions
namespace {

void create_file(std::string file_name, std::string file_path){
	std::ofstream file;
	file.open(file_path + file_name);
	file.close();
}

}

int init(){
	if (std::filesystem::exists("./.jgit")){
		std::cerr << "jgit already initialized!" << std::endl;
		return 1;
	}
	std::filesystem::create_directories("./.jgit/objects");
	std::filesystem::create_directories("./.jgit/refs/heads");

	create_file("HEAD", "./.jgit/");

	return 0;
}


}
