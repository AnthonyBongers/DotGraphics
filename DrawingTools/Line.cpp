#include "Line.h"
#include <cmath>

Line::Line(DisplayPoint begin, DisplayPoint end)
{
  m_begin = begin;
  m_end = end;
}

void Line::setBegin(DisplayPoint point)
{
  m_begin = point;
}

void Line::setEnd(DisplayPoint point)
{
  m_end = point;
}

void Line::draw(DisplayBuffer &buffer)
{
  float x1 = m_begin.x;
  float x2 = m_end.x;
  float y1 = m_begin.y;
  float y2 = m_end.y;
  
  // Bresenham's line drawing equation
  // http://rosettacode.org/wiki/Bitmap/Bresenham's_line_algorithm#C.2B.2B
  
  const bool steep = (fabs(y2 - y1) > fabs(x2 - x1));
  if(steep)
  {
    std::swap(x1, y1);
    std::swap(x2, y2);
  }
  
  if(x1 > x2)
  {
    std::swap(x1, x2);
    std::swap(y1, y2);
  }
  
  const float dx = x2 - x1;
  const float dy = fabs(y2 - y1);
  
  float error = dx / 2.0f;
  const int ystep = (y1 < y2) ? 1 : -1;
  int y = (int)y1;
  
  const int maxX = (int)x2;
  
  for(int x=(int)x1; x<maxX; x++)
  {
    if(steep)
    {
      buffer.set({ getPosition().x + y, getPosition().y + x }, getDrawMode());
    }
    else
    {
      buffer.set({ getPosition().x + x, getPosition().y + y }, getDrawMode());
    }
    
    error -= dy;
    if(error < 0)
    {
      y += ystep;
      error += dx;
    }
  }
}