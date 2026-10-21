#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
using namespace std;

enum enQuestionsLevel
{
    Easy = 1,
    Medium = 2,
    Hard = 3,
    MixLevel = 4
};

enum enOperationType
{
    Add = 1,
    Sub = 2,
    Mul = 3,
    Div = 4,
    Mix = 5
};

struct stQuestion
{
    int FirstNumber;
    int SecondNumber;
    enQuestionsLevel Questionlevel;
    enOperationType OperationType;
    float Answer;
    float UserAnswer;
    bool isCorrectAnswer;
};

struct stQuiz
{
    stQuestion Question[100];
    int TotalQuestion;
    enQuestionsLevel QuestionLevel;
    enOperationType OperationType;
    int RightAnswerCount = 0;
    int WrongAnswerCount = 0;
    bool isPass;
};

int readInteger(string message)
{
    int num;
    cout << message;
    cin >> num;
    return num;
}

int readIntegerInRange(short from, short to, string message)
{
    int num;
    do
    {
        num = readInteger(message);

    } while (num > to || num < from);
    return num;
}

float readFloat(string message)
{
    float num;
    cout << message;
    cin >> num;
    return num;
}

int randomNumber(int from, int to)
{
    return (rand() % (to - from + 1) + from);
}

int getNumberLevel(enQuestionsLevel level)
{

    switch (level)
    {
    case enQuestionsLevel::Easy:
        return randomNumber(1, 10);
    case enQuestionsLevel::Medium:
        return randomNumber(11, 50);
    default:
        return randomNumber(51, 100);
    }
}

enOperationType getOperationType(enOperationType op)
{
    if (op == enOperationType::Mix)
        return ((enOperationType)randomNumber(1, 4));
    else
        return op;
}

float calculateAnswer(float num1, float num2, enOperationType opType)
{
    switch (opType)
    {
    case enOperationType::Add:
        return num1 + num2;
    case enOperationType::Div:
        return num1 / num2;
    case enOperationType::Mul:
        return num1 * num2;

    default:
        return num1 - num2;
    }
}

enQuestionsLevel setQuestionLevel(enQuestionsLevel questionsLevel)
{
    if (questionsLevel == enQuestionsLevel::MixLevel)
        return (enQuestionsLevel)randomNumber(1, 3);
    else
        return questionsLevel;
}

stQuestion generateQuestion(const stQuiz &quiz)
{
    stQuestion question;
    question.Questionlevel = setQuestionLevel(quiz.QuestionLevel);
    question.FirstNumber = getNumberLevel(question.Questionlevel);
    question.SecondNumber = getNumberLevel(question.Questionlevel);
    question.OperationType = getOperationType(quiz.OperationType);
    question.Answer = calculateAnswer(question.FirstNumber, question.SecondNumber, question.OperationType);

    return question;
}

void generateQuizQuestions(stQuiz &quiz)
{
    for (int questionNumber = 0; questionNumber < quiz.TotalQuestion; questionNumber++)
    {
        quiz.Question[questionNumber] = generateQuestion(quiz);
    }
}

stQuiz generateQuiz(int totalQuestions)
{
    stQuiz quiz;
    quiz.TotalQuestion = totalQuestions;
    quiz.QuestionLevel = (enQuestionsLevel)readIntegerInRange(1, 4, "Enter Questions Level [1] Easy, [2] Medium, [3] Hard, [4] Mix ?  \n");
    quiz.OperationType = (enOperationType)readIntegerInRange(1, 5, "Enter Operation Type [1] Add, [2] Sub, [3] Mul, [4] Div, [5] Mix ?  \n");
    generateQuizQuestions(quiz);
    return quiz;
}

string getOperationSymbol(enOperationType opType)
{
    string arrOp[] = {"+", "-", "*", "/", "Mix"};
    return arrOp[(int)opType - 1];
}

void printQuizQuestion(int questionNumber, const stQuiz &quiz)
{
    cout << "\n\nQuestion [" << questionNumber + 1 << "/" << quiz.TotalQuestion << "]\n\n";
    cout << quiz.Question[questionNumber].FirstNumber << endl;
    cout << quiz.Question[questionNumber].SecondNumber << "  " << getOperationSymbol(quiz.Question[questionNumber].OperationType) << endl;
    cout << "______________\n";
}

