#include "brushmodel.h"

#include <QDebug>
#include "../../../../Logger/logger.h"

void BrushModel::use() {
    qDebug(core()) << "Drawing with brush";
}
