/**
 * PrettyPoem
 * POEMIFIER.CPP
 * @author Daniel Kostuj
 * 
 * This file contains the Poemifier class definition.
 * 
 * Use of this source code is governed by the license that can be
 * found in the LICENSE file.
 */

#include "Poemifier.h"
#include <limits>
#include <sstream>

Poemifier::Poemifier(const char* userFileName)
 : latexFileName("output.tex"),
   userTextFile(userFileName, std::ifstream::in)
{
    if (userTextFile.fail()) {
        throw std::invalid_argument("User file can not be opened.");
    }
    
    loadFontsFromFile();
    loadColorsFromFile();
}

void Poemifier::loadFontsFromFile() {
    std::ifstream fontStream(FontsFile());
    if (fontStream.fail()) {
        throw std::invalid_argument("Fonts file in settings folder can not be opened.");
    }
    
    std::string fontLine;
    
    while (std::getline(fontStream,fontLine)) {
        fonts.insert(fontLine);
    }
}

void Poemifier::loadColorsFromFile() {
    std::ifstream colorStream(ColorsFile());
    if (colorStream.fail()) {
        throw std::invalid_argument("Colors file in settings folder can not be opened.");
    }
    
    std::string colorLine;
    ColorPair tempPair;
    
    while (std::getline(colorStream, colorLine)) {
        std::string color;
        std::stringstream lineStream(colorLine);
        while (std::getline(lineStream, color, ',')) {
            tempPair.emplace_back(color);
        }
        
        if (tempPair.size() == 2) {
            colors.insert(tempPair);
            tempPair.clear();
        }
    }
}


std::string Poemifier::createLatexText(const char &delimiter) {
    char c;
    std::string text;
    
    while ((c = userTextFile.get()) != delimiter
            && !userTextFile.eof()) {
        text += sanitizer.sanitizeInput(c);
    }
    
    return text;
}

std::string Poemifier::createLatexText() { return createLatexText('\0'); }

std::string Poemifier::createFontSize() {
    GrabBag<std::string> sizes({"10","11","12"});
    return sizes.grab();
}

std::string Poemifier::createRandomFont() { return fonts.empty() ? "" : fonts.grab(); }

ColorPair Poemifier::createRandomColors() { return colors.grab(); }

std::string Poemifier::createRandomJustification() {    
    GrabBag<std::string> justifications({"\\centering\n","\\raggedleft\n",""});
    return justifications.grab();
}

std::string Poemifier::addPreamble() {
    std::string preambleFirst = "\\documentclass[a4paper," + createFontSize() + "pt]{article}\\usepackage[a4paper]{geometry}";
    std::string font = createRandomFont() + "\n";    
    std::string preambleSecond = "\\usepackage[T1]{fontenc}\n\\usepackage[utf8]{inputenc}\n\\usepackage[dvipsnames]{xcolor}\n\\setlength{\\parindent}{0pt}\n\\geometry{top=2cm, bottom=2cm}\n\\pagestyle{empty}\n\\begin{document}\n";
    
    ColorPair chosenColors = createRandomColors();
    std::string colors = "\\pagecolor{" + chosenColors.at(0) + "} \n\\color{" + chosenColors.at(1) + "}";
    std::string justify = createRandomJustification();
    
    return (preambleFirst + font + preambleSecond + colors + justify);
}

std::string Poemifier::addPoemTitle() { return "\\section*{" + createLatexText('\n') + "}"; }

std::string Poemifier::addUserText() { return createLatexText(); }

std::string Poemifier::addEnd() { return "\\end{document}"; }

std::string Poemifier::getDestinationFileName() { return latexFileName; }
   
void Poemifier::setDestinationFileName(const char* dest) { latexFileName = dest; }
   
int Poemifier::poemifyUserText() {
    std::ofstream latexTempFile(latexFileName);
     
    latexTempFile 
    << addPreamble() 
    << addPoemTitle() 
    << addUserText()
    << addEnd();
    
    return 0;
}
