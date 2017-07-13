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
    QPushButton *btn_calGrad;
    QLineEdit *le_root;
    QLineEdit *le_size;
    QPushButton *btn_res;
    QLineEdit *le_res;
    QLabel *label_2;
    QPushButton *btn_root;
    QLabel *label_3;
    QPushButton *btn_calDis;
    QPushButton *btn_data1;
    QPushButton *btn_data2;
    QPushButton *btn_calGrad_2D;
    QPushButton *btn_calDis_batch;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *DataProcessClass)
    {
        if (DataProcessClass->objectName().isEmpty())
            DataProcessClass->setObjectName(QStringLiteral("DataProcessClass"));
        DataProcessClass->resize(580, 224);
        centralWidget = new QWidget(DataProcessClass);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        label = new QLabel(centralWidget);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(20, 30, 71, 16));
        btn_calGrad = new QPushButton(centralWidget);
        btn_calGrad->setObjectName(QStringLiteral("btn_calGrad"));
        btn_calGrad->setGeometry(QRect(20, 150, 75, 23));
        le_root = new QLineEdit(centralWidget);
        le_root->setObjectName(QStringLiteral("le_root"));
        le_root->setGeometry(QRect(90, 30, 271, 20));
        le_size = new QLineEdit(centralWidget);
        le_size->setObjectName(QStringLiteral("le_size"));
        le_size->setGeometry(QRect(90, 110, 113, 20));
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
        label_3 = new QLabel(centralWidget);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(20, 110, 61, 16));
        btn_calDis = new QPushButton(centralWidget);
        btn_calDis->setObjectName(QStringLiteral("btn_calDis"));
        btn_calDis->setGeometry(QRect(110, 150, 75, 23));
        btn_data1 = new QPushButton(centralWidget);
        btn_data1->setObjectName(QStringLiteral("btn_data1"));
        btn_data1->setGeometry(QRect(230, 150, 75, 23));
        btn_data2 = new QPushButton(centralWidget);
        btn_data2->setObjectName(QStringLiteral("btn_data2"));
        btn_data2->setGeometry(QRect(310, 150, 75, 23));
        btn_calGrad_2D = new QPushButton(centralWidget);
        btn_calGrad_2D->setObjectName(QStringLiteral("btn_calGrad_2D"));
        btn_calGrad_2D->setGeometry(QRect(390, 150, 75, 23));
        btn_calDis_batch = new QPushButton(centralWidget);
        btn_calDis_batch->setObjectName(QStringLiteral("btn_calDis_batch"));
        btn_calDis_batch->setGeometry(QRect(470, 150, 75, 23));
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
        btn_calGrad->setText(QApplication::translate("DataProcessClass", "calGrad", Q_NULLPTR));
        btn_res->setText(QApplication::translate("DataProcessClass", "....", Q_NULLPTR));
        label_2->setText(QApplication::translate("DataProcessClass", "\347\273\223\346\236\234\344\277\235\345\255\230\345\210\260\357\274\232", Q_NULLPTR));
        btn_root->setText(QApplication::translate("DataProcessClass", "...", Q_NULLPTR));
        label_3->setText(QApplication::translate("DataProcessClass", "\345\210\206\347\273\204\345\274\240\346\225\260\357\274\232", Q_NULLPTR));
        btn_calDis->setText(QApplication::translate("DataProcessClass", "calDis", Q_NULLPTR));
        btn_data1->setText(QApplication::translate("DataProcessClass", "data1", Q_NULLPTR));
        btn_data2->setText(QApplication::translate("DataProcessClass", "data2", Q_NULLPTR));
        btn_calGrad_2D->setText(QApplication::translate("DataProcessClass", "2DGrad", Q_NULLPTR));
        btn_calDis_batch->setText(QApplication::translate("DataProcessClass", "batchDis", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class DataProcessClass: public Ui_DataProcessClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DATAPROCESS_H
