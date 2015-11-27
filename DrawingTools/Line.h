#pragma once

#include "DisplayObject.h"

class Line : public DisplayObject
{
public:
  Line(DisplayPoint begin = {}, DisplayPoint end = {});
  
  void setBegin(DisplayPoint point);
  void setEnd(DisplayPoint point);
  
  virtual void draw(DisplayBuffer &buffer) override;
  
private:
  DisplayPoint m_begin {};
  DisplayPoint m_end {};
};