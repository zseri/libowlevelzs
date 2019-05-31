/** lowlevelzs file_io.cxx
    (C) 2019 Erik Zscheile
    License: MIT
 **/
#include "file_io.hpp"
#include <stdio.h>

using std::string;

namespace llzs {

bool read_file2buffer(const string &file, string &content) noexcept {
  content.clear();

  FILE * fh = fopen(file.c_str(), "r");
  if(!fh) return false;

  char buf[1024];

  try {
    while(const size_t cnt = fread(buf, 1, sizeof(buf) - 1, fh))
      content.append(buf, cnt);
  } catch(...) {
    content.clear();
  }
  fclose(fh);

  return !content.empty();
}

}