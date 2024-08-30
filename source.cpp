    void gradient_text(std::string text, ImColor startColor, ImColor endColor, bool should_anim = false) {
        ImVec2 windowSize = ImGui::GetWindowSize();

        ImGui::PushTextWrapPos(windowSize.x - 20.0f);

        if (should_anim) {
            float time = ImGui::GetTime();
            float frequency = -2.0f;

            for (int i = 0; i < text.size(); i++) {
                ImVec4 interpolatedColor;
                interpolatedColor.x = ImLerp(startColor.Value.x, endColor.Value.x, 0.5f + 0.5f * sinf(time * frequency + i * 0.3f));
                interpolatedColor.y = ImLerp(startColor.Value.y, endColor.Value.y, 0.5f + 0.5f * sinf(time * frequency + i * 0.3f));
                interpolatedColor.z = ImLerp(startColor.Value.z, endColor.Value.z, 0.5f + 0.5f * sinf(time * frequency + i * 0.3f));
                interpolatedColor.w = 1.0f;

                ImGui::PushStyleColor(ImGuiCol_Text, interpolatedColor);
                ImGui::TextUnformatted(text.substr(i, 1).c_str());
                ImGui::PopStyleColor();
                ImGui::SameLine(0, 0);
            }
        }
        else {
            ImGui::TextWrapped(text.c_str());
        }

        ImGui::PopTextWrapPos();
    }
