#pragma once

#include <map>
#include <functional>

class Brush {
public:
  Brush();
 
  void draw();
  void nextBrush();
  void prevBrush();

private:

  void draw_SingleRect();
  void draw_MultiRect();
  void draw_FadedCircles();
  void draw_Stars();
  void draw_Triangles();

  using BrushMap = std::map<int, std::function<void()>>;
  //using BrushMap = std::map<int, float>;
  BrushMap m_brushMap;

  int m_brushType{0};
};
