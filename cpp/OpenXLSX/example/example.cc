#include <OpenXLSX.hpp>

int main(void) {
  using namespace OpenXLSX;

  XLDocument doc;
  doc.create("./Demo01.xlsx", XLForceOverwrite);
  auto wks = doc.workbook().worksheet("Sheet1");

  wks.cell("A1").value() = M_PI;
  wks.cell("B1").value() = "text";

  doc.save();
  doc.close();
  return 0;
}
