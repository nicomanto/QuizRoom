#ifndef ERRORMESSAGE_H
#define ERRORMESSAGE_H

#include <QVBoxLayout>
#include <QLabel>
#include <QMessageBox>
#include <QIcon>
#include <QStyle>
#include <QScreen>
#include <QApplication>
#include <QDesktopWidget>



class ErrorMessage : public QMessageBox{
public:
    explicit ErrorMessage(const QString& m, QWidget *parent=nullptr);
    ~ErrorMessage()= default;
};

#endif // ERRORMESSAGE_H
