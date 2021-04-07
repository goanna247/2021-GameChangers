#pragma once

struct wfd_paths {
  /**
  * Create a spline using waypoints and control points
  */
  wayfinder::Path::sSpline spline1{
    {
      {0,0},
      {1,0}
    }, // Waypoints

    {0,0}, // Start control point
    {1,0}, // End Control point
    "poggers"
  };

  /**
  * Path to use with follower
  */
  wayfinder::Path::sPath path;

  wayfinder::Path::lLine line1 {{{0,0}, {0.4,0}}};
  wayfinder::Path::lLine line2 {{{0.4,0}, {0.4,1.8}}};

  wayfinder::Path::lLine l1 {{{0,0}, {0,0}}};
  wayfinder::Path::lLine l2 {{{0,0}, {0,0}}};
  wayfinder::Path::lLine l3 {{{0,0}, {0,0}}};
  wayfinder::Path::lLine l4 {{{0,0}, {0,0}}};
  wayfinder::Path::lLine l5 {{{0,0}, {0,0}}};
  wayfinder::Path::lLine l6 {{{0,0}, {0,0}}};
  wayfinder::Path::lLine l7 {{{0,0}, {0.5,0.5}}};
  wayfinder::Path::lLine l8 {{{0.5,0.5}, {1.6,1.6}}};
  wayfinder::Path::lLine l9 {{{1.6,1.6}, {1.5,2.2}}};
  // wayfinder::Path::lLine l10 {{{1.5,2.5}, {-2,2}}};

  wayfinder::Path::lLine m1 {{{0,0}, {0,0}}};
  wayfinder::Path::lLine m2 {{{0,0}, {0,0}}};
  wayfinder::Path::lLine m3 {{{0,0}, {0,0}}};
  wayfinder::Path::lLine m4 {{{0,0}, {0,0}}};
  wayfinder::Path::lLine m5 {{{0,0}, {0,0}}};
  wayfinder::Path::lLine m6 {{{0,0}, {0,0}}};
  wayfinder::Path::lLine m7 {{{0,0}, {0,0}}};
  wayfinder::Path::lLine m8 {{{0,0}, {0,0}}};
  wayfinder::Path::lLine m9 {{{0,0}, {0,0}}};
  wayfinder::Path::lLine m10 {{{0,0}, {0,0}}};
  wayfinder::Path::lLine m11 {{{0,0}, {0,0}}};
  wayfinder::Path::lLine m12 {{{0,0}, {0,0}}};
  wayfinder::Path::lLine m13 {{{0,0}, {0,0}}};
  wayfinder::Path::lLine m14 {{{0,0}, {-3,-0.5}}}; //start
  wayfinder::Path::lLine m15 {{{-3,-0.5}, {-6,-0.5}}};


  wayfinder::Path::lLine n1 {{{0,0}, {0,0}}};
  wayfinder::Path::lLine n2 {{{0,0}, {0,0}}};
  wayfinder::Path::lLine n3 {{{0,0}, {0,0}}};
  wayfinder::Path::lLine n4 {{{0,0}, {0,0}}};
  wayfinder::Path::lLine n5 {{{0,0}, {0,0}}};
  wayfinder::Path::lLine n6 {{{0,0}, {0,0}}};
  wayfinder::Path::lLine n7 {{{0,0}, {0,0}}};
  wayfinder::Path::lLine n8 {{{0,0}, {0,0}}};
  wayfinder::Path::lLine n9 {{{0,0}, {0,0}}};
  wayfinder::Path::lLine n10 {{{0,0}, {0,0}}};
  wayfinder::Path::lLine n11 {{{0,0}, {0,0}}};
  wayfinder::Path::lLine n12 {{{0,0}, {0,0}}};
  wayfinder::Path::lLine n13 {{{0,0}, {0,0}}};
  wayfinder::Path::lLine n14 {{{0,0}, {0,0}}};
  wayfinder::Path::lLine n15 {{{0,0}, {0,0}}};
  wayfinder::Path::lLine n16 {{{0,0}, {0,0}}};
  wayfinder::Path::lLine n17 {{{0,0}, {0,0}}};
  wayfinder::Path::lLine n18 {{{0,0}, {0,0}}};
  wayfinder::Path::lLine n19 {{{0,0}, {0,0}}};
  wayfinder::Path::lLine n20 {{{0,0}, {0,0}}};
  wayfinder::Path::lLine n21 {{{0,0}, {0,0}}};
  wayfinder::Path::lLine n22 {{{0,0}, {0,0}}};
  wayfinder::Path::lLine n23 {{{0,0}, {0,0}}};
  wayfinder::Path::lLine n24 {{{0,0}, {0,2}}};
  wayfinder::Path::lLine n25 {{{0,2}, {0,3}}};

  // wayfinder::Path::lLine n17 {{{0,-2.5}, {0,-3}}};







  wayfinder::Path::lPath path1L {
    {
      line1,
      line2
    }
  };

  wayfinder::Path::lPath path2L {
    {
      l1,
      l2,
      l3,
      l4,
      l5,
      l6,
      l7,
      l8,
      l9
    }
  };

  wayfinder::Path::lPath path3L {
    {
      m1,
      m2,
      m3,
      m4,
      m5,
      m6,
      m7,
      m8,
      m9,
      m10,
      m11,
      m12,
      m13,
      m14,
      m15
    }
  };


  wayfinder::Path::lPath path4L {
    {
      n1,
      n2,
      n3,
      n4,
      n5,
      n6,
      n7,
      n8,
      n9,
      n10,
      n11,
      n12,
      n13,
      n14,
      n15,
      n16,
      n17,
      n18,
      n19,
      n20,
      n21,
      n22,
      n23,
      n24,
      n25
      // n17
    }
  };

};