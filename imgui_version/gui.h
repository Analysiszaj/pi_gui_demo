#pragma once
#include "hello_imgui/hello_imgui.h"
#include "imgui.h"

class Gui {
private:
    HelloImGui::FontDpiResponsive *default_font;

public:
    Gui() = default;
    ~Gui() = default;

    void render();
    void render_header();
    void render_content();
    void render_footer();
    void load_fonts();

private:
    void draw_header_bg(ImDrawList *draw_list, ImVec4 color, float padding);
    void draw_header_text(const std::string text, ImVec4 text_color, ImVec4 bg_color, float padding_x, float padding_y);

    void draw_content_left_bg(ImDrawList *draw_list);
    void draw_content_right_bg(ImDrawList *draw_list);
};