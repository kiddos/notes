#include <iostream>

#include "PDFDictionary.h"
#include "PDFModifiedPage.h"
#include "PDFParser.h"
#include "PDFWriter.h"

void ReadMetadata(const std::string& filePath) {
  PDFParser parser;
  InputFile pdfFile;

  if (pdfFile.OpenFile(filePath) != eSuccess) {
    std::cout << "Could not open file." << std::endl;
    return;
  }

  // Note: It takes a pointer to an IByteReader, which InputFile provides.
  if (parser.StartPDFParsing(pdfFile.GetInputStream()) != eSuccess) {
    std::cout << "Parsing failed (maybe not a valid PDF or encrypted)."
              << std::endl;
    return;
  }

  unsigned long pages = parser.GetPagesCount();
  std::cout << "Total Pages: " << pages << std::endl;

  const PDFDictionary* trailer = parser.GetTrailer();
  if (trailer) {
    std::cout << "Trailer dictionary successfully accessed." << std::endl;
  }
}

int main(void) {
  ReadMetadata("./Output.pdf");
  return 0;
}
