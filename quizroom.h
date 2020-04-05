#ifndef QUIZROOM_H
#define QUIZROOM_H

#include <QWidget>

QT_BEGIN_NAMESPACE
namespace Ui { class QuizRoom; }
QT_END_NAMESPACE

class QuizRoom : public QWidget
{
    Q_OBJECT

public:
    QuizRoom(QWidget *parent = nullptr);
    ~QuizRoom();

private:
    Ui::QuizRoom *ui;
};
#endif // QUIZROOM_H
