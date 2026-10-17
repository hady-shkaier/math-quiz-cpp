# Math Quiz — C++ Console Application

An interactive, customizable math quiz built with C++. Generate random arithmetic questions, challenge yourself across multiple difficulty levels, and track your performance with instant feedback and a final results summary.

## Features

- **Customizable Quiz Length:** Choose from 1 to 100 questions per session.
- **Multiple Difficulty Levels:**
  - **Easy:** Numbers ranging from 1 to 10.
  - **Medium:** Numbers ranging from 11 to 50.
  - **Hard:** Numbers ranging from 51 to 100.
  - **Mixed:** Randomly selects a difficulty level for each question.
- **Arithmetic Operations:**
  - Addition (`+`)
  - Subtraction (`-`)
  - Multiplication (`*`)
  - Division (`/`)
  - **Mixed Operations:** Randomly selects an arithmetic operation for each question.
- **Instant Feedback:** Receive immediate confirmation when an answer is correct or incorrect, with the correct answer displayed when needed.
- **Visual and Audio Feedback:** Color-coded console output and a beep alert for incorrect answers.
- **Performance Tracking:** Tracks the number of correct and incorrect answers throughout the quiz.
- **Final Results Summary:** Displays the quiz outcome, selected difficulty, operation type, and answer statistics.
- **Replay Support:** Start another quiz with new settings without restarting the application.

## Getting Started

### Prerequisites

- A C++ compiler, such as GCC/G++ or MSVC.
- A Windows environment for the console color and screen-clearing commands.

### Installation and Execution

**1. Clone the repository**

```bash
git clone https://github.com/hady-shkaier/math-quiz-cpp
cd math-game-cpp

```

**2. Compile the source code**

Using GCC/G++:

```bash
g++ main.cpp -o MathQuiz.exe
```

**3. Run the application**

```bash
.\MathQuiz.exe
```

## How to Play

1. Choose the number of questions you want to answer (1–100).
2. Select a difficulty level:
   - `1` — Easy
   - `2` — Medium
   - `3` — Hard
   - `4` — Mixed
3. Select an arithmetic operation:
   - `1` — Addition
   - `2` — Subtraction
   - `3` — Multiplication
   - `4` — Division
   - `5` — Mixed Operations
4. Answer each question displayed in the console.
5. Review the feedback after every answer.
6. Check your final results and choose whether to play again.

**Note:** Division answers should be entered to one decimal place, as required by the current program.

## Code Structure

The project uses procedural C++ programming principles and separates the main tasks into dedicated functions.

- **Enumerations (`enQuestionsLevel`, `enOperationType`):** Represent difficulty levels and arithmetic operations using named constants.
- **Structures (`stQuestion`, `stQuiz`):** Organize question data, answers, difficulty settings, and quiz statistics.
- **Modular Functions:** Separate question generation, answer checking, result calculation, console output, and quiz execution.
- **Arrays and Loops:** Store quiz questions and process them sequentially.
- **Random Number Generation:** Generate question values, difficulty levels, and operations.

## Project Purpose

This project was developed to strengthen my C++ programming skills through practical implementation of structured data, modular functions, random question generation, input handling, and interactive console applications.

It is also an opportunity to practice code organization and improve readability while building a complete, playable project.

## Author

**Created by HaDy**

If you liked this project, feel free to give it a ⭐️ on GitHub!