void checkUserAnswer(int questionNumber, stQuiz &quiz)
{
    if ((int)(quiz.Question[questionNumber].Answer * 10) == (int)(quiz.Question[questionNumber].UserAnswer * 10))
        quiz.Question[questionNumber].isCorrectAnswer = true;
    else
        quiz.Question[questionNumber].isCorrectAnswer = false;
}

void setScreenColor(bool isCorrectAnswer)
{
    if (isCorrectAnswer)
        system("color 2F");
    else
    {
        system("color 4F");
        cout << "\a";
    }
}

void updateFinalResult(int questionNumber, stQuiz &quiz)
{
    if (quiz.Question[questionNumber].isCorrectAnswer)
        quiz.RightAnswerCount++;
    else
        quiz.WrongAnswerCount++;
}

void printQuestionResult(bool isCorrectAnswer, float answer)
{
    setScreenColor(isCorrectAnswer);
    if (isCorrectAnswer)
    {
        cout << "Right Answer :)" << endl;
    }
    else
    {
        cout << "Wrong Answer :(" << endl;
        answer = (int)(answer * 10);
        cout << "The right answer is : " << answer / 10 << endl;
    }
}

void checkFinalResult(stQuiz &quiz)
{
    if (quiz.RightAnswerCount >= quiz.WrongAnswerCount)
        quiz.isPass = true;
    else
        quiz.isPass = false;
}

void startQuiz(stQuiz &quiz)
{
    cout << "\n\nNote:For decimals, please use only 1 decimal place.";

    for (int questionNumber = 0; questionNumber < quiz.TotalQuestion; questionNumber++)
    {
        printQuizQuestion(questionNumber, quiz);

        float userAnswer = readFloat("");
        quiz.Question[questionNumber].UserAnswer = userAnswer;

        checkUserAnswer(questionNumber, quiz);
        updateFinalResult(questionNumber, quiz);
        printQuestionResult(quiz.Question[questionNumber].isCorrectAnswer, quiz.Question[questionNumber].Answer);
    }

    checkFinalResult(quiz);
}

string getFinalResult(bool isPass)
{
    if (isPass)
        return "PASS";
    else
        return "FAIL";
}

string getQuestionsLevel(enQuestionsLevel questionsLevel)
{
    string arrLevels[] = {"Easy", "Medium", "Hard", "Mix"};
    return arrLevels[(int)questionsLevel - 1];
}

void printQuizResult(const stQuiz &quiz)
{
    setScreenColor(quiz.isPass);

    cout << "\n______________________________________\n\n";
    cout << "\tFinal Results is " << getFinalResult(quiz.isPass) << endl;
    cout << "\n______________________________________\n\n";
    cout << "Number of Questions     : " << quiz.TotalQuestion << endl;
    cout << "Questions Level         : " << getQuestionsLevel(quiz.QuestionLevel) << endl;
    cout << "Operation Type          : " << getOperationSymbol(quiz.OperationType) << endl;
    cout << "Number Of Right Answers : " << quiz.RightAnswerCount << endl;
    cout << "Number Of Wrong Answers : " << quiz.WrongAnswerCount << endl;
    cout << "\n______________________________________\n";
}

void resetScreen()
{
    system("cls");
    system("color 0F");
}

bool playAgain(string message)
{
    char letter;
    do
    {
        cout << message;
        cin >> letter;
    } while (letter != 'y' && letter != 'n' && letter != 'Y' && letter != 'N');
    return (letter == 'y' || letter == 'Y');
}

void startSystem()
{
    do
    {
        resetScreen();

        stQuiz quiz = generateQuiz(readIntegerInRange(1, 100, "How Many Questions do you want to answer? (1-100)? \n"));

        startQuiz(quiz);

        printQuizResult(quiz);

    } while (playAgain("Do you want to play again? Y/N? "));
}

int main()
{
    srand((unsigned)time(NULL));

    startSystem();

    return 0;
}
// Created By HaDy;
