/** 
 * PrettyPoem
 * POEMIFIER.H
 * @author Daniel Kostuj
 * 
 * This file contains the Poemifier class declarations.
 * 
 * Use of this source code is governed by the license that can be
 * found in the LICENSE file.
 */

 
#ifndef POEMIFIER_H
#define POEMIFIER_H

#include "GrabBag.h"
#include <fstream>
#include <string>
#include <vector>

using ColorPair = std::vector<std::string>;

class Poemifier {
    
private:
    const char* latexFileName;
    std::ifstream userTextFile;
    GrabBag<ColorPair> colors;
    GrabBag<std::string> fonts;

    inline const char* FontsFile() { return "settings/fonts"; };
    inline const char* ColorsFile() { return "settings/colors"; };
    void loadFontsFromFile();
    void loadColorsFromFile();
    std::string sanitizeInput(const char &c);
    std::string createLatexText(const char &delimiter);
    std::string createLatexText();
    std::string createFontSize();
    std::string createRandomFont();
    std::string createRandomJustify();
    ColorPair createRandomColors();
    std::string addPreamble();
    std::string addPoemTitle();
    std::string addUserText();
    std::string addEnd();    
    
public:
    Poemifier(const char* userFileName);
    
    int poemifyUserText();    
    std::string getDestinationFileName();
    void setDestinationFileName(const char* dest);
    
    
};

#endif
