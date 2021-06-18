#pragma once
#include "Scene.h"
class Credit :
    public Scene
{

    Texture* credit;
    Button* back;

    // Scene을(를) 통해 상속됨
    virtual void Init() override;
    virtual void Update() override;
    virtual void Render() override;
    virtual void Release() override;
};

