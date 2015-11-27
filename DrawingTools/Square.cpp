#include "Square.h"

Square::Square(DisplayRect size)
: m_size { size.width, size.height }
{
}

void Square::setSize(DisplayRect size)
{
  m_size = size;
}

DisplayRect Square::getSize()
{
  return m_size;
}

void Square::setFilled(bool filled)
{
  m_filled = filled;
}

void Square::draw(DisplayBuffer &buffer)
{
  for (int x = -m_size.width / 2; x < m_size.width / 2; ++x)
  {
    for (int y = -m_size.height / 2; y < m_size.height / 2; ++y)
    {
      DisplayPoint point { x + getPosition().x, y + getPosition().y };
      
      buffer.set(point, getDrawMode());
    }
  }
}