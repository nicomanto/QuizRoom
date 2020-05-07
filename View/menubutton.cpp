#include "menubutton.h"

MenuButton::MenuButton(QPushButton* b, QWidget* parent) : button(b), QMenu(parent){
}

void MenuButton::showEvent(QShowEvent* event)
{
    QPoint p = this->pos();
    QRect geo = button->geometry();
    this->move(p.x()+geo.width()-this->geometry().width(), p.y());
}
