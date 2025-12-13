#ifndef FILEIO_HPP
#define FILEIO_HPP

#include <string>

std::string read_file(std::string path);
void write_file(std::string path, std::string content);

#endif