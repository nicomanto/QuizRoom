#ifndef MENUBUTTON_H
#define MENUBUTTON_H


#include <QMenu>
#include <QPushButton>

class MenuButton : public QMenu{
    Q_OBJECT

private:
    QPushButton* button;

    void showEvent(QShowEvent* event);

public:
    explicit MenuButton(QPushButton* button, QWidget* parent = nullptr);


};


#endif // MENUBUTTON_H
