#define IMGUI_DEFINE_MATH_OPERATORS
#include "gui.h"

void Gui::render() {
    ImGui::PushFont(default_font->font);

    render_header();
    render_content();
    render_footer();

    ImGui::PopFont();
}

/**
 * @brief 绘制头部
 */
void Gui::render_header() {
    ImGui::BeginChild("##HEADER", HelloImGui::EmToVec2(0.0f, 0.0f), ImGuiChildFlags_AutoResizeY);
    ImDrawList *draw_list = ImGui::GetWindowDrawList();
    draw_header_bg(draw_list, ImColor(223, 243, 132), HelloImGui::EmSize(0.2f));

    ImGui::SameLine(HelloImGui::EmSize(1.0f));
    draw_header_text("U.S.S. CERRITOS / CALIFORNIA CLASS", ImColor(255, 255, 255).Value, ImColor(0, 0, 0), HelloImGui::EmSize(0.5f), HelloImGui::EmSize(0.1f));

    static std::string right_text = "NCC-75567";
    ImGui::SameLine(ImGui::GetWindowWidth() - HelloImGui::EmSize(1.0f) - HelloImGui::EmSize(0.5f) * 2 - ImGui::CalcTextSize(right_text.c_str()).x);
    draw_header_text(right_text, ImColor(255, 255, 255), ImColor(0, 0, 0), HelloImGui::EmSize(0.5f), HelloImGui::EmSize(0.1f));
    ImGui::EndChild();
}

void Gui::render_content() {
    ImGui::BeginChild("##CONTENT", ImVec2(0.0f, ImGui::GetContentRegionAvail().y * 0.6f));

    ImGui::BeginChild("##CONTENT_LEFT", ImVec2(ImGui::GetContentRegionAvail().x * 0.3f, 0.0f));
    ImDrawList *left_draw_list = ImGui::GetBackgroundDrawList();
    draw_content_left_bg(left_draw_list);
    ImGui::EndChild();

    ImGui::SameLine();

    ImGui::BeginChild("##CONTENT_RIGHT", ImGui::GetContentRegionAvail());
    ImDrawList *right_draw_list = ImGui::GetWindowDrawList();
    draw_content_right_bg(right_draw_list);
    ImGui::EndChild();

    ImGui::EndChild();
}

void Gui::render_footer() {
    ImGui::BeginChild("##FOOTER", ImVec2(0.0f, ImGui::GetContentRegionAvail().y * 0.4f));
    ImGui::Text("FOOT");
    ImGui::EndChild();
}

/**
 * @brief 加载字体
 */
void Gui::load_fonts() {
    auto runnerParams = HelloImGui::GetRunnerParams();
    runnerParams->dpiAwareParams.onlyUseFontDpiResponsive = true;

    HelloImGui::ImGuiDefaultSettings::LoadDefaultFont_WithFontAwesomeIcons();

    default_font = HelloImGui::LoadFontDpiResponsive("fonts/DINCOROS-Black-2.ttf", 24.0f);
}

/**
 * @brief 绘制背景
 * @param draw_list 绘制指针
 * @param color 背景颜色
 * @param padding 上下边距
 */
void Gui::draw_header_bg(ImDrawList *draw_list, ImVec4 color, float padding) {
    ImVec2 p1 = ImGui::GetWindowPos() + ImVec2(0.0f, padding);
    ImVec2 p2 = ImGui::GetWindowPos() + ImGui::GetWindowSize() - ImVec2(0.0f, padding);
    float height = ImGui::GetWindowSize().y - 2 * padding;
    draw_list->AddRectFilled(p1, p2, ImGui::GetColorU32(color), height / 2.0f);
}

/**
 * @brief 绘制头部文字
 * @param text 文字
 * @param text_color 字体颜色
 * @param bg_color 背景颜色
 * @param padding_x 左右边距
 * @param padding_y 上下边距
 */
void Gui::draw_header_text(const std::string text, ImVec4 text_color, ImVec4 bg_color, float padding_x, float padding_y) {
    ImVec2 text_size = ImGui::CalcTextSize(text.c_str()) + ImVec2(2 * padding_x, 2 * padding_y);

    ImGui::InvisibleButton(("@" + text).c_str(), text_size);
    ImVec2 p1 = ImGui::GetItemRectMin();
    ImVec2 p2 = ImGui::GetItemRectMax();

    ImDrawList *draw_list = ImGui::GetWindowDrawList();

    ImGui::PushClipRect(p1, p2, true);

    draw_list->AddRectFilled(p1, p2, ImGui::GetColorU32(bg_color), 0.0f);
    draw_list->AddText(p1 + ImVec2(padding_x, padding_y), ImGui::GetColorU32(text_color), text.c_str());

    ImGui::PopClipRect();
}

void Gui::draw_content_left_bg(ImDrawList *draw_list) {
    ImVec2 p1 = ImGui::GetWindowPos();
    ImVec2 p2 = p1 + ImGui::GetWindowSize();
    float width = ImGui::GetWindowWidth();
    float height = ImGui::GetWindowHeight();

    ImGui::PushClipRect(p1, p2, true);
    draw_list->AddRectFilled(p1, p2, ImGui::GetColorU32(ImColor(198, 241, 248).Value), HelloImGui::EmSize(2.0f));

    ImVec2 p3 = p1 + ImVec2(width * 0.8f, height);
    draw_list->AddRectFilled(p1, p3, IM_COL32_BLACK);

    ImVec2 p4 = p1 + ImVec2(width * 0.79f, height);
    draw_list->AddRectFilled(p1, p4, ImGui::GetColorU32(ImColor(216, 246, 241).Value));

    ImVec2 p5 = p1 + ImVec2(width * 0.15f, height);
    draw_list->AddRectFilled(p1, p5, IM_COL32_BLACK);

    ImVec2 p6 = p1 + ImVec2(width * 0.13f, height);
    draw_list->AddRectFilled(p1, p6, ImGui::GetColorU32(ImColor(215, 182, 182).Value));

    ImVec2 p7 = p1 + ImVec2(width * 0.11f, height);
    draw_list->AddRectFilled(p1, p7, IM_COL32_BLACK);

    ImVec2 p8 = p1 + ImVec2(width * 0.10f, height);
    draw_list->AddRectFilled(p1, p8, ImGui::GetColorU32(ImColor(215, 182, 182).Value));

    ImVec2 p9 = p1 + ImVec2(width * 0.09f, height);
    draw_list->AddRectFilled(p1, p9, IM_COL32_BLACK);

    ImVec2 p10 = p1 + ImVec2(width * 0.08f, height);
    draw_list->AddRectFilled(p1, p10, ImGui::GetColorU32(ImColor(232, 245, 137).Value));

    draw_list->AddRectFilled(p1, p2, ImGui::GetColorU32(ImVec4(0.0, 0.0f, 0.0f, 0.0f)));

    ImGui::PopClipRect();
}
void Gui::draw_content_right_bg(ImDrawList *draw_list) {
}
