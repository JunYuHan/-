#pragma once
#include "Scene.h"
class Credit :
    public Scene
{

    Texture* credit;
    Button* back;

    // Scene��(��) ���� ��ӵ�
    virtual void Init() override;
    virtual void Update() override;
    virtual void Render() override;
    virtual void Release() override;
};

