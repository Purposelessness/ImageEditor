#include "penmodel.h"

#include <QDebug>
#include "../../../../Logger/logger.h"

void PenModel::use() {
    qDebug(core()) << "Using the pen";
}
