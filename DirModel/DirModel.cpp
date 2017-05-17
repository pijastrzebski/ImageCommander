#include "DirModel.h"

DirModel::DirModel(QWidget *parent)
	: QMainWindow(parent),
	dirModel(new QFileSystemModel(this)),
	movie(new QMovie(EASTER_CLIP_PATH)),
	sPath(new QString("/")),
	clickedThumbName(new QString("")),
	pathWidgetList(new QWidgetList()),
	picWidgetList(new QWidgetList())
{
	ui.setupUi(this);

	qDebug() << "Running Thread: " << thread()->currentThreadId();

	firstThread = new QThread; // TODO: Deal with threads..
	secondThread = new QThread;

	/*QFuture<void> future;*/

	// Left window
	QString startPath = "/";

	//// First thread
	//dirModel->moveToThread(firstThread);

	//QObject::connect(dirModel, SIGNAL(error(QString)), this, SLOT(errorString(QString)));
	//QObject::connect(firstThread, SIGNAL(started()), dirModel, SLOT(process()));
	//QObject::connect(dirModel, SIGNAL(finished()), firstThread, SLOT(quit()));
	//QObject::connect(dirModel, SIGNAL(finished()), dirModel, SLOT(deleteLater()));
	//QObject::connect(firstThread, SIGNAL(finished()), firstThread, SLOT(deleteLater()));
	//firstThread->start();

	//qDebug() << "Running Thread: " << thread()->currentThreadId();

	// Dir Model
	dirModel->setRootPath(startPath);
	ui.treeView->setModel(dirModel);

	// properties
	// ex. change number and column names

	// view filter
	dirModel->setFilter(QDir::AllDirs | QDir::AllEntries | QDir::Hidden | QDir::Files);
	QStringList filters;
	filters << "*.jpg" << "*.png" << "*.gif" << "*.bmp" << "*.jpeg" << "*.pbm" << "*.pgm" << "*.ppm" << "*.xbm" << "*.xpm" << "*.ico";
	dirModel->setNameFilters(filters);
	dirModel->setNameFilterDisables(false);
	

	// Thumbnail Window
	ui.picListView->setViewMode(QListWidget::IconMode);
	ui.picListView->setIconSize(QSize(ICON_HEIGHT, ICON_WIDTH));
	ui.picListView->setResizeMode(QListWidget::Adjust);

	// Connects:
	// Quit Button
	QObject::connect(ui.pushButtonQuit, SIGNAL(clicked()), this, SLOT(close()));
	// Open Button
	QObject::connect(ui.pushButtonOpen, SIGNAL(clicked()), this, SLOT(openImage()));
	// Close Button
	QObject::connect(ui.pushButtonClose, SIGNAL(clicked()), this, SLOT(closeImage()));
	// Open File from tree view
	QObject::connect(ui.treeView, SIGNAL(clicked(QModelIndex)), this, SLOT(openImage()));
	// Setting path for open file in tree view
	QObject::connect(ui.treeView, &QTreeView::clicked, [=](QModelIndex index) {
		*sPath = dirModel->fileInfo(index).absoluteFilePath();
		emit clicked(index); });  // modern Qt SIG/SLOT: (src, dest, foo) + lambda: [=](parameters) { body };
	// Set and show path in thumbnail widget
	QObject::connect(ui.treeView, SIGNAL(clicked(QModelIndex)), this, SLOT(showPathOnWidgetList()));
	// Scan pic files
	QObject::connect(ui.treeView, SIGNAL(clicked(QModelIndex)), this, SLOT(scanPicFiles()));
	// Set file name in clicked list view
	QObject::connect(ui.picListView, &QListWidget::itemDoubleClicked, [=]() {

		*clickedThumbName = ui.picListView->currentItem()->text();
		qDebug() << ui.picListView->currentItem()->text();
		
		QImage image(*sPath + "/" + *clickedThumbName);
		ui.labelForImg->setScaledContents(true);
		ui.labelForImg->setPixmap(QPixmap::fromImage(image));
	});
	
	/*qDebug() << "Running Thread: " << thread()->currentThreadId();
	future.waitForFinished();
*/

    // List of SIGNALS:
	/*	clicked
	customContextMenuRequested
	destroyed
	objectNameChanged
	pressed
	released
	toggled
	windowIconChanged
	windowIconTextChanged
	windowTitleChanged*/

	// List of SLOTS:
	/**/
}

DirModel::~DirModel()
{
	delete sPath;
	delete dirModel;
	delete movie;
	delete pathWidgetList;
	delete clickedThumbName;
	//delete dirPicIter;
	
	if (firstThread->isFinished())
	{
		delete firstThread;
	}
	if (secondThread->isFinished())
	{
		delete secondThread;
	}
}

void DirModel::uniClicked(QModelIndex index) // del this if NN
{
	if (sPath != NULL)
	{
		*sPath = dirModel->fileInfo(index).absoluteFilePath();
		
		emit clicked(index);
	}
}

void DirModel::openImage()
{
	if (sPath != NULL)
	{
		QString openImageFile = *sPath;
		QImage image(openImageFile);
		
		ui.labelForImg->setScaledContents(true);
		ui.labelForImg->setPixmap(QPixmap::fromImage(image));
		ui.pushButtonClose->setText("Close Image");
	}
}

void DirModel::closeImage()
{
	//movie->moveToThread(QApplication::instance()->thread()); // move to main thread
	//qDebug() << "Running Thread: " << thread()->currentThreadId();
	
	ui.labelForImg->setMovie(movie);
	movie->start();
	ui.pushButtonClose->setText("Happy Easter Cowboy!");
}

void DirModel::openImageNewWindow()
{
	// build new class first
}

void DirModel::showPathOnWidgetList()
{
	if (sPath != NULL)
	{
		// clear path
		delete ui.pathListView->item(0);
		//set current path
		ui.pathListView->addItem(*sPath);
	}
}

void DirModel::scanPicFiles()
{
	if (sPath != NULL)
	{
		QString thumbName;
		// clear qlist
		ui.picListView->clear();
		// Scan Dir, only jpg and bmp for now
		//dirPicIter = new QDirIterator(*sPath, QStringList() << "*.jpg" << "*.bmp", QDir::Files/*, QDirIterator::Subdirectories*/);
		QDirIterator it(*sPath, QStringList() << "*.jpg" << "*.bmp", QDir::Files/*, QDirIterator::Subdirectories*/);
		while (it.hasNext())
		{
			thumbName = it.next();
			qDebug() << thumbName;
			ui.picListView->addItem(new QListWidgetItem(QIcon(thumbName), it.fileName()));
			// set auto size for thumbnails window
			//ui.picListView->setFixedWidth(ui.picListView->count() * 160);
		}
	}
}