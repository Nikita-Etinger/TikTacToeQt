#ifndef TICTACTOE_H
#define TICTACTOE_H

#include <QMainWindow>
#include <QPushButton>
#include <QLabel>

QT_BEGIN_NAMESPACE
namespace Ui { class TicTacToe; }
QT_END_NAMESPACE

class TicTacToe : public QMainWindow
{
    Q_OBJECT

public:
    TicTacToe(QWidget *parent = nullptr);
    ~TicTacToe();

private slots:
    void onButtonClick();
    void resetGame();
    void checkForWinner();

private:
    Ui::TicTacToe *ui;
    QPushButton* buttons[9];
    QPushButton* btnReset;
    QLabel* label;
    enum class Player { None, X, O };
    Player currentPlayer;
    bool gameOver;
};

#endif // TICTACTOE_H
