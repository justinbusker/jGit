#include "jgit.hpp"
#include "utils.hpp"
#include "objects.hpp"
#include <iostream>

using namespace jgit;

int main(){
	std::cout << get_jgit_path("./");
	return 0;
}
