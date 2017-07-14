/********************************************************************************
** Form generated from reading UI file 'comparedialog.ui'
**
** Created by: Qt User Interface Compiler version 5.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_COMPAREDIALOG_H
#define UI_COMPAREDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_compareDialog
{
public:
    QDialogButtonBox *buttonBox;
    QLabel *label;
    QLabel *label_img1;
    QLabel *label_7;
    QLabel *label_8;
    QLabel *label_img2;
    QLabel *label_imgdiff;
    QLabel *label_10;
    QFrame *line;
    QFrame *line_2;
    QLabel *label_2;
    QLineEdit *t_img1;
    QPushButton *btn_openimg2;
    QPushButton *btn_openimg1;
    QLabel *label_3;
    QLineEdit *t_img2;
    QPushButton *btn_caldiff;
    QPushButton *btn_savediff;
    QPushButton *btn_saveall;
    QLineEdit *t_res;
    QPushButton *btn_res;
    QLabel *label_4;

    void setupUi(QDialog *compareDialog)
    {
        if (compareDialog->objectName().isEmpty())
            compareDialog->setObjectName(QStringLiteral("compareDialog"));
        compareDialog->resize(598, 452);
        buttonBox = new QDialogButtonBox(compareDialog);
        buttonBox->setObjectName(QStringLiteral("buttonBox"));
        buttonBox->setGeometry(QRect(30, 400, 341, 32));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);
        label = new QLabel(compareDialog);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(10, 10, 251, 21));
        label_img1 = new QLabel(compareDialog);
        label_img1->setObjectName(QStringLiteral("label_img1"));
        label_img1->setGeometry(QRect(20, 190, 151, 141));
        label_7 = new QLabel(compareDialog);
        label_7->setObjectName(QStringLiteral("label_7"));
        label_7->setGeometry(QRect(20, 160, 54, 12));
        label_8 = new QLabel(compareDialog);
        label_8->setObjectName(QStringLiteral("label_8"));
        label_8->setGeometry(QRect(220, 160, 54, 12));
        label_img2 = new QLabel(compareDialog);
        label_img2->setObjectName(QStringLiteral("label_img2"));
        label_img2->setGeometry(QRect(220, 190, 151, 141));
        label_imgdiff = new QLabel(compareDialog);
        label_imgdiff->setObjectName(QStringLiteral("label_imgdiff"));
        label_imgdiff->setGeometry(QRect(420, 190, 151, 141));
        label_10 = new QLabel(compareDialog);
        label_10->setObjectName(QStringLiteral("label_10"));
        label_10->setGeometry(QRect(420, 160, 54, 12));
        line = new QFrame(compareDialog);
        line->setObjectName(QStringLiteral("line"));
        line->setGeometry(QRect(0, 150, 601, 16));
        line->setFrameShape(QFrame::HLine);
        line->setFrameShadow(QFrame::Sunken);
        line_2 = new QFrame(compareDialog);
        line_2->setObjectName(QStringLiteral("line_2"));
        line_2->setGeometry(QRect(0, 370, 591, 16));
        line_2->setFrameShape(QFrame::HLine);
        line_2->setFrameShadow(QFrame::Sunken);
        label_2 = new QLabel(compareDialog);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(10, 80, 71, 16));
        t_img1 = new QLineEdit(compareDialog);
        t_img1->setObjectName(QStringLiteral("t_img1"));
        t_img1->setGeometry(QRect(60, 40, 351, 20));
        btn_openimg2 = new QPushButton(compareDialog);
        btn_openimg2->setObjectName(QStringLiteral("btn_openimg2"));
        btn_openimg2->setGeometry(QRect(410, 80, 31, 20));
        btn_openimg1 = new QPushButton(compareDialog);
        btn_openimg1->setObjectName(QStringLiteral("btn_openimg1"));
        btn_openimg1->setGeometry(QRect(410, 40, 31, 20));
        label_3 = new QLabel(compareDialog);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(10, 40, 71, 16));
        t_img2 = new QLineEdit(compareDialog);
        t_img2->setObjectName(QStringLiteral("t_img2"));
        t_img2->setGeometry(QRect(60, 80, 351, 20));
        btn_caldiff = new QPushButton(compareDialog);
        btn_caldiff->setObjectName(QStringLiteral("btn_caldiff"));
        btn_caldiff->setGeometry(QRect(10, 350, 75, 23));
        btn_savediff = new QPushButton(compareDialog);
        btn_savediff->setObjectName(QStringLiteral("btn_savediff"));
        btn_savediff->setGeometry(QRect(140, 350, 75, 23));
        btn_saveall = new QPushButton(compareDialog);
        btn_saveall->setObjectName(QStringLiteral("btn_saveall"));
        btn_saveall->setGeometry(QRect(280, 350, 75, 23));
        t_res = new QLineEdit(compareDialog);
        t_res->setObjectName(QStringLiteral("t_res"));
        t_res->setGeometry(QRect(80, 120, 331, 20));
        btn_res = new QPushButton(compareDialog);
        btn_res->setObjectName(QStringLiteral("btn_res"));
        btn_res->setGeometry(QRect(410, 120, 31, 20));
        label_4 = new QLabel(compareDialog);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(10, 120, 71, 16));

        retranslateUi(compareDialog);
        QObject::connect(buttonBox, SIGNAL(accepted()), compareDialog, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), compareDialog, SLOT(reject()));

        QMetaObject::connectSlotsByName(compareDialog);
    } // setupUi

    void retranslateUi(QDialog *compareDialog)
    {
        compareDialog->setWindowTitle(QApplication::translate("compareDialog", "Dialog", Q_NULLPTR));
        label->setText(QApplication::translate("compareDialog", "\346\257\224\350\276\203\344\270\244\345\271\205\345\233\276\347\232\204\345\267\256\345\274\202", Q_NULLPTR));
        label_img1->setText(QApplication::translate("compareDialog", "TextLabel", Q_NULLPTR));
        label_7->setText(QApplication::translate("compareDialog", "\345\233\2761\357\274\232", Q_NULLPTR));
        label_8->setText(QApplication::translate("compareDialog", "\345\233\2762\357\274\232", Q_NULLPTR));
        label_img2->setText(QApplication::translate("compareDialog", "TextLabel", Q_NULLPTR));
        label_imgdiff->setText(QApplication::translate("compareDialog", "TextLabel", Q_NULLPTR));
        label_10->setText(QApplication::translate("compareDialog", "\345\267\256\345\274\202\345\233\276\357\274\232", Q_NULLPTR));
        label_2->setText(QApplication::translate("compareDialog", "\346\211\223\345\274\200\345\233\2762", Q_NULLPTR));
        btn_openimg2->setText(QApplication::translate("compareDialog", "....", Q_NULLPTR));
        btn_openimg1->setText(QApplication::translate("compareDialog", "...", Q_NULLPTR));
        label_3->setText(QApplication::translate("compareDialog", "\346\211\223\345\274\200\345\233\2761", Q_NULLPTR));
        btn_caldiff->setText(QApplication::translate("compareDialog", "cal diff", Q_NULLPTR));
        btn_savediff->setText(QApplication::translate("compareDialog", "save diff", Q_NULLPTR));
        btn_saveall->setText(QApplication::translate("compareDialog", "save all", Q_NULLPTR));
        btn_res->setText(QApplication::translate("compareDialog", ".....", Q_NULLPTR));
        label_4->setText(QApplication::translate("compareDialog", "\347\273\223\346\236\234\344\277\235\345\255\230\345\210\260\357\274\232", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class compareDialog: public Ui_compareDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_COMPAREDIALOG_H
