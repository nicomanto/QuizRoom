#ifndef ERRORDIALOG_H
#define ERRORDIALOG_H

#include <QVBoxLayout>
#include <QLabel>
#include <QDialog>


class ErrorDialog : public QDialog{
private:
    QVBoxLayout* layout_error;
    QLabel* msg;
public:
    explicit ErrorDialog(const QString& m, QWidget *parent);
    ~ErrorDialog()= default;
};

#endif // ERRORDIALOG_H
