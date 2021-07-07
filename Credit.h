#pragma once
#include "Scene.h"
class Credit :
    public Scene
{
    Texture* bg;
    // Scene을(를) 통해 상속됨
    virtual void Init() override;
    virtual void Update() override;
    virtual void Render() override;
    virtual void Release() override;
    //f
    Button* Back;
};

