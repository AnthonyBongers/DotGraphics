#pragma once

#include "DisplayObject.h"

class Square : public DisplayObject
{
public:
  Square(DisplayRect size = {});
  
  void setSize(DisplayRect size);
  DisplayRect getSize();
  
  void setFilled(bool filled);
  
  virtual void draw(DisplayBuffer &buffer) override;
  
private:
  DisplayRect m_size {};
  bool m_filled {};
};