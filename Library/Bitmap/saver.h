#ifndef IMAGEEDITOR_SAVER_H
#define IMAGEEDITOR_SAVER_H


#include "image.h"

namespace Bitmap {

    class Saver {
    public:
        static void save(Image *image, const char *path);
    };

} // Bitmap


#endif //IMAGEEDITOR_SAVER_H
