#ifndef IMAGEEDITOR_BITMAPHEADER_H
#define IMAGEEDITOR_BITMAPHEADER_H


namespace Bitmap {

#pragma pack(push, 1)
    struct FileHeader {
        uint16_t type;
        uint32_t fileSize;
        uint16_t reserved1;
        uint16_t reserved2;
        uint32_t pixelArrayOffset;
    };

    struct CoreHeader {
        uint16_t width;
        uint16_t height;
        uint16_t planes;
        uint16_t bitsPerPixel;
    };

    struct V3Header {
        int32_t width;
        int32_t height;
        uint16_t planes;
        uint16_t bitsPerPixel;
        uint32_t compression;
        uint32_t imageSize;
        int32_t xPixelsPerMeter;
        int32_t yPixelsPerMeter;
        uint32_t colorsInColorTable;
        uint32_t importantColorsCount;
    };

    struct V4Header : V3Header {
        uint32_t redMask;
        uint32_t greenMask;
        uint32_t blueMask;
        uint32_t alphaMask;
        uint32_t colorSpaceType;
        int8_t endpoints[36];
        uint32_t gammaRed;
        uint32_t gammaGreen;
        uint32_t gammaBlue;
    };

    struct V5Header : V4Header {
        uint32_t rasterPreference;
        uint32_t profileData;
        uint32_t profileSize;
        uint32_t reserved;
    };

    enum InfoHeaderVersion {
        none,
        core,
        v3,
        v4,
        v5,
    };

    struct InfoHeader {
        union {
            CoreHeader coreHeader;
            V3Header v3Header;
            V4Header v4Header;
            V5Header v5Header;
        } data{};

        uint32_t size;
        InfoHeaderVersion version;
        bool isUpsideDown = true;

        explicit InfoHeader(uint32_t size) : size(size) {
            switch (size) {
                case 12:
                    version = core;
                    break;
                case 40:
                    version = v3;
                    break;
                case 108:
                    version = v4;
                    break;
                case 124:
                    version = v5;
                    break;
                default:
                    version = none;
                    break;
            }
        }

        [[nodiscard]] int32_t getHeight() const {
            return version == core ? data.coreHeader.height : data.v3Header.height;
        }

        [[nodiscard]] int32_t getWidth() const {
            return version == core ? data.coreHeader.width : data.v3Header.width;
        }

        void setHeight(int32_t height) {
            version == core ? data.coreHeader.height = height : data.v3Header.height = height;
        }

        void setWidth(int32_t width) {
            version == core ? data.coreHeader.width = width : data.v3Header.width = width;
        }
    };

#pragma pack(pop)

}


#endif //IMAGEEDITOR_BITMAPHEADER_H
