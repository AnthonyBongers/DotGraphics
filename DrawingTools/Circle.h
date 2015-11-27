#pragma once

#include "DisplayObject.h"

class Circle : public DisplayObject
{
public:
  Circle(int radius = 0);
  
  void setRadius(int radius);
  int getRadius();
  
  void setFilled(bool filled);
  
  virtual void draw(DisplayBuffer &buffer) override;
  
private:  
  int m_radius {};
  bool m_filled {};
};