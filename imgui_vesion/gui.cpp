#include "gui.h"
#include "imgui.h"

void Gui::render()
{
    ImGui::PushFont(default_font->font);

    render_header();
  
    ImGui::PopFont();
}


void Gui::render_header()
{
    ImGui::BeginChild("##HEADER", HelloImGui::EmToVec2(0.0f, 1.0f));
    ImGui::Text("U.S.S. CERRITOS / CALIFORNIA CLASS");

    ImGui::EndChild();
}



void Gui::draw_corner_btn(ImVec2 size,  ImVec4 color, bool right)
{
    ImDrawList *draw_list = ImGui::GetWindowDrawList();
    ImGui::InvisibleButton("@", size);

    ImVec2 min_left = ImGui::GetItemRectMin();
    ImVec2 max_right = ImGui::GetItemRectMax();


    ImGui::PushClipRect(min_left, max_right, false);
    draw_list->ChannelsSplit(0);


    ImGui::PopClipRect();

}





void Gui::load_fonts()
{
    auto runnerParams = HelloImGui::GetRunnerParams();
	runnerParams->dpiAwareParams.onlyUseFontDpiResponsive=true;

    HelloImGui::ImGuiDefaultSettings::LoadDefaultFont_WithFontAwesomeIcons();

    default_font = HelloImGui::LoadFontDpiResponsive("fonts/DINCOROS-Black-2.ttf", 24.0f);
}