#include <bits/stdc++.h>
#include <string>

std::string ReplaceAll(std::string str, const std::string &from, const std::string &to) {
  size_t start_pos = 0;
  while ((start_pos = str.find(from, start_pos)) != std::string::npos) {
    str.replace(start_pos, from.length(), to);
    start_pos +=
        to.length(); // Handles case where 'to' is a substring of 'from'
  }
  return str;
}

void write_to_csv_file(FILE *csv_file, std::vector<std::string> cols) {
  for (uint i = 0; i < cols.size(); i++) {
    if (cols[i].find(',') != std::string::npos) {
      cols[i] = ReplaceAll(cols[i], std::string("\""), std::string("\"\""));
      cols[i] = ReplaceAll(cols[i], std::string("  "), std::string(""));
      cols[i] = ReplaceAll(cols[i], std::string("\n"), std::string(""));
      cols[i] = '"' + cols[i] + '"';
    }
    fprintf(csv_file, "%s", cols[i].c_str());
    if (i != cols.size() - 1)
      fprintf(csv_file, ",");
  }
  fprintf(csv_file, "\n");

  return;
}

std::vector<std::string> read_from_csv_file(std::string line, char delimeter) {
  line.erase(std::remove(line.begin(), line.end(), '\n'), line.end());
  line.erase(std::remove(line.begin(), line.end(), '\r'), line.end());
  std::vector<std::string> cols;
  std::string cur = "";
  bool instring = false;
  for (uint i = 0; i < line.length(); i++) {
    if (line[i] == '"')
      instring = !instring;
    else if (!instring && line[i] == delimeter) {
      cols.push_back(cur);
      cur = "";
    } else
      cur.push_back(line[i]);
  }
  cols.push_back(cur);
  return cols;
}

std::vector<std::vector<double> > read_traces(const char *filename) {
    std::vector<std::vector<double> > to_return;

    std::ifstream inputFile(filename);
    bool header = true;
    std::string s;

    while (std::getline(inputFile, s)) {
        std::vector<double> line_doubles;

        if (header) {
            header = false;
            continue;
        }
        std::vector<std::string> line = read_from_csv_file(s, ',');

        for (std::string val : line) {
            line_doubles.push_back(std::stod(val));
        }

        to_return.push_back(line_doubles);
    }    

    if (header) {
        std::cout << "CSV file " << filename << " is empty." << std::endl;
        throw 1;
    }

    return to_return;
}