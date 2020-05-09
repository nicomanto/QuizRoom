#ifndef BASEFORM_H
#define BASEFORM_H
#include <QBoxLayout>
#include <QWidget>
#include <QStyle>
#include <QScreen>
#include <QApplication>
#include <QDesktopWidget>

class BaseForm: public QWidget{
    Q_OBJECT
protected:
    QBoxLayout *main_layout;
    int height_screen;
    int width_screen;
public:
    explicit BaseForm(QWidget *parent = nullptr);

    virtual ~BaseForm();

    virtual void addForm()=0;

    virtual void setStyle();
signals:

public slots:
};

#endif // BASEFORM_H
