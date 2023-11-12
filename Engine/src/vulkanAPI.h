#pragma once
#include "graphicsAPI.h"
namespace myEngine {

class vulkanAPI :
    public graphicsAPI
{
public:
    void setup();
};

}