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

  wayfinder::Path::lLine line1 {{{0,0}, {3.5,0}}};
  wayfinder::Path::lLine line2 {{{3.5,0}, {3.5,-1.3}}};
  // wayfinder::Path::lLine line3 {{{3.5,-1.5}, {2.5,-1.6}}};

  wayfinder::Path::lLine l1 {{{0,0}, {0,0}}};
  wayfinder::Path::lLine l2 {{{0,0}, {0,0}}};
  wayfinder::Path::lLine l3 {{{0,0}, {0,0}}};
  wayfinder::Path::lLine l4 {{{0,0}, {0,-1}}};

  wayfinder::Path::lLine m1 {{{0,0}, {0,0}}};
  wayfinder::Path::lLine m2 {{{0,0}, {0,0}}};
  wayfinder::Path::lLine m3 {{{0,0}, {0,0}}};
  wayfinder::Path::lLine m4 {{{0,0}, {0,0}}};
  wayfinder::Path::lLine m5 {{{0,0}, {0,0}}};
  wayfinder::Path::lLine m6 {{{0,0}, {0,-1}}};

  wayfinder::Path::lPath path1L {
    {
      line1,
      line2
      // line3
    }
  };

  wayfinder::Path::lPath path2L {
    {
      l1,
      l2,
      l3,
      l4
    }
  };

  wayfinder::Path::lPath path3L {
    {
      m1,
      m2,
      m3,
      m4,
      m5,
      m6
    }
  };
};