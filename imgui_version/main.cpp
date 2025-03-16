#include "hello_imgui/hello_imgui.h"
#include "gui.h"

int main(int, char *[]) {
    Gui gui;
    HelloImGui::RunnerParams runnerParams;
    runnerParams.appWindowParams.windowTitle = "pi_imgui_demo";
    runnerParams.appWindowParams.windowGeometry.size = {1024, 600};
    runnerParams.appWindowParams.resizable = false;

    runnerParams.callbacks.LoadAdditionalFonts = [&]() {
        gui.load_fonts();
    };

    runnerParams.callbacks.ShowGui = [&]() {
        gui.render();
    };

    HelloImGui::Run(runnerParams);
    return 0;
}