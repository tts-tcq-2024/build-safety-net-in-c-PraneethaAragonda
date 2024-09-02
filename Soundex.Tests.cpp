#include <gtest/gtest.h>
#include "Soundex.h"

// Helper function to generate Soundex code
std::string generateSoundexCode(const std::string& name) {
    char soundex[5];
    generateSoundex(name.c_str(), soundex);
    return std::string(soundex);
}

// Test for typical names
TEST(SoundexTest, Miller) {
    // Arrange
    std::string name = "Miller";
    std::string expectedSoundex = "M460";

    // Act
    std::string result = generateSoundexCode(name);

    // Assert
    EXPECT_EQ(result, expectedSoundex);
}

TEST(SoundexTest, America) {
    // Arrange
    std::string name = "America";
    std::string expectedSoundex = "A561";

    // Act
    std::string result = generateSoundexCode(name);

    // Assert
    EXPECT_EQ(result, expectedSoundex);
}

TEST(SoundexTest, Smith) {
    // Arrange
    std::string name = "Smith";
    std::string expectedSoundex = "S530";

    // Act
    std::string result = generateSoundexCode(name);

    // Assert
    EXPECT_EQ(result, expectedSoundex);
}

// Test for names with non-alphabetic characters
TEST(SoundexTest, NameWithNumbers) {
    // Arrange
    std::string name = "123Praneetha";
    std::string expectedSoundex = "P654";

    // Act
    std::string result = generateSoundexCode(name);

    // Assert
    EXPECT_EQ(result, expectedSoundex);
}

TEST(SoundexTest, NameWithSpecialChars) {
    // Arrange
    std::string name = "pr@12nee";
    std::string expectedSoundex = "P652";

    // Act
    std::string result = generateSoundexCode(name);

    // Assert
    EXPECT_EQ(result, expectedSoundex);
}

// Test for edge cases
TEST(SoundexTest, SingleCharacter) {
    // Arrange
    std::string nameA = "A";
    std::string expectedSoundexA = "A000";
    
    std::string nameB = "B";
    std::string expectedSoundexB = "B010";

    // Act
    std::string resultA = generateSoundexCode(nameA);
    std::string resultB = generateSoundexCode(nameB);

    // Assert
    EXPECT_EQ(resultA, expectedSoundexA);
    EXPECT_EQ(resultB, expectedSoundexB);
}

TEST(SoundexTest, EmptyString) {
    // Arrange
    std::string name = "";
    std::string expectedSoundex = "0000";

    // Act
    std::string result = generateSoundexCode(name);

    // Assert
    EXPECT_EQ(result, expectedSoundex);
}

// Test for names with all same characters
TEST(SoundexTest, RepeatedCharacters) {
    // Arrange
    std::string name = "LLLL";
    std::string expectedSoundex = "L400";

    // Act
    std::string result = generateSoundexCode(name);

    // Assert
    EXPECT_EQ(result, expectedSoundex);
}

// Test for names with mixed cases
TEST(SoundexTest, MixedCase) {
    // Arrange
    std::string name = "mIlLeR";
    std::string expectedSoundex = "M460";

    // Act
    std::string result = generateSoundexCode(name);

    // Assert
    EXPECT_EQ(result, expectedSoundex);
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
