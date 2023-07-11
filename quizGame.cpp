// Quiz Game using arrays

#include <iostream>
using std::cin;
using std::cout;
using std::string;

int main()
{
    string questions[] = {"1. Which one is the first search engine in internet ?",
                          "2. Number of bit used by the IPv6 address. ",
                          "3. Which programming language is used to create programs like applets ?",
                          "4. which one is the first web browser invented in 1990 ?",
                          "5. First computer virus is known as ..."};

    string answers[][5] = {
        {"A. Google",        "B. Archie",      "C. Altavista",      "D. WAIS" },
        {"A. 32-bit" ,       "B. 64-bit",     "C. 128-bit",      "D. 256-bit" },
        {"A. COBOL" ,       "B. C-language" ,     "C. Java",      "D. BASIC      "},
        {"A.Internet Explorer",        "B. Mosaic",     "C. Mozilla",      "D. Nexus      "},
        {"A. Rabbit" ,       "B. Creeper Virus",      "C. Eik Cloner",      "D. SCA Virus      "},
    };

    char answerKey[] = {'B', 'C', 'C', 'D', 'B'};

    int size = sizeof(questions) / sizeof(questions[0]);
    char guess;
    int score = 0;

    for (int i = 0; i < size; i++)
    {
        cout << "*************************************************" << std::endl;
        cout << "**                 QUESTIONS                   **" << std::endl;
        cout << "*************************************************" << std::endl;
        cout << questions[i] << std::endl;

        for (int j = 0; j < sizeof(answers[i]) / sizeof(answers[i][0]); j++)
        {
            cout << answers[i][j] << std::endl;
        }
        fflush(stdin);
        cin >> guess;
        guess = toupper(guess);

        if (guess == answerKey[i])
        {
            cout << "CORRECT \n";
            score++;
        }
        else
        {
            cout << "WRONG \n";
            cout << "Answer : " << answerKey[i] << '\n';
        }
    }

    cout << "*************************************************" << std::endl;
    cout << "**                 RESULT                   **" << std::endl;
    cout << "*************************************************" << std::endl;
    cout << "CORRECT GUESSES : " << score << std::endl;
    cout << "Your total score is : " << (score / (double)size) * 100 << "%" << std::endl;
    return 0;
}