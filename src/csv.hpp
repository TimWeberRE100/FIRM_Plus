#ifndef CSV_HPP
#define CSV_HPP

#include <string>
#include <vector>

std::string ReplaceAll(std::string str, const std::string &from, const std::string &to);
void write_to_csv_file(FILE *csv_file, std::vector<std::string> cols);
std::vector<std::string> read_from_csv_file(std::string line, char delimeter);
std::vector<std::vector<double> > read_traces(const char *filename);

#endif