#include "jgit.hpp"
#include "utils.hpp"
#include "objects.hpp"
#include <iostream>

using namespace jgit;

int main(){
	add_to_tracked("./objects.cpp");
	return 0;
}
