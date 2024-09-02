#include <gtest/gtest.h>
#include "Soundex.h"

// Helper function to compare generated Soundex with expected output

void TestSoundex(const char* name, const char* expected) {
    char soundex[5];
    generateSoundex(name, soundex);
    EXPECT_STREQ(expected, soundex);
}

// Test cases using AAA format

TEST(SoundexTest, HandlesSimpleNames) {
    // Arrange
    const char* name = "America";
    const char* expected = "A562";
    
    // Act
    char soundex[5];
    generateSoundex(name, soundex);
    
    // Assert
    EXPECT_STREQ(expected, soundex);
}

TEST(SoundexTest, HandlesNamesWithNumbersAndSpecialChars) {
    // Arrange
    const char* name = "123praneetha";
    const char* expected = "P653"; // Only letters are considered
    
    // Act
    char soundex[5];
    generateSoundex(name, soundex);
    
    // Assert
    EXPECT_STREQ(expected, soundex);
}

TEST(SoundexTest, HandlesNamesWithSpecialCharsAndDigits) {
    // Arrange
    const char* name = "pr@12nee";
    const char* expected = "P653"; // Special characters and digits are ignored
    
    // Act
    char soundex[5];
    generateSoundex(name, soundex);
    
    // Assert
    EXPECT_STREQ(expected, soundex);
}

TEST(SoundexTest, HandlesSingleLetterName) {
    // Arrange
    const char* name = "A";
    const char* expected = "A000"; // Single letter name should be padded with zeros
    
    // Act
    char soundex[5];
    generateSoundex(name, soundex);
    
    // Assert
    EXPECT_STREQ(expected, soundex);
}

TEST(SoundexTest, HandlesShortName) {
    // Arrange
    const char* name = "Al";
    const char* expected = "A040"; // Short name, should be padded with zeros
    
    // Act
    char soundex[5];
    generateSoundex(name, soundex);
    
    // Assert
    EXPECT_STREQ(expected, soundex);
}

TEST(SoundexTest, HandlesLongerName) {
    // Arrange
    const char* name = "Alexander";
    const char* expected = "A252"; // Longer name, should truncate correctly
    
    // Act
    char soundex[5];
    generateSoundex(name, soundex);
    
    // Assert
    EXPECT_STREQ(expected, soundex);
}

TEST(SoundexTest, HandlesEmptyInput) {
    // Arrange
    const char* name = "";
    const char* expected = "0000"; // An empty input should be handled gracefully
    
    // Act
    char soundex[5];
    generateSoundex(name, soundex);
    
    // Assert
    EXPECT_STREQ(expected, soundex);
}

TEST(SoundexTest, HandlesEdgeCases) {
    // Arrange
    const char* name = "Arnold";
    const char* expected = "A653"; // Name with repeating characters that should be ignored
    
    // Act
    char soundex[5];
    generateSoundex(name, soundex);
    
    // Assert
    EXPECT_STREQ(expected, soundex);
}

TEST(SoundexTest, HandlesSingleLetterMappingToZero) {
    // Arrange
    const char* name = "U";
    const char* expected = "U000"; // Single letter name that maps to '0'
    
    // Act
    char soundex[5];
    generateSoundex(name, soundex);
    
    // Assert
    EXPECT_STREQ(expected, soundex);
}

TEST(SoundexTest, HandlesLetterMappingToZero) {
    // Arrange
    const char* name = "O";
    const char* expected = "O000"; // Single letter name that maps to '0'
    
    // Act
    char soundex[5];
    generateSoundex(name, soundex);
    
    // Assert
    EXPECT_STREQ(expected, soundex);
}
