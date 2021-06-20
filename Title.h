#pragma once
#include "Scene.h"
class Title :
    public Scene
{
public:
    Title(int type);

    Texture* bg;

    vector<Texture*> anim;
    Timer* delay;
    int index = 0;

    Button* start;
    Button* credit;
    Button* howto;
    Button* exit;

    Window* win_credit;
    ScrollMap* map;

    int type;
    bool isM_On;

    // Scene을(를) 통해 상속됨
    virtual void Init() override;
    virtual void Update() override;
    virtual void Render() override;
    virtual void Release() override;
};

