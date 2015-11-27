#pragma once

#include "DisplayBuffer.h"

/** A turtle graphics object.
 *
 * A simple implementation of the Logo turtle drawing object. 
 * Where ever the turtle moves, a line will be drawn in it's wake. 
 * Allows for moving forwards and backwards, and rotating left and right.
 */
class Turtle
{
public:
  Turtle(DisplayBuffer *buffer, DisplayPoint position = {});
  
  // Move and draw a line from it's current position to it's destination.
  void forward(int distance);
  void backward(int distance);
  
  // Rotate the turtle by degrees.
  void right(double degrees);
  void left(double degrees);
  
private:
  // Handle to the drawing buffer. No ownership of memory.
  DisplayBuffer *m_bufferHandle = nullptr;
  
  DisplayPoint m_position {};
  
  // The turtles rotation, stored in radians.
  double m_angle {};
};