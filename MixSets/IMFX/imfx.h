/*
Credits for DK22Pac - IMFX
If you consider fixing something here, you should also consider fixing there: https://github.com/DK22Pac/imfx
*/
#pragma once
#include "RenderWare.h"

class IMFX {
public:
    static bool bSampGame;

    IMFX();

    static void ProcessPerFrame();
};