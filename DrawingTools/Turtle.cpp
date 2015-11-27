#include "Turtle.h"
#include "Line.h"
#include <cmath>

// 0.017453292519 = PI / 180
#define degreesToRadians(a) (a * 0.017453292519)

Turtle::Turtle(DisplayBuffer *buffer, DisplayPoint position)
: m_bufferHandle { buffer }
, m_position { position }
{}

void Turtle::forward(int distance)
{
  DisplayPoint begin { 0, 0 };
  
  DisplayPoint end
  {
    distance * std::cos(m_angle),
    distance * std::sin(m_angle)
  };
  
  Line line { begin, end };
  
  line.setPosition(m_position);
  line.draw(*m_bufferHandle);
  
  m_position =
  {
    m_position.x + end.x,
    m_position.y + end.y
  };
}

void Turtle::backward(int distance)
{
  forward(-distance);
}

void Turtle::right(double angle)
{
  m_angle -= degreesToRadians(angle);
}

void Turtle::left(double angle)
{
  m_angle += degreesToRadians(angle);
}