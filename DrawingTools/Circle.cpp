#include "Circle.h"

Circle::Circle(int radius)
: m_radius { radius }
{
}

void Circle::setRadius(int radius)
{
  m_radius = radius;
}

int Circle::getRadius()
{
  return m_radius;
}

void Circle::setFilled(bool filled)
{
  m_filled = filled;
}

void Circle::draw(DisplayBuffer &buffer)
{
  int x = m_radius;
  int y = 0;
  int decisionOver2 = 1 - x;
  
  // Draw on a temp buffer and then bring over to the main buffer when done.
  // This is required at the moment since this circle drawing alg has a fair
  // amount of overdraw, and the Toggle drawmode wouldn't work with that.
  DisplayBuffer tempBuffer({ m_radius * 2 + 1, m_radius * 2 + 1 });
  
  // Alg for drawing a circle
  while(y <= x)
  {
    int jump = m_filled ? 1 : (x * 2);
    
    for (int i = -x; i <= x; i += jump)
    {
      tempBuffer.set({ (double)i + m_radius,  (double)y + m_radius  }, DrawMode::Set);
      tempBuffer.set({ (double)i + m_radius,  (double)-y + m_radius }, DrawMode::Set);
      tempBuffer.set({ (double)y + m_radius,  (double)i + m_radius  }, DrawMode::Set);
      tempBuffer.set({ (double)-y + m_radius, (double)i + m_radius  }, DrawMode::Set);
    }
    
    y++;
    
    if (decisionOver2<=0) decisionOver2 += 2 * y + 1;
    
    else
    {
      x--;
      decisionOver2 += 2 * (y - x) + 1;
    }
  }
  
  // Copy the temp buffer over to the main buffer
  for (int x = 0; x < tempBuffer.getViewport().width; ++x)
  {
    for (int y = 0; y < tempBuffer.getViewport().height; ++y)
    {
      if (tempBuffer.get({ (double)x, (double)y }))
      {
        DisplayPoint point
        {
          x - m_radius + getPosition().x,
          y - m_radius + getPosition().y
        };
        
        buffer.set(point, getDrawMode());
      }
    }
  }
}
