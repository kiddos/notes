#include <poppler-document.h>
#include <poppler-page.h>
#include <poppler-page-renderer.h>
#include <string>
#include <iostream>

int main(void) {
  auto *doc = poppler::document::load_from_file("test.pdf");
  auto title = doc->info_key("Title").to_utf8();
  std::cout << "Title:" << std::string(title.begin(), title.end()) << std::endl;

  int pages = doc->pages();
  for (int i = 0; i < pages; ++i) {
    auto *page = doc->create_page(i);
    auto bytes = page->text().to_utf8();
    std::string text(bytes.begin(), bytes.end());
    std::cout << "content:" << text << std::endl;

    poppler::page_renderer renderer;
    renderer.set_render_hint(poppler::page_renderer::text_antialiasing);

    auto image = renderer.render_page(page, 300.0, 300.0);
    std::string name = "page" + std::to_string(i + 1) + ".png";
    image.save(name, "png");

    auto rect = page->page_rect(poppler::page_box_enum::media_box);
    poppler::ustring search_text = poppler::ustring::from_utf8("Text");

    bool found = page->search(search_text, rect, poppler::page::search_from_top, poppler::case_insensitive);
    if (found) {
      auto text_boxes = page->text_list();
      for (auto& t : text_boxes) {
        std::cout << "found at " << t.bbox().left() << "," << t.bbox().top() << std::endl;
      }
    }
  }

  delete doc;
  return 0;
}
