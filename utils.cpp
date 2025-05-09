#include <iostream>
#include <filesystem>
#include <fstream>
#include <cryptopp/cryptlib.h>
#include <cryptopp/hex.h>
#include <cryptopp/files.h>
#include <cryptopp/filters.h>
#include <cryptopp/sha.h>
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
		return "";
	}

	std::string content((std::istreambuf_iterator<char>(file)), std::istreambuf_iterator<char>());

	return content;
	

}

void create_file(std::string file_name, std::string file_path){
	std::ofstream file;
	file.open(file_path + file_name);
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
