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
    QBoxLayout *main_layout;  //layout principale
    int height_screen;  //altezza dello screen del pc
    int width_screen;  //larghezza dello screen del pc



    virtual void addForm()=0;

    virtual void setStyle();
public:
    explicit BaseForm(QWidget *parent = nullptr);

    virtual ~BaseForm();





signals:

public slots:
};

#endif // BASEFORM_H
