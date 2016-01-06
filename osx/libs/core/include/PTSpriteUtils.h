#ifndef PTSPRITEUTILS_H
#define PTSPRITEUTILS_H

#include "models/PTModelSprite.h"
#include "models/PTModelScreen.h"

struct ptHsl {
    float h;
    float s;
    float l;
};

class PTSpriteUtils
{
public:
    PTSpriteUtils();
    static CCSprite* solidColorSprite(CCSize size, ccColor4B color);
    static void alphaCrop(PTModelSprite* model);
    static bool objectDepthSort(const void *p1, const void *p2);
    static CCPoint projectPointOnLine(CCPoint line1, CCPoint line2, CCPoint toProject);

#ifdef __QT__

    static QRgb toRgb( ptHsl hsl );
    static ptHsl toHsl( QRgb rgb );
    static QPixmap screenModelToPixmap(PTModelScreen* model, QSize canvasSize, bool isLandscape = true);

    static bool validateImages(const QList<QUrl> &urls);
    static bool validateImage(const QUrl &url);

#endif
};



#endif // PTSPRITEUTILS_H

