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
        main.cpp \
        mainwindow.cpp

HEADERS += \
        mainwindow.h \
    lib/etlbase.h \
    lib/Eigen/Cholesky \
    lib/Eigen/CholmodSupport \
    lib/Eigen/Core \
    lib/Eigen/Dense \
    lib/Eigen/Eigen \
    lib/Eigen/Eigenvalues \
    lib/Eigen/Geometry \
    lib/Eigen/Householder \
    lib/Eigen/IterativeLinearSolvers \
    lib/Eigen/Jacobi \
    lib/Eigen/LU \
    lib/Eigen/MetisSupport \
    lib/Eigen/OrderingMethods \
    lib/Eigen/PardisoSupport \
    lib/Eigen/PaStiXSupport \
    lib/Eigen/QR \
    lib/Eigen/QtAlignedMalloc \
    lib/Eigen/Sparse \
    lib/Eigen/SparseCholesky \
    lib/Eigen/SparseCore \
    lib/Eigen/SparseLU \
    lib/Eigen/SparseQR \
    lib/Eigen/SPQRSupport \
    lib/Eigen/StdDeque \
    lib/Eigen/StdList \
    lib/Eigen/StdVector \
    lib/Eigen/SuperLUSupport \
    lib/Eigen/SVD \
    lib/Eigen/UmfPackSupport

FORMS += \
        mainwindow.ui

DISTFILES += \
    lib/Eigen/CMakeLists.txt
