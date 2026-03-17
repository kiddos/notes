#include <PDFPage.h>
#include <PDFWriter.h>
#include <PageContentContext.h>

#include <string>

int main(void) {
  PDFWriter writer;
  writer.StartPDF("Output.pdf", ePDFVersion13);

  // Create a Page (A4 size: 595 x 842 points)
  PDFPage* page = new PDFPage();
  page->SetMediaBox(PDFRectangle(0, 0, 595, 842));
  PageContentContext* context = writer.StartPageContentContext(page);

  AbstractContentContext::ImageOptions image_options;
  image_options.transformationMethod = AbstractContentContext::eFit;
  image_options.boundingBoxWidth = 200;
  image_options.boundingBoxHeight = 200;
  context->DrawImage(50, 650, "./logo.png", image_options);

  PDFUsedFont* custom_font = writer.GetFontForFile("./ComicMono.ttf");

  std::string lines[] = {
      "This is a simulated paragraph using a custom font.",
      "The PDF-Writer library gives you precise control over",
      "the placement of every single line on the page."};

  AbstractContentContext::TextOptions text_options(
      custom_font, 14, AbstractContentContext::eGray, 0);

  int startY = 600;
  for (const std::string& line : lines) {
    context->WriteText(50, startY, line, text_options);
    startY -= 20;
  }

  writer.EndPageContentContext(context);
  writer.WritePageAndRelease(page);
  writer.EndPDF();
  return 0;
}
