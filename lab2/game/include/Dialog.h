/**
 * @file Dialog.h
 * @brief Dialog system class
 * @author Gleb Shikunov
 */

#pragma once
#include <string>
#include <vector>

/**
 * @class Dialog
 * @brief Manages dialog interactions and choices
 * 
 * This class handles dialog display, choice selection,
 * and conversation flow between player and NPCs.
 */
class Dialog {
public:
    /**
     * @brief Constructor
     * @param text Initial dialog text
     */
    Dialog(const std::string& text = "");
    
    /**
     * @brief Show the dialog
     * 
     * Displays the current dialog text and available choices.
     */
    void Show();
    
    /**
     * @brief Move to next line
     * 
     * Advances to the next line of dialog text.
     */
    void NextLine();
    
    /**
     * @brief Check if dialog has choices
     * @return True if there are choices available
     */
    bool HasChoices() const;
    
    /**
     * @brief Select a choice
     * @param choice Index of the selected choice
     * 
     * Processes the player's choice selection.
     */
    void SelectChoice(int choice);
    
    /**
     * @brief End the dialog
     * 
     * Closes the dialog and returns to normal gameplay.
     */
    void End();
    
    /**
     * @brief Add a choice option
     * @param choice Choice text to add
     * 
     * Adds a new choice option to the dialog.
     */
    void AddChoice(const std::string& choice);
    
    /**
     * @brief Set dialog text
     * @param newText New text for the dialog
     */
    void SetText(const std::string& newText);

private:
    std::string text;                    ///< Current dialog text
    int currentLine;                     ///< Current line being displayed
    bool hasChoices;                     ///< Whether dialog has choices
    std::vector<std::string> choices;    ///< Available choice options
};
