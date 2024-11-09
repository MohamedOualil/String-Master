#pragma once
#include <iostream>
#include <vector>

using namespace std;

class clsString
{
    string _Value;

public:
    clsString() {
        _Value = "";
    }

    clsString(string Value) {
        _Value = Value;
    }

    void SetValue(string Value) {
        _Value = Value;
    }

    string GetValue() {
        return _Value;
    }

    __declspec (property(get = GetValue, put = SetValue)) string Value;

    static int Length(string S1) {
        return S1.length();
    }

    int Length() {
        return _Value.length();
    }

    static void PrintFirstLettleOfEachWord(string S1) {
        bool IsFistLettle = true;

        for (short i = 0; i < S1.length(); i++) {

            if (S1[i] != ' ' && IsFistLettle) {

                cout << S1[i] << endl;
            }
            IsFistLettle = (S1[i] == ' ' ? true : false);
        }
    }

    void PrintFirstLettleOfEachWord() {
        PrintFirstLettleOfEachWord(_Value);
    }

    static string UpperFirstLettleOfEachWord(string S1) {
        bool IsFirstLettler = true;

        for (short i = 0; i < S1.length(); i++) {

            if (S1[i] != ' ' && IsFirstLettler) {

                S1[i] = toupper(S1[i]);
            }
            IsFirstLettler = (S1[i] == ' ' ? true : false);
        }
        return S1;
    }

    void UpperFirstLettleOfEachWord() {
        _Value = UpperFirstLettleOfEachWord(_Value);
    }

    static string LowerFirstLettleOfEachWord(string S1) {
        bool IsFirstLettler = true;

        for (short i = 0; i < S1.length(); i++) {

            if (S1[i] != ' ' && IsFirstLettler) {

                S1[i] = tolower(S1[i]);
            }
            IsFirstLettler = (S1[i] == ' ' ? true : false);
        }
        return S1;
    }

    void LowerFirstLettleOfEachWord() {
        _Value = LowerFirstLettleOfEachWord(_Value);
    }

    static string UpperAllString(string S1) {

        for (short i = 0; i < S1.length(); i++) {

            S1[i] = toupper(S1[i]);
        }
        return S1;
    }

    void UpperAllString() {
        _Value = UpperAllString(_Value);

    }

    static string InvertAllStringLettlersCase(string S1) {

        for (short i = 0; i < S1.length(); i++) {

            S1[i] = InvertLetterCase(S1[i]);
        }
        return S1;
    }

    void InvertAllStringLettlersCase() {
        _Value = InvertAllStringLettlersCase(_Value);
    }

    static short CounterWords(string S1) {
        string delim = " ";
        short counter = 0;

        short pos = 0;
        string sWord;
        while ((pos = S1.find(delim)) != std::string::npos) {

            sWord = S1.substr(0, pos);

            if (sWord != "") {

                counter++;
            }
            S1.erase(0, pos + delim.length());
        }
        if (S1 != "") {
            counter++;
        }
        return counter;

    }

    short CounterWords() {
        return CounterWords(_Value);
    }

    static string TrimLeft(string S1) {

        for (short i = 0; i < S1.length(); i++) {
            if (S1[i] != ' ') {
                return S1.substr(i, S1.length() - i);
            }
        }
        return "";
    }

    void TrimLeft() {
        _Value = TrimLeft(_Value);
    }

    static  string TrimRight(string S1) {

        for (short i = S1.length() - 1; i > 0; i--) {
            if (S1[i] != ' ') {
                return S1.substr(0, i + 1);
            }
        }
        return "";
    }

    void TrimRight() {
        _Value = TrimRight(_Value);
    }

    static string Trim(string S1) {

        return TrimRight(TrimLeft(S1));

    }

    void Trim() {
        _Value = Trim(_Value);
    }

