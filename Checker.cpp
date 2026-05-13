#include <iostream>
#include <string>
#include <cctype>

using namespace std;

int calculateScore(string pass) {
    int score = 0;
    int len = pass.length();
    
    if(len >= 12) {
        score += 3;
    } else if(len >= 8) {
        score += 2;
    } else if(len >= 6) {
        score += 1;
    }
    
    bool hasUpper = false;
    bool hasLower = false;
    bool hasDigit = false;
    bool hasSpecial = false;
    
    for(int i = 0; i < len; i++) {
        char c = pass[i];
        if(isupper(c)) hasUpper = true;
        else if(islower(c)) hasLower = true;
        else if(isdigit(c)) hasDigit = true;
        else hasSpecial = true;
    }
    
    if(hasUpper) score += 2;
    if(hasLower) score += 2;
    if(hasDigit) score += 2;
    if(hasSpecial) score += 3;
    
    return score;
}

string getStrength(int score) {
    if(score >= 10) return "STRONG";
    else if(score >= 6) return "MEDIUM";
    else return "WEAK";
}

void showFeedback(string pass, int score, string strength) {
    cout << "\n=== RESULTS ===" << endl;
    cout << "Password: " << pass << endl;
    cout << "Score: " << score << "/12" << endl;
    cout << "Strength: " << strength << endl;
    
    cout << "\n=== TIPS ===" << endl;
    if(strength == "WEAK") {
        cout << "- Make it at least 8 characters" << endl;
        cout << "- Add numbers and symbols" << endl;
        cout << "- Mix uppercase and lowercase" << endl;
    } else if(strength == "MEDIUM") {
        cout << "- Add special characters (!@#$%)" << endl;
        cout << "- Make it longer (12+ chars)" << endl;
    } else {
        cout << "Good password! Keep it safe." << endl;
    }
}

int main() {
    cout << "=== PASSWORD STRENGTH CHECKER ===" << endl;
    cout << "Enter a password to check: ";
    
    string password;
    cin >> password;
    
    int score = calculateScore(password);
    string strength = getStrength(score);
    
    showFeedback(password, score, strength);
    
    return 0;
}
