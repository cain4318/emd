/********************************************************************************
** Form generated from reading UI file 'emdtester.ui'
**
** Created by: Qt User Interface Compiler version 5.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_EMDTESTER_H
#define UI_EMDTESTER_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_EMDtesterClass
{
public:
    QWidget *centralWidget;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QSpinBox *sb_nDim;
    QTextEdit *t_supplyData;
    QTextEdit *t_demandData;
    QPushButton *btn_showSdis;
    QPushButton *btn_showDdis;
    QLabel *t_sumS;
    QLabel *t_sumD;
    QPushButton *btn_calemd;
    QPushButton *btn_saveTest;
    QPushButton *btn_calGrad;
    QLabel *label_6;
    QLabel *lb_emdDis;
    QPushButton *btn_readSingleData;
    QPushButton *btn_readBatchData;
    QLineEdit *t_singleDataPath;
    QLabel *label_8;
    QLabel *label_9;
    QLineEdit *t_batchDataPath;
    QPushButton *btn_readInSD;
    QPushButton *btn_readInBD;
    QLabel *label_7;
    QLabel *lb_emdDis_ap;
    QPushButton *btn_calGrad_ap;
    QPushButton *btn_calemd_ap;
    QPushButton *btn_saveTest_ap;
    QPushButton *btn_randomData;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *EMDtesterClass)
    {
        if (EMDtesterClass->objectName().isEmpty())
            EMDtesterClass->setObjectName(QStringLiteral("EMDtesterClass"));
        EMDtesterClass->resize(421, 515);
        centralWidget = new QWidget(EMDtesterClass);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        label = new QLabel(centralWidget);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(10, 10, 81, 16));
        label_2 = new QLabel(centralWidget);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(10, 40, 81, 16));
        label_3 = new QLabel(centralWidget);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(10, 140, 81, 16));
        sb_nDim = new QSpinBox(centralWidget);
        sb_nDim->setObjectName(QStringLiteral("sb_nDim"));
        sb_nDim->setGeometry(QRect(101, 10, 51, 21));
        sb_nDim->setMinimum(1);
        t_supplyData = new QTextEdit(centralWidget);
        t_supplyData->setObjectName(QStringLiteral("t_supplyData"));
        t_supplyData->setGeometry(QRect(10, 60, 401, 51));
        t_demandData = new QTextEdit(centralWidget);
        t_demandData->setObjectName(QStringLiteral("t_demandData"));
        t_demandData->setGeometry(QRect(10, 160, 401, 51));
        btn_showSdis = new QPushButton(centralWidget);
        btn_showSdis->setObjectName(QStringLiteral("btn_showSdis"));
        btn_showSdis->setGeometry(QRect(100, 40, 141, 21));
        btn_showDdis = new QPushButton(centralWidget);
        btn_showDdis->setObjectName(QStringLiteral("btn_showDdis"));
        btn_showDdis->setGeometry(QRect(100, 140, 141, 23));
        t_sumS = new QLabel(centralWidget);
        t_sumS->setObjectName(QStringLiteral("t_sumS"));
        t_sumS->setGeometry(QRect(250, 40, 161, 16));
        t_sumD = new QLabel(centralWidget);
        t_sumD->setObjectName(QStringLiteral("t_sumD"));
        t_sumD->setGeometry(QRect(250, 140, 161, 20));
        btn_calemd = new QPushButton(centralWidget);
        btn_calemd->setObjectName(QStringLiteral("btn_calemd"));
        btn_calemd->setGeometry(QRect(10, 240, 75, 23));
        btn_saveTest = new QPushButton(centralWidget);
        btn_saveTest->setObjectName(QStringLiteral("btn_saveTest"));
        btn_saveTest->setGeometry(QRect(10, 330, 75, 23));
        btn_calGrad = new QPushButton(centralWidget);
        btn_calGrad->setObjectName(QStringLiteral("btn_calGrad"));
        btn_calGrad->setGeometry(QRect(10, 300, 75, 23));
        label_6 = new QLabel(centralWidget);
        label_6->setObjectName(QStringLiteral("label_6"));
        label_6->setGeometry(QRect(100, 240, 81, 21));
        lb_emdDis = new QLabel(centralWidget);
        lb_emdDis->setObjectName(QStringLiteral("lb_emdDis"));
        lb_emdDis->setGeometry(QRect(160, 240, 81, 21));
        btn_readSingleData = new QPushButton(centralWidget);
        btn_readSingleData->setObjectName(QStringLiteral("btn_readSingleData"));
        btn_readSingleData->setGeometry(QRect(300, 370, 21, 16));
        btn_readBatchData = new QPushButton(centralWidget);
        btn_readBatchData->setObjectName(QStringLiteral("btn_readBatchData"));
        btn_readBatchData->setGeometry(QRect(300, 410, 21, 16));
        t_singleDataPath = new QLineEdit(centralWidget);
        t_singleDataPath->setObjectName(QStringLiteral("t_singleDataPath"));
        t_singleDataPath->setGeometry(QRect(120, 370, 181, 16));
        label_8 = new QLabel(centralWidget);
        label_8->setObjectName(QStringLiteral("label_8"));
        label_8->setGeometry(QRect(10, 370, 111, 16));
        label_9 = new QLabel(centralWidget);
        label_9->setObjectName(QStringLiteral("label_9"));
        label_9->setGeometry(QRect(10, 410, 111, 16));
        t_batchDataPath = new QLineEdit(centralWidget);
        t_batchDataPath->setObjectName(QStringLiteral("t_batchDataPath"));
        t_batchDataPath->setGeometry(QRect(120, 410, 181, 16));
        btn_readInSD = new QPushButton(centralWidget);
        btn_readInSD->setObjectName(QStringLiteral("btn_readInSD"));
        btn_readInSD->setGeometry(QRect(350, 370, 51, 21));
        btn_readInBD = new QPushButton(centralWidget);
        btn_readInBD->setObjectName(QStringLiteral("btn_readInBD"));
        btn_readInBD->setGeometry(QRect(350, 410, 51, 23));
        label_7 = new QLabel(centralWidget);
        label_7->setObjectName(QStringLiteral("label_7"));
        label_7->setGeometry(QRect(100, 270, 81, 21));
        lb_emdDis_ap = new QLabel(centralWidget);
        lb_emdDis_ap->setObjectName(QStringLiteral("lb_emdDis_ap"));
        lb_emdDis_ap->setGeometry(QRect(180, 270, 81, 21));
        btn_calGrad_ap = new QPushButton(centralWidget);
        btn_calGrad_ap->setObjectName(QStringLiteral("btn_calGrad_ap"));
        btn_calGrad_ap->setGeometry(QRect(100, 300, 81, 23));
        btn_calemd_ap = new QPushButton(centralWidget);
        btn_calemd_ap->setObjectName(QStringLiteral("btn_calemd_ap"));
        btn_calemd_ap->setGeometry(QRect(10, 270, 75, 23));
        btn_saveTest_ap = new QPushButton(centralWidget);
        btn_saveTest_ap->setObjectName(QStringLiteral("btn_saveTest_ap"));
        btn_saveTest_ap->setGeometry(QRect(100, 330, 81, 23));
        btn_randomData = new QPushButton(centralWidget);
        btn_randomData->setObjectName(QStringLiteral("btn_randomData"));
        btn_randomData->setGeometry(QRect(330, 0, 75, 23));
        EMDtesterClass->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(EMDtesterClass);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 421, 23));
        EMDtesterClass->setMenuBar(menuBar);
        mainToolBar = new QToolBar(EMDtesterClass);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        EMDtesterClass->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(EMDtesterClass);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        EMDtesterClass->setStatusBar(statusBar);

        retranslateUi(EMDtesterClass);

        QMetaObject::connectSlotsByName(EMDtesterClass);
    } // setupUi

    void retranslateUi(QMainWindow *EMDtesterClass)
    {
        EMDtesterClass->setWindowTitle(QApplication::translate("EMDtesterClass", "EMDtester", Q_NULLPTR));
        label->setText(QApplication::translate("EMDtesterClass", "\345\234\237\345\240\206/\345\235\221\346\225\260\351\207\217\357\274\232", Q_NULLPTR));
        label_2->setText(QApplication::translate("EMDtesterClass", "\345\234\237\345\240\206\345\220\204\350\207\252\347\232\204\351\207\217\357\274\232", Q_NULLPTR));
        label_3->setText(QApplication::translate("EMDtesterClass", "\345\234\237\345\235\221\345\220\204\350\207\252\347\232\204\351\207\217\357\274\232", Q_NULLPTR));
        btn_showSdis->setText(QApplication::translate("EMDtesterClass", "show supply distribute", Q_NULLPTR));
        btn_showDdis->setText(QApplication::translate("EMDtesterClass", "show demand distribute", Q_NULLPTR));
        t_sumS->setText(QApplication::translate("EMDtesterClass", "()/()", Q_NULLPTR));
        t_sumD->setText(QApplication::translate("EMDtesterClass", "()/()", Q_NULLPTR));
        btn_calemd->setText(QApplication::translate("EMDtesterClass", "Cal EMD", Q_NULLPTR));
        btn_saveTest->setText(QApplication::translate("EMDtesterClass", "Save Test", Q_NULLPTR));
        btn_calGrad->setText(QApplication::translate("EMDtesterClass", "Cal Grad", Q_NULLPTR));
        label_6->setText(QApplication::translate("EMDtesterClass", "EMD\350\267\235\347\246\273\357\274\232", Q_NULLPTR));
        lb_emdDis->setText(QApplication::translate("EMDtesterClass", "0", Q_NULLPTR));
        btn_readSingleData->setText(QApplication::translate("EMDtesterClass", "..", Q_NULLPTR));
        btn_readBatchData->setText(QApplication::translate("EMDtesterClass", "...", Q_NULLPTR));
        label_8->setText(QApplication::translate("EMDtesterClass", "\345\215\225\344\270\252\345\256\236\351\252\214\346\225\260\346\215\256\346\226\207\344\273\266\357\274\232", Q_NULLPTR));
        label_9->setText(QApplication::translate("EMDtesterClass", "\346\211\271\345\256\236\351\252\214\346\225\260\346\215\256\346\226\207\344\273\266\345\244\271\357\274\232", Q_NULLPTR));
        btn_readInSD->setText(QApplication::translate("EMDtesterClass", "load", Q_NULLPTR));
        btn_readInBD->setText(QApplication::translate("EMDtesterClass", "batch", Q_NULLPTR));
        label_7->setText(QApplication::translate("EMDtesterClass", "\350\277\221\344\274\274EMD\350\267\235\347\246\273\357\274\232", Q_NULLPTR));
        lb_emdDis_ap->setText(QApplication::translate("EMDtesterClass", "0", Q_NULLPTR));
        btn_calGrad_ap->setText(QApplication::translate("EMDtesterClass", "Cal Grad ap", Q_NULLPTR));
        btn_calemd_ap->setText(QApplication::translate("EMDtesterClass", "Cal EMD ap", Q_NULLPTR));
        btn_saveTest_ap->setText(QApplication::translate("EMDtesterClass", "Save Test ap", Q_NULLPTR));
        btn_randomData->setText(QApplication::translate("EMDtesterClass", "rand Data", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class EMDtesterClass: public Ui_EMDtesterClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_EMDTESTER_H
