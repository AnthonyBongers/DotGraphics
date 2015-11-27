#pragma once

#include "DisplayBuffer.h"

class DisplayObject
{
public:
  void setPosition(DisplayPoint position);
  DisplayPoint getPosition();
  
  void setDrawMode(DrawMode mode);
  DrawMode getDrawMode() const;
  
  virtual void draw(DisplayBuffer &buffer);
  
private:
  DisplayPoint m_position { };
  
  DrawMode m_drawMode { DrawMode::Set };
};