#include "Dialog.h"
#include <iostream>

Dialog::Dialog(const std::string& text) : text(text), currentLine(0), hasChoices(false) {}

void Dialog::Show() {
    std::cout << text << std::endl;
}

void Dialog::NextLine() {
    currentLine++;
    std::cout << "Следующая строка диалога..." << std::endl;
}

bool Dialog::HasChoices() const {
    return hasChoices;
}

void Dialog::SelectChoice(int choice) {
    if (hasChoices && choice >= 0 && choice < static_cast<int>(choices.size())) {
        std::cout << "Выбрано: " << choices[choice] << std::endl;
    } else {
        std::cout << "Неверный выбор!" << std::endl;
    }
}

void Dialog::End() {
    std::cout << "Диалог завершен." << std::endl;
}

void Dialog::AddChoice(const std::string& choice) {
    choices.push_back(choice);
    hasChoices = true;
}

void Dialog::SetText(const std::string& newText) {
    text = newText;
}
