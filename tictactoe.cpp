// В файле tictactoe.cpp
#include "tictactoe.h"
#include "ui_tictactoe.h"

TicTacToe::TicTacToe(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::TicTacToe)
{
    ui->setupUi(this);

    // Инициализация кнопок, сетки и метки
    buttons[0] = ui->btn1;
    buttons[1] = ui->btn2;
    buttons[2] = ui->btn3;
    buttons[3] = ui->btn4;
    buttons[4] = ui->btn5;
    buttons[5] = ui->btn6;
    buttons[6] = ui->btn7;
    buttons[7] = ui->btn8;
    buttons[8] = ui->btn9;

    btnReset = ui->btnReset;
    label = ui->label;

    // Подключение слотов к событиям нажатия на кнопки
    for (int i = 0; i < 9; i++) {
        connect(buttons[i], &QPushButton::clicked, this, &TicTacToe::onButtonClick);
    }
    connect(btnReset, &QPushButton::clicked, this, &TicTacToe::resetGame);

    // Инициализация игры
    currentPlayer = Player::X;
    gameOver = false;
}

// Слот для обработки нажатия на кнопку
void TicTacToe::onButtonClick() {
    QPushButton* buttonClicked = qobject_cast<QPushButton*>(sender());

    if (!gameOver && buttonClicked) {
        if (buttonClicked->text() == "") {
            buttonClicked->setText(currentPlayer == Player::X ? "X" : "O");
            checkForWinner();
            currentPlayer = (currentPlayer == Player::X) ? Player::O : Player::X;
        }
    }
}

// Слот для сброса игры
void TicTacToe::resetGame() {
    for (int i = 0; i < 9; i++) {
        buttons[i]->setText("");
    }

    label->setText("");
    currentPlayer = Player::X;
    gameOver = false;
}

void TicTacToe::checkForWinner() {
    //возможные комбинации выигрышных позиций
    int winCombinations[8][3] = {
        {0, 1, 2}, {3, 4, 5}, {6, 7, 8}, // Горизонтали
        {0, 3, 6}, {1, 4, 7}, {2, 5, 8}, // Вертикали
        {0, 4, 8}, {2, 4, 6}             // Диагонали
    };

    for (int i = 0; i < 8; i++) {
        int a = winCombinations[i][0];
        int b = winCombinations[i][1];
        int c = winCombinations[i][2];

        // Проверка, содержат ли все три кнопки одинаковые значения (X или O)
        if (buttons[a]->text() == buttons[b]->text() && buttons[b]->text() == buttons[c]->text() && buttons[a]->text() != "") {
            label->setText(buttons[a]->text() + " победил!");
            gameOver = true;
            return;
        }
    }

    // Проверка на ничью (если все клетки заполнены и нет победителя)
    bool draw = true;
    for (int i = 0; i < 9; i++) {
        if (buttons[i]->text() == "") {
            draw = false;
            break;
        }
    }
    if (draw) {
        label->setText("Ничья!");
        gameOver = true;
    }
}
TicTacToe::~TicTacToe(){


   delete ui;
}
