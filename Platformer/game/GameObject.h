#pragma once
class GameObject {
public:
    virtual void Initialize() = 0;
    virtual void Deinitialize() = 0;
    virtual void Update() = 0;
};