#include <iostream>
#include <vector>
#include "clsString.h"  // Ensure this path is correct for your project

using namespace std;


int main() {
    // Create an instance of clsString
    clsString str("Hello, World! Welcome to [C++] String Library.");

    // Test Length
    cout << "Length: " << str.Length() << endl;

    // Test PrintFirstLetterOfEachWord

    cout << "First letters of each word:" << endl;
    str.PrintFirstLettleOfEachWord();

    // Test UpperFirstLetterOfEachWord
    str.UpperFirstLettleOfEachWord();
    cout << "UpperFirstLetterOfEachWord: " << str.GetValue() << endl;

    // Test LowerFirstLetterOfEachWord
    str.LowerFirstLettleOfEachWord();
    cout << "LowerFirstLetterOfEachWord: " << str.GetValue() << endl;

    // Test UpperAllString
    str.UpperAllString();
    cout << "UpperAllString: " << str.GetValue() << endl;

    // Test InvertAllStringLettersCase
    str.InvertAllStringLettlersCase();
    cout << "InvertAllStringLettersCase: " << str.GetValue() << endl;

    // Test CounterWords
    cout << "CounterWords: " << str.CounterWords() << endl;

    // Test Trim
    clsString strWithSpaces("   Hello, World!   ");
    strWithSpaces.Trim();
    cout << "Trim: '" << strWithSpaces.GetValue() << "'" << endl;

    // Test SplitString
    vector <string> words = str.SplitString(" ");
    cout << "SplitString: ";
    for (const string& word : words) {
        cout << "'" << word << "' ";
    }
    cout << endl;

    // Test JoinSplit
    string joined = clsString::JoinSplit(words, " ");
    cout << "JoinSplit: " << joined << endl;

    // Test ReverseWords
    str.ReverseWords();
    cout << "ReverseWords: " << str.GetValue() << endl;

    // Test LowerAllString
    str.LowerAllString();
    cout << "LowerAllString: " << str.GetValue() << endl;

    // Test ReplaceWord
    str.ReplaceWord("world", "Universe", false);
    cout << "ReplaceWord: " << str.GetValue() << endl;

    // Test RemovePunctuationsFromString
    str.RemovePunctuationsFromString();
    cout << "RemovePunctuationsFromString: " << str.GetValue() << endl;

    // Test PrintVowels
    cout << "Vowels in string: ";
    str.PrintVowels();
    cout << endl;

    // Test CountVowels
    cout << "CountVowels: " << str.CountVowels() << endl;

    // Test CountLetter
    cout << "CountLetter 'l': " << str.CountLetter('l') << endl;
    return 0;
}