    static vector<string> SplitString(string S1, string delim) {
        vector<string> vString;

        short pos = 0;
        string sWord;
        while ((pos = S1.find(delim)) != std::string::npos) {

            sWord = S1.substr(0, pos);

            if (sWord != "") {

                vString.push_back(sWord);
            }
            S1.erase(0, pos + delim.length());
        }
        if (S1 != "") {
            vString.push_back(S1);
        }

        return vString;
    }

    vector<string> SplitString(string delim) {
        return SplitString(_Value, delim);
    }

    static string JoinSplit(vector <string>& vString, string delim) {
        string S1 = "";

        for (string& s : vString) {
            S1 = S1 + s + delim;
        }
        return S1.substr(0, S1.length() - delim.length());
    }

    static string ReverseWords(string S1) {
        string S2 = "";

        vector <string> vString;
        vString = SplitString(S1, " ");

        vector <string> ::iterator iter = vString.end();


        while (iter != vString.begin()) {
            --iter;
            S2 += *iter + " ";
        }
        return S2.substr(0, S2.length() - 1);// remove last spase.
    }

    void ReverseWords() {
        _Value = ReverseWords(_Value);
    }

    static string LowerAllString(string S1) {

        for (short i = 0; i < S1.length(); i++) {

            S1[i] = tolower(S1[i]);
        }
        return S1;
    }

    void LowerAllString() {
        _Value = LowerAllString(_Value);
    }

    static string ReplaceWord(string S1, string StringToReplace, string ReplaceTo, bool MatchCase = true) {
        vector<string> vString;
        vString = SplitString(S1, " ");

        for (string& S : vString) {

            if (MatchCase) {

                if (S == StringToReplace)
                    S = ReplaceTo;
            }
            else {
                if (LowerAllString(S) == LowerAllString(StringToReplace)) {
                    S = ReplaceTo;
                }
            }
        }
        return JoinSplit(vString, " ");
    }

    void ReplaceWord(string StringToReplace, string ReplaceTo, bool MatchCase = true) {
        _Value = ReplaceWord(_Value, StringToReplace, ReplaceTo, MatchCase);
    }

    static bool isItPunctuations(char char1) {
        return ((char1 > 33 && char1 < 47) || (char1 > 58 && char1 < 64)) ? true : false;
    }

    static string RemovePunctuationsFromString(string S1) {
        string S2 = "";
        for (short i = 0; i < S1.length(); i++) {

            if (!ispunct(S1[i])) {
                S2 += S1[i];
            }
        }
        return S2;
    }

    void RemovePunctuationsFromString() {
        _Value = RemovePunctuationsFromString(_Value);
    }

    static bool IsVowel(char letter) {

        letter = tolower(letter);
        return ((letter == 'a') || (letter == 'e') || (letter == 'i') || (letter == 'o') || (letter == 'u'));
    }

    static void PrintVowels(string S1) {
        cout << "\nNumber of Vowels is : ";
        for (short i = 0; i < S1.length(); i++) {

            if (IsVowel(S1[i]))
                cout << S1[i] << "   ";
        }
    }

    void PrintVowels() {
        return PrintVowels(_Value);
    }

    static short CountVowels(string S1) {
        short counter = 0;
        for (short i = 0; i < S1.length(); i++) {

            if (IsVowel(S1[i]))
                counter++;
        }
        return counter;
    }

    short CountVowels() {
        return CountVowels(_Value);
    }

    static char InvertLetterCase(char Char1) {

        return isupper(Char1) ? tolower(Char1) : toupper(Char1);
    }

    static short CountLetter(string S1, char Letter, bool MatchCase = true) {
        short Counter = 0;

        for (short i = 0; i < S1.length(); i++) {
            if (MatchCase) {
                if (Letter == S1[i])
                    Counter++;
            }
            else {
                if (tolower(S1[i]) == tolower(Letter))
                    Counter++;
            }
        }
        return Counter;
    }

    short CountLetter(char Letter, bool MatchCase = true) {
        return CountLetter(_Value, Letter, MatchCase);
    }


};

