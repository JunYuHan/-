#pragma once
#include "Obj.h"
class Button :
    public Obj
{
public:
    Button(Texture* bg, V2 pos, const string& text, float w, float h, float depth, function<void()> func, bool T_B);

    float W, H;
    Texture* bg;
    Texture* sword;
    V2 b_pos;
    string text;
    function<void()> func;

    Timer* wait;

    int r = 255, g = 255, b = 255;
    float swordX;

    float depth;

    bool isOn;
    bool T_B;
    bool title_button;
    bool T_B_On = false;
    bool isClick = false;

    void On();
    void Off();

    // Obj을(를) 통해 상속됨
    virtual void Init() override;
    virtual void Update() override;
    virtual void Render() override;
    virtual void Release() override;
    virtual void Enter(Col* p) override;
    virtual void Stay(Col* p) override;
    virtual void Exit(Col* p) override;
};

