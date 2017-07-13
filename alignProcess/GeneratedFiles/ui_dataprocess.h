/********************************************************************************
** Form generated from reading UI file 'dataprocess.ui'
**
** Created by: Qt User Interface Compiler version 5.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DATAPROCESS_H
#define UI_DATAPROCESS_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_DataProcessClass
{
public:
    QWidget *centralWidget;
    QPushButton *btn_root;
    QLineEdit *le_res;
    QLabel *label_2;
    QPushButton *btn_ai;
    QPushButton *btn_demo;
    QPushButton *btn_res;
    QLabel *label;
    QLineEdit *le_root;
    QPushButton *btn_icp;
    QPushButton *btn_as;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *DataProcessClass)
    {
        if (DataProcessClass->objectName().isEmpty())
            DataProcessClass->setObjectName(QStringLiteral("DataProcessClass"));
        DataProcessClass->resize(455, 209);
        centralWidget = new QWidget(DataProcessClass);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        btn_root = new QPushButton(centralWidget);
        btn_root->setObjectName(QStringLiteral("btn_root"));
        btn_root->setGeometry(QRect(380, 60, 31, 23));
        le_res = new QLineEdit(centralWidget);
        le_res->setObjectName(QStringLiteral("le_res"));
        le_res->setGeometry(QRect(80, 100, 271, 20));
        label_2 = new QLabel(centralWidget);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(10, 100, 71, 16));
        btn_ai = new QPushButton(centralWidget);
        btn_ai->setObjectName(QStringLiteral("btn_ai"));
        btn_ai->setGeometry(QRect(110, 140, 75, 23));
        btn_demo = new QPushButton(centralWidget);
        btn_demo->setObjectName(QStringLiteral("btn_demo"));
        btn_demo->setGeometry(QRect(10, 10, 75, 23));
        btn_res = new QPushButton(centralWidget);
        btn_res->setObjectName(QStringLiteral("btn_res"));
        btn_res->setGeometry(QRect(380, 100, 31, 23));
        label = new QLabel(centralWidget);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(10, 60, 71, 16));
        le_root = new QLineEdit(centralWidget);
        le_root->setObjectName(QStringLiteral("le_root"));
        le_root->setGeometry(QRect(80, 60, 271, 20));
        btn_icp = new QPushButton(centralWidget);
        btn_icp->setObjectName(QStringLiteral("btn_icp"));
        btn_icp->setGeometry(QRect(200, 140, 75, 23));
        btn_as = new QPushButton(centralWidget);
        btn_as->setObjectName(QStringLiteral("btn_as"));
        btn_as->setGeometry(QRect(10, 140, 75, 23));
        DataProcessClass->setCentralWidget(centralWidget);
        mainToolBar = new QToolBar(DataProcessClass);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        DataProcessClass->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(DataProcessClass);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        DataProcessClass->setStatusBar(statusBar);

        retranslateUi(DataProcessClass);

        QMetaObject::connectSlotsByName(DataProcessClass);
    } // setupUi

    void retranslateUi(QMainWindow *DataProcessClass)
    {
        DataProcessClass->setWindowTitle(QApplication::translate("DataProcessClass", "DataProcess", Q_NULLPTR));
        btn_root->setText(QApplication::translate("DataProcessClass", "...", Q_NULLPTR));
        label_2->setText(QApplication::translate("DataProcessClass", "\347\273\223\346\236\234\344\277\235\345\255\230\345\210\260\357\274\232", Q_NULLPTR));
        btn_ai->setText(QApplication::translate("DataProcessClass", "alignIter", Q_NULLPTR));
        btn_demo->setText(QApplication::translate("DataProcessClass", "showDemo", Q_NULLPTR));
        btn_res->setText(QApplication::translate("DataProcessClass", "....", Q_NULLPTR));
        label->setText(QApplication::translate("DataProcessClass", "\351\200\211\346\213\251\346\240\271\347\233\256\345\275\225\357\274\232", Q_NULLPTR));
        btn_icp->setText(QApplication::translate("DataProcessClass", "ICP", Q_NULLPTR));
        btn_as->setText(QApplication::translate("DataProcessClass", "alignSimp", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class DataProcessClass: public Ui_DataProcessClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DATAPROCESS_H
