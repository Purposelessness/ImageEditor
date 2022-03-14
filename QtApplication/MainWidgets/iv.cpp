#include <QMenuBar>
#include <QFileDialog>
#include <QImageReader>
#include <QMessageBox>
#include <QStandardPaths>
#include <QPainter>
#include <QColorSpace>
#include <QToolButton>
#include <QColor>
#include <QColorDialog>
#include "iv.h"

ImageViewer::ImageViewer(QWidget *parent) :
        QMainWindow(parent), ui(new Ui::ImageViewer), imageLabel(new QLabel), scrollArea(new QScrollArea) {
    ui->setupUi(this);

    auto toolButton = new QToolButton(this);
    toolButton->setGeometry(50, 50, 100, 50);
    toolButton->setText(tr("QToolButton"));
    toolButton->setPopupMode(QToolButton::MenuButtonPopup);
    auto someAction = new QAction();
    someAction->setText("SomeAction");
    auto someAction2 = new QAction();
    someAction2->setText("SomeAction");
    toolButton->addAction(someAction);
    toolButton->addAction(someAction2);


    auto color = QColorDialog::getColor(Qt::white, this);
    qDebug() << color;

    imageLabel->setBackgroundRole(QPalette::Base);
    imageLabel->setSizePolicy(QSizePolicy::Ignored, QSizePolicy::Ignored);
    imageLabel->setScaledContents(true);

    scrollArea->setBackgroundRole(QPalette::Dark);
    scrollArea->setWidget(imageLabel);
    scrollArea->setVisible(false);
    setCentralWidget(scrollArea);

    createMenus();
    createActions();
}

ImageViewer::~ImageViewer() {
    delete ui;
}

void ImageViewer::createMenus() {
    fileMenu = menuBar()->addMenu(tr("&File"));
}

void ImageViewer::createActions() {
    openAct = fileMenu->addAction(tr("&Open"), this, SLOT(open()), QKeySequence::Open);

    saveAsAct = fileMenu->addAction(tr("&Save As"), this, SLOT(saveAs()),
                                    QKeySequence(Qt::CTRL | Qt::SHIFT | Qt::Key_S));
    saveAsAct->setEnabled(false);
}

void ImageViewer::open() {
    const QStringList picturesLocation = QStandardPaths::standardLocations(QStandardPaths::PicturesLocation);
    QString fileName = QFileDialog::getOpenFileName(this, tr("Open"),
                                                    picturesLocation.isEmpty() ? QDir::currentPath() : picturesLocation.last(),
                                                    tr("All files (*.*);;JPEG (*.jpg *.jpeg);;PNG (*.png);;BMP (*.bmp)"));
    if (!fileName.isEmpty())
        loadFile(fileName);
}

void ImageViewer::saveAs() {
    qDebug("Save As");
}

bool ImageViewer::loadFile(const QString &fileName) {
    QImageReader reader(fileName);
    reader.setAutoTransform(true);
    const QImage newImage = reader.read();
    if (newImage.isNull()) {
        QMessageBox::information(this, QGuiApplication::applicationDisplayName(),
                                 tr("Cannot load %1: %2").arg(QDir::toNativeSeparators(fileName),
                                                              reader.errorString()));
        return false;
    }

    setImage(newImage);
    imageLabel->resize(newImage.size());

    return true;
}

void ImageViewer::setImage(const QImage &newImage) {
    image = newImage;
    auto pixmap = new QPixmap(QPixmap::fromImage(newImage));
    image = pixmap->toImage();
    if (image.colorSpace().isValid())
        image.convertToColorSpace(QColorSpace::SRgb);

    imageLabel->setPixmap(QPixmap::fromImage(image));
    scrollArea->setVisible(true);
    imageLabel->adjustSize();
}
