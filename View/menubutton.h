#ifndef MENUBUTTON_H
#define MENUBUTTON_H


#include <QMenu>
#include <QPushButton>


//classe per la creazione del menu a tendina che mostra la tendinda a destra del menu
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
