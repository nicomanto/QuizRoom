QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# The following define makes your compiler emit warnings if you use
# any Qt feature that has been marked deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    Model/classicquiz.cpp \
    Model/combinequiz.cpp \
    Model/course.cpp \
    Model/date.cpp \
    Model/datetime.cpp \
    Model/homework.cpp \
    Model/malusquiz.cpp \
    Model/quiz.cpp \
    Model/quizcontainer.cpp \
    Model/scorehomework.cpp \
    Model/time.cpp \
    Model/timehomework.cpp \
    Model/timescorehomework.cpp \
    View/baseform.cpp \
    View/classicquizform.cpp \
    View/combinequizform.cpp \
    View/courseform.cpp \
    View/homeworkform.cpp \
    View/loginform.cpp \
    View/mainform.cpp \
    View/menubutton.cpp \
    View/principalform.cpp \
    View/quizbaseform.cpp \
    main.cpp \
    Model/quizroom.cpp \
    Model/user.cpp \
    Model/student.cpp \
    Model/teacher.cpp

HEADERS += \
    Model/classicquiz.h \
    Model/combinequiz.h \
    Model/course.h \
    Model/date.h \
    Model/datetime.h \
    Model/homework.h \
    Model/malusquiz.h \
    Model/myvector.h \
    Model/quiz.h \
    Model/quizcontainer.h \
    Model/quizroom.h \
    Model/scorehomework.h \
    Model/time.h \
    Model/timehomework.h \
    Model/timescorehomework.h \
    Model/user.h \
    Model/student.h \
    Model/teacher.h \
    View/baseform.h \
    View/classicquizform.h \
    View/combinequizform.h \
    View/courseform.h \
    View/homeworkform.h \
    View/loginform.h \
    View/mainform.h \
    View/menubutton.h \
    View/principalform.h \
    View/quizbaseform.h

FORMS += \
    quizroom.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    resources.qrc
