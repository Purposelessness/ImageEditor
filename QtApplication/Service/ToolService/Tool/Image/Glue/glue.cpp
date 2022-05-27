#include "glue.h"
#include "../../../../CommandInterface/commandinformation.h"
#include "../../../../UndoService/Command/additemcommand.h"
#include "../../../../../Data/data.h"
#include "../../../../../MainWidgets/EditorWindow/editorwindow.h"

#include <QStandardPaths>
#include <QFileDialog>

Glue::Glue() : Tool(tr("Glue")) {
    connect(this, SIGNAL(triggered(QString)), this, SLOT(use()));
}

void Glue::use() {
    auto picturesLocation = QStandardPaths::standardLocations(QStandardPaths::PicturesLocation);
    auto fileName = QFileDialog::getOpenFileName(nullptr, QWidget::tr("Open"),
                                            picturesLocation.isEmpty() ? QDir::currentPath() : picturesLocation.last(),
                                            QWidget::tr("BMP (*.bmp);;JPEG (*.jpg *.jpeg);;PNG (*.png)"));
    if (fileName.isEmpty()) {
        qWarning() << "Invalid file path";
        return;
    }
    auto data = CommandGlueData{fileName.toUtf8().constData()};
    auto info = CommandInformation{.glueData = data, .type = CommandType::glue};
    new AddItemCommand(nullptr, info);

    auto window = WidgetData::getInstance().getEditorWindow();
    window->saveImage(true);
}
