#include <iostream>
#include <filesystem>
#include <fstream>
#include <cryptopp/cryptlib.h>
#include <cryptopp/hex.h>
#include <cryptopp/files.h>
#include <cryptopp/filters.h>
#include <cryptopp/sha.h>
#include <sys/stat.h>
using namespace CryptoPP;

bool check_init(){
	if (std::filesystem::exists("./.jgit")){
		return true;
	}
	return false;
}

std::string get_file_contents(std::string file_path){

	std::ifstream file(file_path);
	if(!file.is_open()){
		throw std::runtime_error("File could not open / does not exist");
	}
	std::string content((std::istreambuf_iterator<char>(file)), std::istreambuf_iterator<char>());
	return content;
}

void create_file(std::string file_name, std::string dir_path){
	std::ofstream file;
	file.open(dir_path + file_name);
	file.close();
}

void write_to_file(std::string file_path, std::string content){
	std::ofstream file;
	file.open(file_path);
	file << content;
	file.close();
}

std::string gen_sha(std::string msg){
	HexEncoder encoder(new FileSink(std::cout));
	std::string digest;
	std::string hexDigest;
	SHA1 hash;

	StringSource(msg, true,
	new HashFilter(hash,
	new StringSink(digest)
	)
	);

	StringSource(digest, true,
	new HexEncoder(
	new StringSink(hexDigest),
	false)
	);

	return hexDigest;
}

std::string get_jgit_path(std::string path){
	if(std::filesystem::exists(path + "/.jgit")){
		std::cout << "FOUND JGIT IN " << path << std::endl;
		return path;
	} else if (!std::filesystem::equivalent(path, "/")){
		path = "../" + path;
		return get_jgit_path(path);
	} else {
		std::cout << "get_jgit_path exited at root (/)" << std::endl;
	}

	return "";
}

bool is_jgit_dir(std::string path){
	if(std::filesystem::exists(path + "/.jgit")){
		std::cout << "FOUND JGIT IN " << path << std::endl;
		return true;
	} else if (!std::filesystem::equivalent(path, "/")){
		path = "../" + path;
		return is_jgit_dir(path);
	} else {
		std::cout << "is_jgit_dir exited at root (/)" << std::endl;
	}

	return false;
}

bool file_in_tracked(std::string file){
	get_file_contents("./.jgit");
}

void add_to_tracked(std::string path){

}
