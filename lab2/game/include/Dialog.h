#pragma once
#include <string>
#include <vector>

class Dialog {
public:
    Dialog(const std::string& text = "");
    void Show();
    void NextLine();
    bool HasChoices() const;
    void SelectChoice(int choice);
    void End();
    void AddChoice(const std::string& choice);
    void SetText(const std::string& newText);
private:
    std::string text;
    int currentLine;
    bool hasChoices;
    std::vector<std::string> choices;
};
