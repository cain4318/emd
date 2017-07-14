/********************************************************************************
** Form generated from reading UI file 'emd2dtester.ui'
**
** Created by: Qt User Interface Compiler version 5.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_EMD2DTESTER_H
#define UI_EMD2DTESTER_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QFrame>
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

class Ui_emd2DTesterClass
{
public:
    QWidget *centralWidget;
    QFrame *line;
    QLineEdit *t_root;
    QPushButton *btn_res;
    QLineEdit *t_res;
    QPushButton *btn_root;
    QLabel *label_2;
    QLabel *label;
    QFrame *line_2;
    QSpinBox *sb_index;
    QLabel *label_3;
    QLabel *label_4;
    QPushButton *btn_calpair;
    QLabel *label_imgleft;
    QLabel *label_imgright;
    QLabel *label_7;
    QLabel *label_8;
    QLabel *label_imggrad;
    QLabel *label_10;
    QLabel *label_11;
    QLabel *label_12;
    QPushButton *btn_savepair;
    QLabel *label_avgemd;
    QPushButton *btn_calsaveall;
    QLabel *label_14;
    QFrame *line_3;
    QLabel *label_5;
    QSpinBox *sb_radius;
    QLabel *label_6;
    QTextEdit *t_lineemd;
    QTextEdit *t_weights;
    QPushButton *btn_savegrad;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *emd2DTesterClass)
    {
        if (emd2DTesterClass->objectName().isEmpty())
            emd2DTesterClass->setObjectName(QStringLiteral("emd2DTesterClass"));
        emd2DTesterClass->resize(426, 656);
        centralWidget = new QWidget(emd2DTesterClass);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        line = new QFrame(centralWidget);
        line->setObjectName(QStringLiteral("line"));
        line->setGeometry(QRect(0, 80, 421, 21));
        line->setFrameShape(QFrame::HLine);
        line->setFrameShadow(QFrame::Sunken);
        t_root = new QLineEdit(centralWidget);
        t_root->setObjectName(QStringLiteral("t_root"));
        t_root->setGeometry(QRect(80, 10, 271, 20));
        btn_res = new QPushButton(centralWidget);
        btn_res->setObjectName(QStringLiteral("btn_res"));
        btn_res->setGeometry(QRect(350, 50, 31, 20));
        t_res = new QLineEdit(centralWidget);
        t_res->setObjectName(QStringLiteral("t_res"));
        t_res->setGeometry(QRect(80, 50, 271, 20));
        btn_root = new QPushButton(centralWidget);
        btn_root->setObjectName(QStringLiteral("btn_root"));
        btn_root->setGeometry(QRect(350, 10, 31, 20));
        label_2 = new QLabel(centralWidget);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(10, 50, 71, 16));
        label = new QLabel(centralWidget);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(10, 10, 71, 16));
        line_2 = new QFrame(centralWidget);
        line_2->setObjectName(QStringLiteral("line_2"));
        line_2->setGeometry(QRect(0, 550, 421, 21));
        line_2->setFrameShape(QFrame::HLine);
        line_2->setFrameShadow(QFrame::Sunken);
        sb_index = new QSpinBox(centralWidget);
        sb_index->setObjectName(QStringLiteral("sb_index"));
        sb_index->setGeometry(QRect(30, 150, 41, 21));
        sb_index->setMinimum(1);
        label_3 = new QLabel(centralWidget);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(10, 150, 21, 16));
        label_4 = new QLabel(centralWidget);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(80, 150, 101, 16));
        btn_calpair = new QPushButton(centralWidget);
        btn_calpair->setObjectName(QStringLiteral("btn_calpair"));
        btn_calpair->setGeometry(QRect(190, 150, 91, 20));
        label_imgleft = new QLabel(centralWidget);
        label_imgleft->setObjectName(QStringLiteral("label_imgleft"));
        label_imgleft->setGeometry(QRect(20, 210, 151, 141));
        label_imgright = new QLabel(centralWidget);
        label_imgright->setObjectName(QStringLiteral("label_imgright"));
        label_imgright->setGeometry(QRect(220, 210, 151, 141));
        label_7 = new QLabel(centralWidget);
        label_7->setObjectName(QStringLiteral("label_7"));
        label_7->setGeometry(QRect(20, 180, 54, 12));
        label_8 = new QLabel(centralWidget);
        label_8->setObjectName(QStringLiteral("label_8"));
        label_8->setGeometry(QRect(220, 180, 54, 12));
        label_imggrad = new QLabel(centralWidget);
        label_imggrad->setObjectName(QStringLiteral("label_imggrad"));
        label_imggrad->setGeometry(QRect(20, 390, 151, 141));
        label_10 = new QLabel(centralWidget);
        label_10->setObjectName(QStringLiteral("label_10"));
        label_10->setGeometry(QRect(20, 360, 54, 12));
        label_11 = new QLabel(centralWidget);
        label_11->setObjectName(QStringLiteral("label_11"));
        label_11->setGeometry(QRect(220, 350, 71, 16));
        label_12 = new QLabel(centralWidget);
        label_12->setObjectName(QStringLiteral("label_12"));
        label_12->setGeometry(QRect(220, 490, 71, 16));
        btn_savepair = new QPushButton(centralWidget);
        btn_savepair->setObjectName(QStringLiteral("btn_savepair"));
        btn_savepair->setGeometry(QRect(220, 540, 75, 20));
        label_avgemd = new QLabel(centralWidget);
        label_avgemd->setObjectName(QStringLiteral("label_avgemd"));
        label_avgemd->setGeometry(QRect(280, 490, 71, 16));
        btn_calsaveall = new QPushButton(centralWidget);
        btn_calsaveall->setObjectName(QStringLiteral("btn_calsaveall"));
        btn_calsaveall->setGeometry(QRect(150, 570, 131, 20));
        label_14 = new QLabel(centralWidget);
        label_14->setObjectName(QStringLiteral("label_14"));
        label_14->setGeometry(QRect(10, 570, 131, 16));
        line_3 = new QFrame(centralWidget);
        line_3->setObjectName(QStringLiteral("line_3"));
        line_3->setGeometry(QRect(0, 130, 421, 21));
        line_3->setFrameShape(QFrame::HLine);
        line_3->setFrameShadow(QFrame::Sunken);
        label_5 = new QLabel(centralWidget);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setGeometry(QRect(10, 100, 51, 16));
        sb_radius = new QSpinBox(centralWidget);
        sb_radius->setObjectName(QStringLiteral("sb_radius"));
        sb_radius->setGeometry(QRect(60, 100, 41, 21));
        sb_radius->setMinimum(0);
        label_6 = new QLabel(centralWidget);
        label_6->setObjectName(QStringLiteral("label_6"));
        label_6->setGeometry(QRect(130, 100, 31, 16));
        t_lineemd = new QTextEdit(centralWidget);
        t_lineemd->setObjectName(QStringLiteral("t_lineemd"));
        t_lineemd->setGeometry(QRect(220, 370, 181, 111));
        t_weights = new QTextEdit(centralWidget);
        t_weights->setObjectName(QStringLiteral("t_weights"));
        t_weights->setGeometry(QRect(160, 100, 251, 21));
        btn_savegrad = new QPushButton(centralWidget);
        btn_savegrad->setObjectName(QStringLiteral("btn_savegrad"));
        btn_savegrad->setGeometry(QRect(220, 510, 75, 20));
        emd2DTesterClass->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(emd2DTesterClass);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 426, 23));
        emd2DTesterClass->setMenuBar(menuBar);
        mainToolBar = new QToolBar(emd2DTesterClass);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        emd2DTesterClass->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(emd2DTesterClass);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        emd2DTesterClass->setStatusBar(statusBar);

        retranslateUi(emd2DTesterClass);

        QMetaObject::connectSlotsByName(emd2DTesterClass);
    } // setupUi

    void retranslateUi(QMainWindow *emd2DTesterClass)
    {
        emd2DTesterClass->setWindowTitle(QApplication::translate("emd2DTesterClass", "emd2DTester", Q_NULLPTR));
        btn_res->setText(QApplication::translate("emd2DTesterClass", "....", Q_NULLPTR));
        btn_root->setText(QApplication::translate("emd2DTesterClass", "...", Q_NULLPTR));
        label_2->setText(QApplication::translate("emd2DTesterClass", "\347\273\223\346\236\234\344\277\235\345\255\230\345\210\260\357\274\232", Q_NULLPTR));
        label->setText(QApplication::translate("emd2DTesterClass", "\351\200\211\346\213\251\346\240\271\347\233\256\345\275\225\357\274\232", Q_NULLPTR));
        label_3->setText(QApplication::translate("emd2DTesterClass", "\347\254\254", Q_NULLPTR));
        label_4->setText(QApplication::translate("emd2DTesterClass", "\345\257\271\345\233\276\345\203\217emd\347\233\270\345\205\263\347\273\223\346\236\234", Q_NULLPTR));
        btn_calpair->setText(QApplication::translate("emd2DTesterClass", "calculate pair", Q_NULLPTR));
        label_imgleft->setText(QApplication::translate("emd2DTesterClass", "TextLabel", Q_NULLPTR));
        label_imgright->setText(QApplication::translate("emd2DTesterClass", "TextLabel", Q_NULLPTR));
        label_7->setText(QApplication::translate("emd2DTesterClass", "\345\267\246\345\233\276\357\274\232", Q_NULLPTR));
        label_8->setText(QApplication::translate("emd2DTesterClass", "\345\217\263\345\233\276\357\274\232", Q_NULLPTR));
        label_imggrad->setText(QApplication::translate("emd2DTesterClass", "TextLabel", Q_NULLPTR));
        label_10->setText(QApplication::translate("emd2DTesterClass", "\346\242\257\345\272\246\345\233\276\357\274\232", Q_NULLPTR));
        label_11->setText(QApplication::translate("emd2DTesterClass", "\346\257\217\350\241\214\347\232\204emd\357\274\232", Q_NULLPTR));
        label_12->setText(QApplication::translate("emd2DTesterClass", "\345\271\263\345\235\207emd\357\274\232", Q_NULLPTR));
        btn_savepair->setText(QApplication::translate("emd2DTesterClass", "save result", Q_NULLPTR));
        label_avgemd->setText(QApplication::translate("emd2DTesterClass", "0", Q_NULLPTR));
        btn_calsaveall->setText(QApplication::translate("emd2DTesterClass", "cal and save all", Q_NULLPTR));
        label_14->setText(QApplication::translate("emd2DTesterClass", "\346\211\200\346\234\211\345\233\276\345\203\217\345\257\271emd\347\233\270\345\205\263\347\273\223\346\236\234", Q_NULLPTR));
        label_5->setText(QApplication::translate("emd2DTesterClass", "\351\202\273\345\237\237\345\215\212\345\276\204", Q_NULLPTR));
        label_6->setText(QApplication::translate("emd2DTesterClass", "\346\235\203\351\207\215\357\274\232", Q_NULLPTR));
        btn_savegrad->setText(QApplication::translate("emd2DTesterClass", "save grad", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class emd2DTesterClass: public Ui_emd2DTesterClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_EMD2DTESTER_H
