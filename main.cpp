#include "jgit.hpp"
#include "utils.hpp"
#include "objects.hpp"
#include <iostream>

using namespace jgit;

int main(int argc, char* argv[]){
	std::string command = argv[1];

	if (command == "init"){
		init();
	} else if (command == "add"){
		add(argv[2]);
	}
	return 0;
}
