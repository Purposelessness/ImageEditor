#include "outliner.h"
#include "../../../../../Data/data.h"
#include "../../../../CommandInterface/commandinformation.h"
#include "../../../../UndoService/Command/additemcommand.h"
#include "../../../../../MainWidgets/EditorWindow/editorwindow.h"

Outliner::Outliner() : Tool(tr("Outliner")) {
    connect(this, SIGNAL(triggered(QString)), this, SLOT(use()));
}

void Outliner::use() {
    auto data = CommandOutlinerData{1, Qt::white, Qt::red};
    auto info = CommandInformation{.outlinerData = data, .type = CommandType::outline};
    new AddItemCommand(nullptr, info);

    auto window = WidgetData::getInstance().getEditorWindow();
    window->saveImage(true);
}
