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
    QLabel *label;
    QPushButton *btn_plus;
    QPushButton *btn_rename;
    QLineEdit *le_root;
    QPushButton *btn_cut;
    QLineEdit *le_size;
    QPushButton *btn_res;
    QLineEdit *le_res;
    QLabel *label_2;
    QPushButton *btn_root;
    QPushButton *btn_resize;
    QLabel *label_3;
    QPushButton *btn_renameAll;
    QPushButton *btn_sclar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *DataProcessClass)
    {
        if (DataProcessClass->objectName().isEmpty())
            DataProcessClass->setObjectName(QStringLiteral("DataProcessClass"));
        DataProcessClass->resize(455, 332);
        centralWidget = new QWidget(DataProcessClass);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        label = new QLabel(centralWidget);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(20, 30, 71, 16));
        btn_plus = new QPushButton(centralWidget);
        btn_plus->setObjectName(QStringLiteral("btn_plus"));
        btn_plus->setGeometry(QRect(300, 130, 75, 23));
        btn_rename = new QPushButton(centralWidget);
        btn_rename->setObjectName(QStringLiteral("btn_rename"));
        btn_rename->setGeometry(QRect(80, 130, 75, 23));
        le_root = new QLineEdit(centralWidget);
        le_root->setObjectName(QStringLiteral("le_root"));
        le_root->setGeometry(QRect(90, 30, 271, 20));
        btn_cut = new QPushButton(centralWidget);
        btn_cut->setObjectName(QStringLiteral("btn_cut"));
        btn_cut->setGeometry(QRect(190, 130, 75, 23));
        le_size = new QLineEdit(centralWidget);
        le_size->setObjectName(QStringLiteral("le_size"));
        le_size->setGeometry(QRect(150, 190, 113, 20));
        btn_res = new QPushButton(centralWidget);
        btn_res->setObjectName(QStringLiteral("btn_res"));
        btn_res->setGeometry(QRect(390, 70, 31, 23));
        le_res = new QLineEdit(centralWidget);
        le_res->setObjectName(QStringLiteral("le_res"));
        le_res->setGeometry(QRect(90, 70, 271, 20));
        label_2 = new QLabel(centralWidget);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(20, 70, 71, 16));
        btn_root = new QPushButton(centralWidget);
        btn_root->setObjectName(QStringLiteral("btn_root"));
        btn_root->setGeometry(QRect(390, 30, 31, 23));
        btn_resize = new QPushButton(centralWidget);
        btn_resize->setObjectName(QStringLiteral("btn_resize"));
        btn_resize->setGeometry(QRect(300, 190, 75, 23));
        label_3 = new QLabel(centralWidget);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(80, 190, 61, 16));
        btn_renameAll = new QPushButton(centralWidget);
        btn_renameAll->setObjectName(QStringLiteral("btn_renameAll"));
        btn_renameAll->setGeometry(QRect(30, 250, 75, 23));
        btn_sclar = new QPushButton(centralWidget);
        btn_sclar->setObjectName(QStringLiteral("btn_sclar"));
        btn_sclar->setGeometry(QRect(130, 250, 75, 23));
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
        label->setText(QApplication::translate("DataProcessClass", "\351\200\211\346\213\251\346\240\271\347\233\256\345\275\225\357\274\232", Q_NULLPTR));
        btn_plus->setText(QApplication::translate("DataProcessClass", "plus", Q_NULLPTR));
        btn_rename->setText(QApplication::translate("DataProcessClass", "rename", Q_NULLPTR));
        btn_cut->setText(QApplication::translate("DataProcessClass", "cut", Q_NULLPTR));
        btn_res->setText(QApplication::translate("DataProcessClass", "....", Q_NULLPTR));
        label_2->setText(QApplication::translate("DataProcessClass", "\347\273\223\346\236\234\344\277\235\345\255\230\345\210\260\357\274\232", Q_NULLPTR));
        btn_root->setText(QApplication::translate("DataProcessClass", "...", Q_NULLPTR));
        btn_resize->setText(QApplication::translate("DataProcessClass", "resize", Q_NULLPTR));
        label_3->setText(QApplication::translate("DataProcessClass", "\345\260\272\345\257\270\350\256\276\347\275\256\357\274\232", Q_NULLPTR));
        btn_renameAll->setText(QApplication::translate("DataProcessClass", "renameAll", Q_NULLPTR));
        btn_sclar->setText(QApplication::translate("DataProcessClass", "sclar", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class DataProcessClass: public Ui_DataProcessClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DATAPROCESS_H
