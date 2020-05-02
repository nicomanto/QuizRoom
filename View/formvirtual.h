#ifndef FORMVIRTUAL_H
#define FORMVIRTUAL_H
#include <QVBoxLayout>
#include <QMenuBar>
#include <QWidget>
#include <QFile>

class FormVirtual: public QWidget{
    Q_OBJECT
protected:
    QVBoxLayout *main_layout;
    QMenuBar* menubar;

public:
    explicit FormVirtual(QWidget *parent = nullptr);

    virtual ~FormVirtual();

    virtual void addMenu()=0;

    virtual void addForm()=0;

    virtual void setStyle();
signals:

public slots:
};

#endif // FORMVIRTUAL_H
