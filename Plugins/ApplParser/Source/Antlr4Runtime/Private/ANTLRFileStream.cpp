/* Copyright (c) 2012-2017 The ANTLR Project. All rights reserved.
 * Use of this file is governed by the BSD 3-clause license that
 * can be found in the LICENSE.txt file in the project root.
 */
#pragma GCC visibility push(default)

#include "ANTLRFileStream.h"

using namespace antlr4;

void ANTLRFileStream::loadFromFile(const std::string &fileName) {
  _fileName = fileName;
  if (_fileName.empty()) {
    return;
  }

  std::ifstream stream(fileName, std::ios::binary);

  ANTLRInputStream::load(stream);
}

std::string ANTLRFileStream::getSourceName() const {
  return _fileName;
}
#pragma GCC visibility pop
