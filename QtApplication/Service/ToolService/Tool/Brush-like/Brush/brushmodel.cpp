#include "brushmodel.h"

#include <QDebug>
#include "../../../../../logger.h"

void BrushModel::use() {
    qDebug(core()) << "Drawing with brush";
}
