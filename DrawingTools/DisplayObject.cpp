#include "DisplayObject.h"

DisplayPoint DisplayObject::getPosition()
{
  return m_position;
}

void DisplayObject::setPosition(DisplayPoint position)
{
  m_position = position;
}

void DisplayObject::setDrawMode(DrawMode mode)
{
  m_drawMode = mode;
}

DrawMode DisplayObject::getDrawMode() const
{
  return m_drawMode;
}

void DisplayObject::draw(DisplayBuffer &buffer)
{
  
}