#pragma once

struct wfd_paths {
  /**
  * Create a spline using waypoints and control points
  */
  wayfinder::Path::sSpline spline1{
    {
      {0,0},
      {1,0}
                // {0,0}, 
                // {1,-1.5},
                // {2, -2},
                // {3, -2.5},
                // {4, -3},
                // {5, -3.5},
                // {6, -4},
                // {7, -4.5}
      // {0.8, 3},
      // {1.5, 2},
      // {0.8, 1},
      // {0.8, 0}

    }, // Waypoints

    {0,0}, // Start control point
    {1,0}, // End Control point
    "poggers"
  };

  /**
  * Path to use with follower
  */
  wayfinder::Path::sPath path;

  // wayfinder::Path::lLine line1 {{ {5, -0.2}, {2, -0.2} }};
  wayfinder::Path::lLine line1 {{{0,0}, {0.4,0}}};
  wayfinder::Path::lLine line2 {{{0.4,0}, {1.4,-1.7}}};
  wayfinder::Path::lLine line3 {{{1.4,-1.7}, {4.4,-1.7}}};
  wayfinder::Path::lLine line4 {{{4.4,-1.7}, {5.5,0.2}}};
  wayfinder::Path::lLine line5 {{{5.5,0.2}, {6.2,0.2}}};
  wayfinder::Path::lLine line6 {{{6.2,0.2}, {6.2,-0.4}}};
  wayfinder::Path::lLine line7 {{{6.2,-0.4}, {5.5,-1.3}}};
  wayfinder::Path::lLine line8 {{{5.5,-1.3}, {5,-0.2}}};
  // wayfinder::Path::lLine line9 {{{5,-0.2}, {3.5,-0.4}}};
  // wayfinder::Path::lLine line10 {{{3,-1.7}, {1.4,-1.7}}};
  // wayfinder::Path::lLine line11 {{{1.4,-1.7}, {,-1.7}}};






  wayfinder::Path::lPath pathL {
    {
      line1,
      line2,
      line3,
      line4,
      line5,
      line6,
      line7,
      line8
      // line9
      // line10
    }
  };
};