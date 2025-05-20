#include <iostream>
#include <filesystem>
#include <fstream>
#include "utils.hpp"
#include "objects.hpp"

namespace jgit {

int init(){
	if (check_init()){
		std::cerr << "jgit already initialized!" << std::endl;
		return 1;
	}
	std::filesystem::create_directories("./.jgit/objects");
	std::filesystem::create_directories("./.jgit/refs/heads");
	std::filesystem::create_directories("./.jgit/logs");

	create_file("HEAD", "./.jgit/");
	create_file("TRACKED", "./.jgit/");
	create_file("COMMIT_MSG", "./.jgit/");

	// file of all commits parent -> commit
	create_file("HEAD", "./.jgit/logs/");
	
	// current commit
	create_file("main", "./.jgit/refs/heads/");

	return 0;
}

int commit(std::string commit_msg){
	if(!check_init()){
		std::cerr << "Initialize jGit first!" << std::endl;
		return 1;
	}
	write_to_file(".jgit/COMMIT_MSG", commit_msg, false);
	return 0;
}

int add(std::string path){
	if(std::filesystem::is_directory(path)){
		std::cout << "Adding a directory" << std::endl;
	} else {
		std::cout << "adding file" << std::endl;
		create_blob(path);
	}
}

int status(){

}




}
