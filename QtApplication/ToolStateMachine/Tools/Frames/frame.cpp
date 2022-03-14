#include "frame.h"

Frame::Frame(const QString& name) : Tool(name, new DefaultToolView(name), new FrameCore()) {
}
