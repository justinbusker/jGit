#include "jgit.hpp"
#include "utils.hpp"
#include "objects.hpp"
#include <iostream>

using namespace jgit;

int main(){
	create_blob("test.txt");
	commit("test commit");
	commit("another commit");
	return 0;
}
