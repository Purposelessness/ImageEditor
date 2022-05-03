#ifndef IMAGEEDITOR_LOADER_H
#define IMAGEEDITOR_LOADER_H


#include "image.h"

namespace Bitmap {

    class Loader {
    public:
        static Image load(const char *path);
    };

} // Image


#endif //IMAGEEDITOR_LOADER_H
