#include <iostream>
#include <filesystem>
#include <fstream>
#include <vector>
#include <cryptopp/cryptlib.h>
#include <cryptopp/hex.h>
#include <cryptopp/files.h>
#include <cryptopp/filters.h>
#include <cryptopp/sha.h>
#include <sys/stat.h>
using namespace CryptoPP;

std::string jgit_path = "";

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

void write_to_file(std::string file_path, std::string content, bool append = false){
	std::cout << "Writing to " + file_path << std::endl;
	std::ofstream file;
	file.open(file_path, append ? std::ofstream::app : std::ofstream::trunc);
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

std::string get_jgit_path(std::string path = "."){
	if(std::filesystem::exists(path + "/.jgit")){
		std::cout << "FOUND JGIT IN " << path << std::endl;
		jgit_path = path + "/.jgit/";
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

bool is_file_tracked(std::string file_path){
	if(jgit_path.empty()){
		get_jgit_path();
	}
	std::string tracked_files = get_file_contents(jgit_path + "/TRACKED");
	if(tracked_files.find(file_path) != -1){
		std::cout << "File already tracked!";
		return true;
	} else {
		std::cout << file_path + " is not tracked" << std::endl;
	}
	return false;
}

void add_to_tracked(std::string path, std::string sha){
	/* if(std::filesystem::is_directory(path)){
		for(auto const& dir_entry: std::filesystem::directory_iterator(path)){
			std::cout << dir_entry.path() << std::endl;
		} */
	if(std::filesystem::exists(path)){
		if(!is_file_tracked(path)) {
			std::cout << "File exists" << std::endl;
			get_jgit_path(".");
			write_to_file(jgit_path + "TRACKED", path + " " + sha , true);
		}
	} else {
		std::cout << "Cannot find file " + path << std::endl;
	}
}

std::vector<std::string> get_tracked_files(){
	if(jgit_path.empty()){
		get_jgit_path();
	}

}

bool check_init(){
	return is_jgit_dir(".");
}


