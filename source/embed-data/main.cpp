/**
 * @ingroup Tools
 * @file main.cpp
 * @author Bruk Tedla (biruk.tedla93@gmail.com)
 * @date 2020-10-11
 * @brief This file contains the source for embed-data tool(executable) which
 * helps to embed files into executable by phrasing them as a cpp source file.
 * Embed-data was inspired by blender's datatoc.
 *
 */

#include <cstdlib>
#include <filesystem>
#include <fmt/format.h>
#include <fstream>
#include <iostream>
#include <string>
#include <string_view>

int main(int argc, char *argv[]) {
  if (argc < 2) {
    exit(1);
  }
  std::string_view inFile{argv[1]};
  std::string_view outFile{argv[2]};

  uintmax_t size;

  std::ifstream ifs{inFile, std::ios_base::binary | std::ios_base::in};
  if (!ifs.is_open()) {
    std::cout << fmt::format("Unable to open input {}\n", inFile.data())
              << std::endl;
  }
  std::string fileName;
  std::filesystem::path inPath(inFile);
  inPath = std::filesystem::absolute(inPath);
  size = std::filesystem::file_size(inPath);

  fileName = inPath.filename().string();
  std::replace(fileName.begin(), fileName.end(), '.', '_');
  std::replace(fileName.begin(), fileName.end(), '-', '_');

  std::ofstream ofs{outFile};
  if (!ofs.is_open()) {
    std::cout << fmt::format("Unable to open output {}\n", inFile) << std::endl;
  }
  std::cout << fmt::format("Making source file for {}", inFile);

  ofs << "#if defined(_MSC_VER)\n"
         "#pragma warning(push )\n"
         "#pragma warning(disable : 4309 )\n"
         "#pragma warning(disable : 4838 )\n"
         "#elif defined(__GNUC__) || defined(__clang__)\n"
         "  _Pragma(GCC diagnostic push)\n"
         "  _Pragma(GCC diagnostic ignored #Wnarrowing)\n"
         "  _Pragma(GCC diagnostic ignored #Wformat-truncation)\n"
         "#endif\n";

  ofs << fmt::format("/* embed data of file {} */\n\n", inFile);

  ofs << fmt::format("extern const int embed_data_{0}_size;\n"
                     "extern const char embed_data_{0}[];\n\n",
                     fileName.c_str());

  ofs << fmt::format("const int embed_data_{0}_size = {1};\n"
                     "const char embed_data_{0}[]",
                     fileName.c_str(), (int)size)
      << " = {\n";

  while (--size) {
    if (size % 32 == 31) {
      ofs << "\n";
    }
    ofs << ifs.get() << ",";
  }

  ofs << "0\n};\n\n";
  ofs << "#if defined(_MSC_VER)\n"
         "#pragma warning( pop )\n"
         "#elif defined(__GNUC__) || defined(__clang__)\n"
         "_Pragma(GCC diagnostic pop)\n"
         "#endif\n";

  ofs.close();
  ifs.close();
  return 0;
}