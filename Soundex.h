#ifndef SOUNDEX_H
#define SOUNDEX_H
 
#include <ctype.h>
#include <string.h>
 
// Function to return the Soundex code for a given character
 
char getSoundexCode(char c) {
static const char soundexTable[26] = {'0', '1', '2', '3', '0', '1', '2', '0', '0', '2', '2', '4', '5','5', '0', '1', '2', '6', '2', '3', '0', '1', '0', '2', '0', '2'
    };
    c = toupper(c);
	if (!isalpha(c))
    {      
         return '0';
    }
     return soundexTable[c - 'A'];
}

 
 
// Function to initialize the Soundex code with the first character and pad with zeros
 
void initializeSoundex(char *soundex, char firstChar) {
    soundex[0] = toupper(firstChar);
    soundex[1] = soundex[2] = soundex[3] = '0';
    soundex[4] = '\0';
}
 
// Function to determine if the current Soundex code should be added to the result
 
bool shouldAddCode(char code, char previousCode) {
    return code != '0' && code != previousCode;
}
 
// Function to process a single character and update the Soundex code if necessary
 
void processCharacter(const char *name, char *soundex, int *sIndex, int i) {
    char code = getSoundexCode(name[i]);
    if (shouldAddCode(code, soundex[*sIndex - 1])) {
        soundex[*sIndex] = code;
        (*sIndex)++;
    }
}
 
// Function to ensure the Soundex code is 4 characters long by padding with zeros
 
void padSoundex(char *soundex, int sIndex) {
    while (sIndex < 4) {
        soundex[sIndex++] = '0';
    }
}
 
// Main function to generate the Soundex code for a given name
 
void generateSoundex(const char *name, char *soundex) {
    int len = strlen(name);
    int sIndex = 1;
 
    initializeSoundex(soundex, name[0]);
 
    for (int i = 1; i < len && sIndex < 4; i++) {
        processCharacter(name, soundex, &sIndex, i);
    }
 
    padSoundex(soundex, sIndex);
}
 
#endif // SOUNDEX_H
