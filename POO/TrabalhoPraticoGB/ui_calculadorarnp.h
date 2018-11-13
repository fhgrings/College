/********************************************************************************
** Form generated from reading UI file 'calculadorarnp.ui'
**
** Created by: Qt User Interface Compiler version 5.9.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CALCULADORARNP_H
#define UI_CALCULADORARNP_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_CalculadoraRNP
{
public:
    QWidget *centralWidget;
    QTextEdit *ExibirValor;
    QLineEdit *lineEdit;
    QPushButton *Clear;
    QPushButton *N1;
    QPushButton *N2;
    QPushButton *Soma;
    QPushButton *N3;
    QPushButton *N5;
    QPushButton *Subtracao;
    QPushButton *N4;
    QPushButton *N6;
    QPushButton *N8;
    QPushButton *Multiplicacao;
    QPushButton *N7;
    QPushButton *N9;
    QPushButton *Divisao;
    QPushButton *SetaDown;
    QPushButton *N0;
    QPushButton *Rol;
    QPushButton *Enter;
    QPushButton *Del;
    QPushButton *SetaUp;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *CalculadoraRNP)
    {
        if (CalculadoraRNP->objectName().isEmpty())
            CalculadoraRNP->setObjectName(QStringLiteral("CalculadoraRNP"));
        CalculadoraRNP->resize(210, 380);
        centralWidget = new QWidget(CalculadoraRNP);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        ExibirValor = new QTextEdit(centralWidget);
        ExibirValor->setObjectName(QStringLiteral("ExibirValor"));
        ExibirValor->setGeometry(QRect(10, 10, 191, 81));
        lineEdit = new QLineEdit(centralWidget);
        lineEdit->setObjectName(QStringLiteral("lineEdit"));
        lineEdit->setGeometry(QRect(10, 100, 141, 21));
        Clear = new QPushButton(centralWidget);
        Clear->setObjectName(QStringLiteral("Clear"));
        Clear->setGeometry(QRect(160, 100, 41, 23));
        N1 = new QPushButton(centralWidget);
        N1->setObjectName(QStringLiteral("N1"));
        N1->setGeometry(QRect(10, 130, 41, 31));
        N2 = new QPushButton(centralWidget);
        N2->setObjectName(QStringLiteral("N2"));
        N2->setGeometry(QRect(60, 130, 41, 31));
        Soma = new QPushButton(centralWidget);
        Soma->setObjectName(QStringLiteral("Soma"));
        Soma->setGeometry(QRect(160, 130, 41, 31));
        N3 = new QPushButton(centralWidget);
        N3->setObjectName(QStringLiteral("N3"));
        N3->setGeometry(QRect(110, 130, 41, 31));
        N5 = new QPushButton(centralWidget);
        N5->setObjectName(QStringLiteral("N5"));
        N5->setGeometry(QRect(60, 170, 41, 31));
        Subtracao = new QPushButton(centralWidget);
        Subtracao->setObjectName(QStringLiteral("Subtracao"));
        Subtracao->setGeometry(QRect(160, 170, 41, 31));
        N4 = new QPushButton(centralWidget);
        N4->setObjectName(QStringLiteral("N4"));
        N4->setGeometry(QRect(10, 170, 41, 31));
        N6 = new QPushButton(centralWidget);
        N6->setObjectName(QStringLiteral("N6"));
        N6->setGeometry(QRect(110, 170, 41, 31));
        N8 = new QPushButton(centralWidget);
        N8->setObjectName(QStringLiteral("N8"));
        N8->setGeometry(QRect(60, 210, 41, 31));
        Multiplicacao = new QPushButton(centralWidget);
        Multiplicacao->setObjectName(QStringLiteral("Multiplicacao"));
        Multiplicacao->setGeometry(QRect(160, 210, 41, 31));
        N7 = new QPushButton(centralWidget);
        N7->setObjectName(QStringLiteral("N7"));
        N7->setGeometry(QRect(10, 210, 41, 31));
        N9 = new QPushButton(centralWidget);
        N9->setObjectName(QStringLiteral("N9"));
        N9->setGeometry(QRect(110, 210, 41, 31));
        Divisao = new QPushButton(centralWidget);
        Divisao->setObjectName(QStringLiteral("Divisao"));
        Divisao->setGeometry(QRect(160, 250, 41, 31));
        SetaDown = new QPushButton(centralWidget);
        SetaDown->setObjectName(QStringLiteral("SetaDown"));
        SetaDown->setGeometry(QRect(110, 250, 41, 31));
        N0 = new QPushButton(centralWidget);
        N0->setObjectName(QStringLiteral("N0"));
        N0->setGeometry(QRect(60, 250, 41, 31));
        Rol = new QPushButton(centralWidget);
        Rol->setObjectName(QStringLiteral("Rol"));
        Rol->setGeometry(QRect(60, 290, 41, 31));
        Enter = new QPushButton(centralWidget);
        Enter->setObjectName(QStringLiteral("Enter"));
        Enter->setGeometry(QRect(110, 290, 91, 31));
        Del = new QPushButton(centralWidget);
        Del->setObjectName(QStringLiteral("Del"));
        Del->setGeometry(QRect(10, 290, 41, 31));
        SetaUp = new QPushButton(centralWidget);
        SetaUp->setObjectName(QStringLiteral("SetaUp"));
        SetaUp->setGeometry(QRect(10, 250, 41, 31));
        CalculadoraRNP->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(CalculadoraRNP);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 210, 17));
        CalculadoraRNP->setMenuBar(menuBar);
        mainToolBar = new QToolBar(CalculadoraRNP);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        CalculadoraRNP->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(CalculadoraRNP);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        CalculadoraRNP->setStatusBar(statusBar);

        retranslateUi(CalculadoraRNP);

        QMetaObject::connectSlotsByName(CalculadoraRNP);
    } // setupUi

    void retranslateUi(QMainWindow *CalculadoraRNP)
    {
        CalculadoraRNP->setWindowTitle(QApplication::translate("CalculadoraRNP", "CalculadoraRNP", Q_NULLPTR));
        Clear->setText(QApplication::translate("CalculadoraRNP", "Clear", Q_NULLPTR));
        N1->setText(QApplication::translate("CalculadoraRNP", "1", Q_NULLPTR));
        N2->setText(QApplication::translate("CalculadoraRNP", "2", Q_NULLPTR));
        Soma->setText(QApplication::translate("CalculadoraRNP", "+", Q_NULLPTR));
        N3->setText(QApplication::translate("CalculadoraRNP", "3", Q_NULLPTR));
        N5->setText(QApplication::translate("CalculadoraRNP", "5", Q_NULLPTR));
        Subtracao->setText(QApplication::translate("CalculadoraRNP", "-", Q_NULLPTR));
        N4->setText(QApplication::translate("CalculadoraRNP", "4", Q_NULLPTR));
        N6->setText(QApplication::translate("CalculadoraRNP", "6", Q_NULLPTR));
        N8->setText(QApplication::translate("CalculadoraRNP", "8", Q_NULLPTR));
        Multiplicacao->setText(QApplication::translate("CalculadoraRNP", "x", Q_NULLPTR));
        N7->setText(QApplication::translate("CalculadoraRNP", "7", Q_NULLPTR));
        N9->setText(QApplication::translate("CalculadoraRNP", "9", Q_NULLPTR));
        Divisao->setText(QApplication::translate("CalculadoraRNP", "\303\267", Q_NULLPTR));
        SetaDown->setText(QApplication::translate("CalculadoraRNP", "\342\206\223", Q_NULLPTR));
        N0->setText(QApplication::translate("CalculadoraRNP", "0", Q_NULLPTR));
        Rol->setText(QApplication::translate("CalculadoraRNP", "Rol", Q_NULLPTR));
        Enter->setText(QApplication::translate("CalculadoraRNP", "Enter", Q_NULLPTR));
        Del->setText(QApplication::translate("CalculadoraRNP", "Del", Q_NULLPTR));
        SetaUp->setText(QApplication::translate("CalculadoraRNP", "\342\206\221", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class CalculadoraRNP: public Ui_CalculadoraRNP {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CALCULADORARNP_H
