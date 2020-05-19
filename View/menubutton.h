#ifndef MENUBUTTON_H
#define MENUBUTTON_H


#include <QMenu>
#include <QPushButton>

class MenuButton : public QMenu{
    Q_OBJECT

private:
    unsigned int index;

    QPushButton* button;

    void showEvent(QShowEvent* event);

public:
    explicit MenuButton(unsigned int i, QPushButton* button, QWidget* parent = nullptr);


};


#endif // MENUBUTTON_H
