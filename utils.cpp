#include <iostream>
#include <filesystem>
#include <fstream>
#include <cryptopp/cryptlib.h>
#include <cryptopp/hex.h>
#include <cryptopp/files.h>
#include <cryptopp/filters.h>
#include <cryptopp/sha.h>
using namespace CryptoPP;

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
