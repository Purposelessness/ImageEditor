#ifndef IMAGEEDITOR_IMAGE_H
#define IMAGEEDITOR_IMAGE_H


#include "../iimage.h"
#include "bitmapheader.h"

namespace Bitmap {

    class Image : public IImage {
    public:
        Image() = default;
        Image(const Image &other);
        explicit Image(const FileHeader &fileHeader, const InfoHeader &infoHeader, Rgb **pixelData);
        ~Image();

        [[nodiscard]] bool isEmpty() const override;

        void setHeight(int32_t height) override;
        void setWidth(int32_t width) override;
        void setCropRect(const Rect &cropRect = Rect());

        Rgb **getPixelData() override;
        [[nodiscard]] int32_t getHeight() const override;
        [[nodiscard]] int32_t getWidth() const override;
        [[nodiscard]] Rect getCropRect() const override;
        FileHeader *getFileHeader();
        InfoHeader *getInfoHeader();

    private:
        FileHeader fileHeader{};
        InfoHeader infoHeader{0};
        Rgb **pixelData = nullptr;
        Rect cropRect{};
    };

}


#endif //IMAGEEDITOR_IMAGE_H
