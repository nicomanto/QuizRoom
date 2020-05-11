#include "menubutton.h"

MenuButton::MenuButton(QPushButton* b, QWidget* parent) : QMenu(parent), button(b){
}

void MenuButton::showEvent(QShowEvent* event){

    //setto il menu a tendina del bottone a sinistra del bottne
    QPoint p = this->pos();
    QRect geo = button->geometry();
    this->move(p.x()+geo.width()-this->geometry().width(), p.y());
}
