#ifndef JGIT_HPP
#define JGIT_HPP
#include <iostream>

namespace jgit{
	int init();
	int commit(std::string commit_msg);
	int add(std::string path);
};

#endif
