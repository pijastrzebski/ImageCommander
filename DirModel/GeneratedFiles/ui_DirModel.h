/********************************************************************************
** Form generated from reading UI file 'DirModel.ui'
**
** Created by: Qt User Interface Compiler version 5.7.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DIRMODEL_H
#define UI_DIRMODEL_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QSplitter>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QTreeView>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_DirModelClass
{
public:
    QWidget *centralWidget;
    QVBoxLayout *verticalLayout;
    QSplitter *splitter;
    QTreeView *treeView;
    QListWidget *pathListView;
    QListWidget *picListView;
    QLabel *labelForImg;
    QHBoxLayout *horizontalLayout;
    QPushButton *pushButtonOpen;
    QPushButton *pushButtonClose;
    QSpacerItem *horizontalSpacer;
    QPushButton *pushButtonQuit;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *DirModelClass)
    {
        if (DirModelClass->objectName().isEmpty())
            DirModelClass->setObjectName(QStringLiteral("DirModelClass"));
        DirModelClass->setEnabled(true);
        DirModelClass->resize(1020, 606);
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(3);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(DirModelClass->sizePolicy().hasHeightForWidth());
        DirModelClass->setSizePolicy(sizePolicy);
        QFont font;
        font.setFamily(QStringLiteral("Consolas"));
        font.setBold(true);
        font.setItalic(false);
        font.setWeight(75);
        font.setKerning(true);
        font.setStyleStrategy(QFont::PreferAntialias);
        DirModelClass->setFont(font);
        DirModelClass->setWindowTitle(QStringLiteral("ImageCommander Ver1.0.0"));
        DirModelClass->setWindowOpacity(0.95);
        DirModelClass->setIconSize(QSize(50, 50));
        DirModelClass->setAnimated(true);
        DirModelClass->setDocumentMode(false);
        DirModelClass->setDockNestingEnabled(true);
        centralWidget = new QWidget(DirModelClass);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        verticalLayout = new QVBoxLayout(centralWidget);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        splitter = new QSplitter(centralWidget);
        splitter->setObjectName(QStringLiteral("splitter"));
        splitter->setOrientation(Qt::Horizontal);
        treeView = new QTreeView(splitter);
        treeView->setObjectName(QStringLiteral("treeView"));
        QFont font1;
        font1.setFamily(QStringLiteral("Consolas"));
        font1.setPointSize(9);
        font1.setBold(false);
        font1.setWeight(50);
        font1.setKerning(false);
        font1.setStyleStrategy(QFont::PreferAntialias);
        treeView->setFont(font1);
        treeView->setAutoFillBackground(false);
        treeView->setFrameShape(QFrame::StyledPanel);
        treeView->setFrameShadow(QFrame::Plain);
        treeView->setSizeAdjustPolicy(QAbstractScrollArea::AdjustIgnored);
        treeView->setSortingEnabled(true);
        treeView->setAnimated(true);
        treeView->setAllColumnsShowFocus(false);
        treeView->setWordWrap(true);
        treeView->setHeaderHidden(false);
        treeView->setExpandsOnDoubleClick(true);
        splitter->addWidget(treeView);
        treeView->header()->setVisible(true);
        pathListView = new QListWidget(splitter);
        pathListView->setObjectName(QStringLiteral("pathListView"));
        QFont font2;
        font2.setFamily(QStringLiteral("Consolas"));
        pathListView->setFont(font2);
        pathListView->setSizeAdjustPolicy(QAbstractScrollArea::AdjustToContents);
        splitter->addWidget(pathListView);
        picListView = new QListWidget(splitter);
        picListView->setObjectName(QStringLiteral("picListView"));
        picListView->setFont(font2);
        picListView->setSizeAdjustPolicy(QAbstractScrollArea::AdjustIgnored);
        splitter->addWidget(picListView);
        labelForImg = new QLabel(splitter);
        labelForImg->setObjectName(QStringLiteral("labelForImg"));
        labelForImg->setMinimumSize(QSize(300, 300));
        QFont font3;
        font3.setFamily(QStringLiteral("Consolas"));
        font3.setPointSize(30);
        font3.setBold(true);
        font3.setItalic(true);
        font3.setWeight(75);
        font3.setStyleStrategy(QFont::PreferAntialias);
        labelForImg->setFont(font3);
        labelForImg->setLayoutDirection(Qt::LeftToRight);
        labelForImg->setAutoFillBackground(false);
        labelForImg->setFrameShape(QFrame::WinPanel);
        labelForImg->setFrameShadow(QFrame::Plain);
        labelForImg->setPixmap(QPixmap(QString::fromUtf8("../../../../../Downloads/avid.jpg")));
        labelForImg->setScaledContents(true);
        labelForImg->setAlignment(Qt::AlignCenter);
        labelForImg->setMargin(1);
        labelForImg->setIndent(-1);
        labelForImg->setOpenExternalLinks(false);
        splitter->addWidget(labelForImg);

        verticalLayout->addWidget(splitter);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        pushButtonOpen = new QPushButton(centralWidget);
        pushButtonOpen->setObjectName(QStringLiteral("pushButtonOpen"));
        pushButtonOpen->setFont(font2);

        horizontalLayout->addWidget(pushButtonOpen);

        pushButtonClose = new QPushButton(centralWidget);
        pushButtonClose->setObjectName(QStringLiteral("pushButtonClose"));
        pushButtonClose->setFont(font2);

        horizontalLayout->addWidget(pushButtonClose);

        horizontalSpacer = new QSpacerItem(648, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        pushButtonQuit = new QPushButton(centralWidget);
        pushButtonQuit->setObjectName(QStringLiteral("pushButtonQuit"));
        pushButtonQuit->setFont(font2);

        horizontalLayout->addWidget(pushButtonQuit);


        verticalLayout->addLayout(horizontalLayout);

        DirModelClass->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(DirModelClass);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setEnabled(false);
        menuBar->setGeometry(QRect(0, 0, 1020, 24));
        DirModelClass->setMenuBar(menuBar);
        mainToolBar = new QToolBar(DirModelClass);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        DirModelClass->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(DirModelClass);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        DirModelClass->setStatusBar(statusBar);

        retranslateUi(DirModelClass);

        QMetaObject::connectSlotsByName(DirModelClass);
    } // setupUi

    void retranslateUi(QMainWindow *DirModelClass)
    {
#ifndef QT_NO_TOOLTIP
        DirModelClass->setToolTip(QString());
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_TOOLTIP
        labelForImg->setToolTip(QString());
#endif // QT_NO_TOOLTIP
        labelForImg->setText(QString());
        pushButtonOpen->setText(QApplication::translate("DirModelClass", "Open Image", Q_NULLPTR));
        pushButtonClose->setText(QApplication::translate("DirModelClass", "Close Image", Q_NULLPTR));
        pushButtonQuit->setText(QApplication::translate("DirModelClass", "Quit", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class DirModelClass: public Ui_DirModelClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DIRMODEL_H
