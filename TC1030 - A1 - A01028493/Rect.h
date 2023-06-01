#pragma once

class Polar;

class Rect {
  private:
   float x;
   float y;

  public:
   Rect();
   Rect(float, float);
   Rect operator+(const Rect&) const;
   Rect operator+(const Polar&) const;
   float getX() const;
   float getY() const;
   void print() const;
};
