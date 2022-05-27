#include "reflector.h"
#include "../../../../CommandInterface/commandinformation.h"
#include "../../../../UndoService/Command/additemcommand.h"
#include "../../../../../Data/data.h"
#include "../../../../../MainWidgets/EditorWindow/editorwindow.h"

Reflector::Reflector() : Marquee<MarqueeItem>(tr("Reflector")) {}

void Reflector::marqueePaintedEvent(const QPainterPath &path) {
    auto canvas = WidgetData::getInstance().getGraphicsView()->getPixmapItem();
    auto rect = canvas->mapFromScene(path).boundingRect().toRect();

    auto data = CommandReflectorData{rect};
    auto info = CommandInformation{.reflectorData = data, .type = CommandType::reflector};
    new AddItemCommand(nullptr, info);

    auto window = WidgetData::getInstance().getEditorWindow();
    window->saveImage(true);
}
