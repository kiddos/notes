#include <iostream>
#include <string>

#include "PDFModifiedPage.h"
#include "PDFPage.h"
#include "PDFWriter.h"
#include "PageContentContext.h"

int main() {
  PDFWriter writer;
  EStatusCode status =
      writer.ModifyPDF("Output.pdf", ePDFVersion13, "Output_watermarked.pdf");

  if (status != eSuccess) {
    return 1;
  }

  PDFUsedFont* font = writer.GetFontForFile("./ComicMono.ttf");
  PDFParser& parser = writer.GetModifiedFileParser();
  unsigned long page_count = parser.GetPagesCount();

  for (unsigned int i = 0; i < page_count; ++i) {
    PDFModifiedPage modified_page(&writer, i);
    auto context = modified_page.StartContentContext();
    if (!context) {
      std::cout << "Failed to create context for page " << i << std::endl;
      continue;
    }
    AbstractContentContext::GraphicOptions graphic_options;
    AbstractContentContext::TextOptions text_options(
        font, 60, AbstractContentContext::eGray);

    context->WriteText(100, 400, "CONFIDENTIAL", text_options);
    modified_page.WritePage();
    modified_page.EndContentContext();
  }

  writer.EndPDF();
  return 0;
}
