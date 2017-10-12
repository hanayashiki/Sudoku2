/********************************************************************************
** Form generated from reading UI file 'SudokuGUI.ui'
**
** Created by: Qt User Interface Compiler version 5.6.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SUDOKUGUI_H
#define UI_SUDOKUGUI_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_SudokuGUIClass
{
public:
    QAction *action123;
    QAction *actionEASY;
    QAction *actionNew_Game_2;
    QAction *action_easy;
    QAction *action_normal;
    QAction *action_hard;
    QWidget *centralWidget;
    QMenuBar *menuBar;
    QMenu *menu_game;
    QMenu *menu_newGame;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *SudokuGUIClass)
    {
        if (SudokuGUIClass->objectName().isEmpty())
            SudokuGUIClass->setObjectName(QStringLiteral("SudokuGUIClass"));
        SudokuGUIClass->resize(467, 400);
        action123 = new QAction(SudokuGUIClass);
        action123->setObjectName(QStringLiteral("action123"));
        actionEASY = new QAction(SudokuGUIClass);
        actionEASY->setObjectName(QStringLiteral("actionEASY"));
        actionNew_Game_2 = new QAction(SudokuGUIClass);
        actionNew_Game_2->setObjectName(QStringLiteral("actionNew_Game_2"));
        action_easy = new QAction(SudokuGUIClass);
        action_easy->setObjectName(QStringLiteral("action_easy"));
        action_normal = new QAction(SudokuGUIClass);
        action_normal->setObjectName(QStringLiteral("action_normal"));
        action_hard = new QAction(SudokuGUIClass);
        action_hard->setObjectName(QStringLiteral("action_hard"));
        centralWidget = new QWidget(SudokuGUIClass);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        SudokuGUIClass->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(SudokuGUIClass);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 467, 26));
        menu_game = new QMenu(menuBar);
        menu_game->setObjectName(QStringLiteral("menu_game"));
        menu_newGame = new QMenu(menu_game);
        menu_newGame->setObjectName(QStringLiteral("menu_newGame"));
        SudokuGUIClass->setMenuBar(menuBar);
        statusBar = new QStatusBar(SudokuGUIClass);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        SudokuGUIClass->setStatusBar(statusBar);

        menuBar->addAction(menu_game->menuAction());
        menu_game->addAction(menu_newGame->menuAction());
        menu_newGame->addAction(action_easy);
        menu_newGame->addAction(action_normal);
        menu_newGame->addAction(action_hard);

        retranslateUi(SudokuGUIClass);

        QMetaObject::connectSlotsByName(SudokuGUIClass);
    } // setupUi

    void retranslateUi(QMainWindow *SudokuGUIClass)
    {
        SudokuGUIClass->setWindowTitle(QApplication::translate("SudokuGUIClass", "SudokuGUI", Q_NULLPTR));
        action123->setText(QApplication::translate("SudokuGUIClass", "555", Q_NULLPTR));
        actionEASY->setText(QApplication::translate("SudokuGUIClass", "EASY", Q_NULLPTR));
        actionNew_Game_2->setText(QApplication::translate("SudokuGUIClass", "New_Game", Q_NULLPTR));
        action_easy->setText(QApplication::translate("SudokuGUIClass", "Easy", Q_NULLPTR));
        action_easy->setShortcut(QApplication::translate("SudokuGUIClass", "Ctrl+0", Q_NULLPTR));
        action_normal->setText(QApplication::translate("SudokuGUIClass", "Normal", Q_NULLPTR));
        action_normal->setShortcut(QApplication::translate("SudokuGUIClass", "Ctrl+1", Q_NULLPTR));
        action_hard->setText(QApplication::translate("SudokuGUIClass", "Hard", Q_NULLPTR));
        action_hard->setShortcut(QApplication::translate("SudokuGUIClass", "Ctrl+2", Q_NULLPTR));
        menu_game->setTitle(QApplication::translate("SudokuGUIClass", "Game", Q_NULLPTR));
        menu_newGame->setTitle(QApplication::translate("SudokuGUIClass", "New Game", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class SudokuGUIClass: public Ui_SudokuGUIClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SUDOKUGUI_H
