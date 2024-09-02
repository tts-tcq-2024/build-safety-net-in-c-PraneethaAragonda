#ifndef SOUNDEX_H
#define SOUNDEX_H

#include <ctype.h>
#include <string.h>

// This function returns the Soundex code for a given character.
char getSoundexCode(char c) {
    static const char* codes = "01230120022455012623010202";
    c = toupper(c);
    return (c >= 'A' && c <= 'Z') ? codes[c - 'A'] : '0';
}

// This function generates the Soundex code for the given name.
void generateSoundex(const char *name, char *soundex) {
    soundex[0] = toupper(name[0]);
    char lastCode = getSoundexCode(soundex[0]);
    int sIndex = 1;

    for (int i = 1; name[i] != '\0' && sIndex < 4; i++) {
        char code = getSoundexCode(name[i]);
        sIndex += (code != '0' && code != lastCode);
        soundex[sIndex - 1] = (sIndex <= 4 && code != '0' && code != lastCode) ? code : soundex[sIndex - 1];
        lastCode = code;
    }

    while (sIndex < 4) {
        soundex[sIndex++] = '0';
    }

    soundex[4] = '\0';
}

#endif // SOUNDEX_H
