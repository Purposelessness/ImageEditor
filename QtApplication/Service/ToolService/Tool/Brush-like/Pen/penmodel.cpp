#include "penmodel.h"

#include <QDebug>
#include "../../../../../logger.h"

void PenModel::use() {
    qDebug(core()) << "Using the pen";
}
