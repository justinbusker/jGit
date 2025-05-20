#include "jgit.hpp"
#include "utils.hpp"
#include "objects.hpp"
#include <iostream>

using namespace jgit;

int main(int argc, char* argv[]){
	if(argc > 1){
	std::string command = argv[1];

	if (command == "init"){
		init();
	} else if (command == "add"){
		add(argv[2]);
	}
	}

	auto test = split(".jgit/TRACKED", ' ');

	for( auto x : test){
		std::cout << x << std::endl;
	}
	return 0;
}
