#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_DirModel.h"
#include <qdialog.h>
#include <QtCore>
#include <QtGui>
#include <qfilesystemmodel.h> // recommended, won't lack up your gui
#include <qthread.h> // add threads
#include <qsplitter.h> // for widgets? del if not needed
#include <QListView>
#include <qtreewidget.h>
#include <qlabel.h>
#include <qimage.h>
#include <QtConcurrent\qtconcurrentthreadengine.h>
#include <QtConcurrent\qtconcurrentrun.h>
#include <qlistwidget.h>
#include <qdiriterator.h>

// STATIC SETTINGS
#define EASTER_CLIP_PATH "C:/Users/ORAD_JUNIOR_05/Downloads/safe_image.gif"
#define ICON_HEIGHT 160
#define ICON_WIDTH 160

// NAMESPACE
namespace Ui {
	class DirModel;
}

// CLASS
class DirModel : public QMainWindow
{
	// our lovely Qt macro
	Q_OBJECT

public:
	DirModel(QWidget *parent = Q_NULLPTR);
	~DirModel();
	// shared path
	QString *sPath;
	QString *clickedThumbName;
	//QDirIterator *dirPicIter;
	// threads
	QThread *firstThread;
	QThread *secondThread;

private:
	Ui::DirModelClass ui;
	
	// TIP: make comments java doc like style ex.
	//! tree view
	QFileSystemModel *dirModel;
	/*! \brief label for showing image
	*/
	QMovie *movie;
	QWidgetList *pathWidgetList;
	QWidgetList *picWidgetList;
	
public slots:
	// for set path
	void uniClicked(QModelIndex index);
	void openImage();
	void closeImage();
	void openImageNewWindow();
	void showPathOnWidgetList();
	void scanPicFiles();

signals:
	void clicked(QModelIndex);
};
