ImU32 HSVToRGB(float h, float s, float v)
{
	int h_i = static_cast<int>(h * 6.0f);
	float f = h * 6.0f - h_i;
	float p = v * (1.0f - s);
	float q = v * (1.0f - f * s);
	float t = v * (1.0f - (1.0f - f) * s);

	switch (h_i % 6){
	case 0: return IM_COL32(static_cast<int>(v * 255), static_cast<int>(t * 255), static_cast<int>(p * 255), 255);
	case 1: return IM_COL32(static_cast<int>(q * 255), static_cast<int>(v * 255), static_cast<int>(p * 255), 255);
	case 2: return IM_COL32(static_cast<int>(p * 255), static_cast<int>(v * 255), static_cast<int>(t * 255), 255);
	case 3: return IM_COL32(static_cast<int>(p * 255), static_cast<int>(q * 255), static_cast<int>(v * 255), 255);
	case 4: return IM_COL32(static_cast<int>(t * 255), static_cast<int>(p * 255), static_cast<int>(v * 255), 255);
	case 5: return IM_COL32(static_cast<int>(v * 255), static_cast<int>(p * 255), static_cast<int>(q * 255), 255);
	}
}

	ImGui::Begin("", nullptr , ImGuiWindowFlags_NoCollapse | ImGuiWindowFlags_NoResize | ImGuiWindowFlags_NoTitleBar | ImGuiWindowFlags_AlwaysAutoResize);

	float time = ImGui::GetTime();
	float hue = fmodf(time, 1.0f);

	const char* text = "Gay Rainbow Text";
	for (int i = 0; i < strlen(text); ++i)
	{
		float charHue = fmodf(hue + static_cast<float>(i) / strlen(text), 1.0f);
		ImGui::PushStyleColor(ImGuiCol_Text, ImVec4(ImColor(HSVToRGB(charHue, 1.0f, 1.0f))));
		ImGui::Text("%c", text[i]);
		ImGui::SameLine(0, 0);
		ImGui::PopStyleColor();
	}
	ImGui::End();
