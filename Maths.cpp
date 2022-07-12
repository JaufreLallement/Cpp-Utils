#define _USE_MATH_DEFINES
#include <cmath>
#include <iostream>
using namespace std;

const double PI = 3.14159265358979323;

/**
 * @brief Returns the round version of a given number based on a round value
 *
 * @param num    : number to round
 * @param rnd    : round value
 * @return float : rounded number
 */
float round(float num, unsigned short int rnd)
{
  return round(num * rnd) / rnd;
}

/**
 * @brief Returns the percentage based on a given numerator and total
 *
 * @param num    : numerator
 * @param total  : total
 * @return float : percentage
 */
float percent(float num, float total = 1)
{
  return (total != 0) ? num / total * 100 : 0;
}

/**
 * @brief Apply a given percentage on a given total
 *
 * @param total   : total on which apply the percentage
 * @param percent : percentage to apply
 * @return float  : resulting number
 */
float appPercent(float total, unsigned int percent)
{
  return total * percent * 0.01;
}

/**
 * @brief Returns the circumference of a circle based on its radius
 *
 * @param r             : radius
 * @return unsigned int : circumference
 */
unsigned int circ(float r)
{
  return 2 * PI * r;
}

/**
 * @brief Returns the radians correspunding to the given angle
 *
 * @param a      : angle
 * @return float : radians
 */
float angRad(float a)
{
  return a * (PI / 180);
}

/**
 * @brief Keeps a given value inside the given interval based on a min and max value.
 *
 * @param num    : number to limit
 * @param inter  : interval
 * @return float : limited value
 */
float limit(float num, float inter[2])
{
  return fmin(fmax(num, inter[0]), inter[1]);
}

/**
 * @brief Checks whether the given number is inside the given interval
 *
 * @param num    : number to check
 * @param inter  : interval
 * @param inc    : should the interval be inclusive or not
 * @return true  : number is inside the interval
 * @return false : number is not inside the interval
 */
bool between(float num, float inter[2], bool inc = false)
{
  const float min = inter[0], max = inter[1];
  return inc ? (num >= min && num <= max) : (num > min && num < max);
}

/**
 * @brief Returns cartesian coordinates based on a radius, an angle and offset coordinates
 * Cartesian coordinates can be used to place element around a circle
 *
 * @param r                 : circle radius
 * @param a                 : angle
 * @param offset            : offset coordinates
 * @return array<float, 2>  : coordinates
 */
float *cartesXY(float r, float a, float offset[2])
{
  const float rad = angRad(a);
  return new float[2]{r * cos(rad) + offset[0], r * sin(rad) + offset[1]};
}

/**
 * @brief Returns the angle between x axis and a point based on its coordinates
 *
 * @param origin : origin coordinates
 * @param target : target coordinates
 * @return float : resulting theta angle
 */
float arctan(float origin[2], float target[2])
{
  const float ox = origin[0], oy = origin[1];
  const float tx = target[0], ty = target[1];
  const float dx = ox - tx, dy = oy - ty;

  float theta = atan2(-dx, -dy);
  theta *= 180 / PI;

  if (theta < 0)
    theta += 360;

  return theta;
}

int main()
{
  cout << round(43.28, 10) << endl;
  cout << percent(84, 0) << "%" << endl;
  cout << appPercent(18432, 50) << endl;
  cout << circ(20) << endl;
  cout << angRad(90) << endl;

  float offs[2] = {50, 50};
  float *myCartesianCoords = cartesXY(20, 90, offs);
  cout << "X=" << myCartesianCoords[0] << ", Y=" << myCartesianCoords[1] << endl;
}