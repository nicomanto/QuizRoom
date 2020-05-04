#ifndef FORMVIRTUAL_H
#define FORMVIRTUAL_H
#include <QBoxLayout>
#include <QMenuBar>
#include <QWidget>
#include <QStyle>
#include <QScreen>
#include <QApplication>
#include <QDesktopWidget>

class BaseForm: public QWidget{
    Q_OBJECT
protected:
    QBoxLayout *main_layout;
    QMenuBar* menubar;
    int height_screen;
    int width_screen;
public:
    explicit BaseForm(QWidget *parent = nullptr, QBoxLayout* main_l=nullptr, QMenuBar* bar=nullptr);

    virtual ~BaseForm();

    virtual void addMenu()=0;

    virtual void addForm()=0;

    virtual void setStyle();
signals:

public slots:
};

#endif // FORMVIRTUAL_H
