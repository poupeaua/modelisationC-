#include <iostream>

#include "gl_defs.hxx"

#include "camera.hxx"

/** Initialise la caméra en fonciton du clavier et de la position
 * souhaitée
 */
Camera::Camera(KEYBOARD p_keyboard, float p_X, float p_Y, float p_Z,
    float p_psi, float p_theta,
    float p_rotation_speed, float p_translation_speed,
    int p_window_width, int p_window_height) :
  keyboard(p_keyboard),
  X(p_X),
  Y(p_Y),
  Z(p_Z),
  mouse_x(p_window_width/2),
  mouse_y(p_window_height/2),
  psi(p_psi),
  theta(p_theta),
  rotation_speed(p_rotation_speed),
  translation_speed(p_translation_speed),
  // Mapping des claviers en fonction du clavier
  time(0) {
    for(int i=0 ; i<255 ; i++) {
      keys[i] = false;
    }
    switch(keyboard) {
      case AZERTY:
        key_map[FORWARD]  = static_cast<int>('z');
        key_map[BACKWARD] = static_cast<int>('s');
        key_map[LEFT]     = static_cast<int>('q');
        key_map[RIGHT]    = static_cast<int>('d');
        break;
      case QWERTY:
        key_map[FORWARD]  = static_cast<int>('w');
        key_map[BACKWARD] = static_cast<int>('s');
        key_map[LEFT]     = static_cast<int>('a');
        key_map[RIGHT]    = static_cast<int>('d');
        break;
    }
  }

/** Calcul les nouvelles valeurs d'angle en fonction de la position
 * de la souris avec une limite
 * @param[in] x position de la souris dans la direction x
 * @param[in] y position de la souris dans la direction y
 */
void Camera::rotation(int x, int y) {
  theta -= static_cast<float>(x - mouse_x) * rotation_speed;
  psi   += static_cast<float>(y - mouse_y) * rotation_speed;
  if(psi<=0.1) {
    psi = 0.1;
  }
  else if(psi>=0.95*M_PI) {
    psi = 0.95*M_PI;
  }
  mouse_x = x;
  mouse_y = y;
}

/** Modifie le centre de la sphère de visualisation pour
 *       une sensibilité donnée
 *       l'angle de la sphère
 */
void Camera::translation() {
  float t = static_cast<float>(glutGet(GLUT_ELAPSED_TIME) - time);
  time    = glutGet(GLUT_ELAPSED_TIME);
  if(keys[key_map[FORWARD]]) {
    X += sin(theta)*sin(psi) * translation_speed * t;
    Y += cos(psi)            * translation_speed * t;
    Z += cos(theta)*sin(psi) * translation_speed * t;
  }
  if(keys[key_map[BACKWARD]]) {
    X -= sin(theta)*sin(psi) * translation_speed * t;
    Y -= cos(psi)            * translation_speed * t;
    Z -= cos(theta)*sin(psi) * translation_speed * t;
  }
  if(keys[key_map[LEFT]]) {
    X -= sin(theta - M_PI/2)*sin(psi) * translation_speed * t;
    Z -= cos(theta - M_PI/2)*sin(psi) * translation_speed * t;
  }
  if(keys[key_map[RIGHT]]) {
    X -= sin(theta + M_PI/2)*sin(psi) * translation_speed * t;
    Z -= cos(theta + M_PI/2)*sin(psi) * translation_speed * t;
  }
}
