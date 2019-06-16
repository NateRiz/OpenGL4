//
// Single camera active at once. Takes input from the user to change position.
//
#include "Object3d.h"

#ifndef VOXEL4_CAMERA_H
#define VOXEL4_CAMERA_H


class Camera : public Object3d{

public:
    Camera();

    /// Inherited from Parent
    virtual void Tick(float delta);

    /// called every frame to see how the mouse has moved and update the position accordingly.
    void ProcessMouseMovement(float delta, double x, double y);


    void ProcessInput(float delta);
    void ProcessMouseMovement(float delta);

    const float VIEW_DISTANCE = 300.f;
    static double mCurrentMouseX;
    static double mCurrentMouseY;


private:
    /// Set as the GLFW callback for moving the mouse. Updates the current X/Y mouse position.
    static void MouseCallback(GLFWwindow*, double x, double y);

    float yaw   = -90.0f;
    float pitch =  0.0f;
    double mLastMouseX=0;
    double mLastMouseY=0;


};

double Camera::mCurrentMouseX=0;
double Camera::mCurrentMouseY=0;

#endif //VOXEL4_CAMERA_H
