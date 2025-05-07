#include <filesystem>

namespace jgit {
	int init(){
		if (std::filesystem::exists("./.jgit")){
		return 1;
	}
	std::filesystem::create_directory("./.jgit");
	return 0;
}
}
