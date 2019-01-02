/** 
 * PrettyPoem
 * INPUTSANITIZER.CPP
 * @author Daniel Kostuj
 * 
 * This file contains the InputSanitizer class definitions.
 * 
 * Use of this source code is governed by the license that can be
 * found in the LICENSE file.
 */

#include "InputSanitizer.h"

std::string InputSanitizer::sanitizeInput(const char &c) {
    switch (c) {
    case '\\':
        return "\\textbackslash{}";
    case '\n':
        return "\\ \n\n";
    case '<':
        return "$<$";
    case '>':
        return "$>$";
    case '{':
        return "\\{";
    case '}':
        return "\\}";
    case '$':
        return "\\$";
    case '&':
        return "\\&";
    case '#':
        return "\\#";
    case '^':
        return "\\textasciicircum";
    case '-':
        return "--";
    case '_':
        return "\\_";
    case '~':
        return "\\textasciitilde";
    case '%':
        return "\\%";
    default:
        return std::string(1, c);
    }
}
