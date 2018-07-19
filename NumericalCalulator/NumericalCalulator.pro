#-------------------------------------------------
#
# Project created by QtCreator 2018-07-13T14:21:51
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = NumericalCalulator
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0


SOURCES += \
    App/app.cpp \
    main.cpp \
    Viewmodel/viewmodel.cpp \
    Model/model.cpp \
    View/view.cpp \
    Viewmodel/Command/getexpressioncommand.cpp \
    Parameter/parameter.cpp \
    Common/command.cpp \
    Notification/notification.cpp \
    Notification/outputnumericalresultnotification_viewmodel.cpp \
    Notification/outputnumericalresultnotification_view.cpp \
    Common/matrix.cpp \
    Common/polynomial.cpp \
    Common/matrix.cpp \
    Common/matrix.cpp \
    Common/polynomial.cpp \
    Notification/outputerrornotification_view.cpp \
    Algorithm/matrixparser.cpp \
    Algorithm/computedeterminant.cpp \
    Algorithm/solvepolynomialequation.cpp \
    Common/drawpolynomialcurve.cpp \
    Common/point.cpp \
    Algorithm/generalparser.cpp \
    Common/functionname.cpp \
    Algorithm/matrixtransformation.cpp \
    Common/polynomial.cpp \
    View/curveform.cpp


HEADERS += \
    App/app.h \
    App/app.h \
    Viewmodel/viewmodel.h \
    Model/model.h \
    View/view.h \
    Viewmodel/Command/getexpressioncommand.h \
    Parameter/parameter.h \
    Common/command.h \
    Notification/notification.h \
    Notification/outputnumericalresultnotification_viewmodel.h \
    Notification/outputnumericalresultnotification_view.h \
    Common/matrix.h \
    Common/polynomial.h \
    Common/matrix.h \
    Common/matrix.h\
    Common/etlbase.h \
    Notification/outputerrornotification_view.h \
    Algorithm/matrixparser.h \
    Algorithm/computedeterminant.h \
    Algorithm/solvepolynomialequation.h \
    Common/polynomial.h \
    Common/drawpolynomialcurve.h \
    Common/point.h \
    Algorithm/generalparser.h \
    Common/functionname.h \
    Algorithm/matrixtransformation.h \
    Common/polynomial.h \
    View/curveform.h


FORMS += \
    View/view.ui \
    View/curveform.ui

DISTFILES += \
    NumericalCalulator.pro.user \
    Common/Eigen/CMakeLists.txt

SUBDIRS += \
    NumericalCalulator.pro \
