#ifndef MENUBUTTON_H
#define MENUBUTTON_H


#include <QMenu>
#include <QPushButton>

class MenuButton : public QMenu{
    Q_OBJECT

private:
    QPushButton* button;

public:
    explicit MenuButton(QPushButton* button, QWidget* parent = nullptr);
    void showEvent(QShowEvent* event);

};


#endif // MENUBUTTON_H
