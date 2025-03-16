#pragma once
#include "hello_imgui/hello_imgui.h"

class Gui
{
    public:
    Gui() = default;
    ~Gui() = default;    
    
    void render();
    void render_header();
    void load_fonts();

    private:
    HelloImGui::FontDpiResponsive *default_font;



    private:
        void draw_corner_btn(ImVec2 size, ImVec4 color, bool right);
};