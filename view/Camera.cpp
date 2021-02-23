#ifdef __linux__
    #include <GL/glut.h>
#else
    #include <GLUT/glut.h>
#endif
#include "Camera.h"

/*
Initializes the variables and creates the key map according to the
given keyboard configuration. On azerty keyboards, 'z', 'q', 's', 'd'
and on qwerty keyboards, 'w', 'a', 's', 'd', allow the user to move
in the 3D world with the left hand while controling the mouse with
the right hand. Indeed, these letters are on the left-hand side of
the keyboard and offer a configuration similar to the arrow pad's one.
*/
void Camera::UpdateSettings(
        float p_X, float p_Y, float p_Z, float p_psi, float p_theta, float p_rotation_speed,
        float p_translation_speed, int p_window_width, int p_window_height) {
            setX(p_X);
            setY(p_Y);
            setZ(p_Z);
            mouse_x = (p_window_width / 2);
            mouse_y = (p_window_height / 2);
            psi = p_psi;
            theta = p_theta;
            rotation_speed = p_rotation_speed;
            translation_speed = p_translation_speed;
}
Camera::Camera(
        float p_X, float p_Y, float p_Z, float p_psi, float p_theta, float p_rotation_speed,
        float p_translation_speed, int p_window_width, int p_window_height) {
    UpdateSettings(
            p_X, p_Y, p_Z, p_psi, p_theta, p_rotation_speed,
            p_translation_speed, p_window_width, p_window_height);
}
/*
Computes the new angle values given the mouse direction. The sight's
only limits are when looking up or down: it is impossible for the user to
look at his feets or straight up in the air (these edge cases would need
a special treatment in the gluLookAt function).
*/
void Camera::rotation(int x, int y) {
    theta -= static_cast<float>(x - mouse_x) * rotation_speed;
    psi   += static_cast<float>(y - mouse_y) * rotation_speed;
    if(psi<=0.1)            psi = 0.1;
    else if(psi>=0.95*M_PI) psi = 0.95*M_PI;
    mouse_x = x;
    mouse_y = y;
}

/*
Computes the new sphere center given the speed and direction of the camera.
The direction depends on the current angles values, the keys being pushed,
and the elapsed time since the last function call.
*/
void Camera::translation(bool left, bool backward, bool forward, bool right) {
    float t = static_cast<float>(glutGet(GLUT_ELAPSED_TIME) - time);
    time    = glutGet(GLUT_ELAPSED_TIME);
    if (forward) {
        X += sin(theta)*sin(psi) * translation_speed * t;
        Y += cos(psi)            * translation_speed * t;
        Z += cos(theta)*sin(psi) * translation_speed * t;
    }
    if (backward) {
        X -= sin(theta)*sin(psi) * translation_speed * t;
        Y -= cos(psi)            * translation_speed * t;
        Z -= cos(theta)*sin(psi) * translation_speed * t;
    }
    if (left) {
        X -= sin(theta - M_PI/2)*sin(psi) * translation_speed * t;
        Z -= cos(theta - M_PI/2)*sin(psi) * translation_speed * t;
    }
    if (right) {
        X -= sin(theta + M_PI/2)*sin(psi) * translation_speed * t;
        Z -= cos(theta + M_PI/2)*sin(psi) * translation_speed * t;
    }
    if (Z < -10000 || Z > 10000) Z = 0.0f;
    if (X < -10000 || X > 10000) X = 0.0f;
    if (Y < -10000 || Y > 10000) Y = 0.0f;
}
/*
Set center
*/
void Camera::setCenter(int x, int y) {
    mouse_x = x; mouse_y = y;
}
