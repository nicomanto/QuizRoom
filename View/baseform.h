#ifndef BASEFORM_H
#define BASEFORM_H
#include <QBoxLayout>
#include <QStyle>
#include <QScreen>
#include <QApplication>
#include <QDesktopWidget>

class BaseForm: public QWidget{
protected:
    QBoxLayout *main_layout;  //layout principale
    int height_screen;  //altezza dello screen del pc
    int width_screen;  //larghezza dello screen del pc


    //aggiunta dei form all view
    virtual void addForm()=0;

    //modifica dello stile alla view
    virtual void setStyle();
public:
    explicit BaseForm(QWidget *parent = nullptr);

    virtual ~BaseForm();

};

#endif // BASEFORM_H
