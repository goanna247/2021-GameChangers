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

  // wayfinder::Path::lLine line1 {{{5, -0.2}, {2, -0.2}}};
  wayfinder::Path::lLine line1 {{{0,0}, {0.4,0}}};
  wayfinder::Path::lLine line2 {{{0.4,0}, {1.4,1.7}}};
  wayfinder::Path::lLine line3 {{{1.4, 1.7}, {4.6,1.7}}};
  wayfinder::Path::lLine line4 {{{4.6,1.7}, {5,-0.2}}};
  wayfinder::Path::lLine line5 {{{5,-0.2}, {6, -0.3}}};
  wayfinder::Path::lLine line6 {{{6,-0.3}, {6.3, 1.4}}};
  wayfinder::Path::lLine line7 {{{6.3,1.4}, {5.5,1.4}}};
  // wayfinder::Path::lLine line8 {{{5.6,1.4}, {5.6, 0.5}}};
  // wayfinder::Path::lLine line8 {{{6,1.8}, {5.5,1.6}}};
  // wayfinder::Path::lLine line8 {{{5,1.6}, {5,0}}};
  // wayfinder::Path::lLine line9 {{{5,0}, {3,0}}};

  wayfinder::Path::lLine l1 {{{0,0}, {0,0}}}; //0.0, 0.4, 0.8
  wayfinder::Path::lLine l2 {{{0,0}, {0,0}}};
  wayfinder::Path::lLine l3 {{{0,0}, {0,0}}};
  wayfinder::Path::lLine l4 {{{0,0}, {0,0}}};
  wayfinder::Path::lLine l5 {{{0,0}, {0,0}}};
  wayfinder::Path::lLine l6 {{{0,0}, {0,0}}};
  wayfinder::Path::lLine l7 {{{0,0}, {0,0}}};
  wayfinder::Path::lLine l8 {{{0,0}, {0,0}}}; 
  wayfinder::Path::lLine l9 {{{0,0}, {-0.4,2}}}; 
  wayfinder::Path::lLine l10 {{{-0.4,2}, {0.5,2}}}; 
  wayfinder::Path::lLine l11 {{{0.5,2}, {1,2.5}}}; 
  wayfinder::Path::lLine l12 {{{1,2.5}, {2,3.5}}}; 
  wayfinder::Path::lLine l14 {{{2.4,3.5}, {4.4,2}}}; 
  // wayfinder::Path::lLine l15 {{{3,2}, {4,2}}}; 

  




  // wayfinder::Path::lLine l11 {{{0.2,2}, {4,2}}}; 
  // wayfinder::Path::lLine l12 {{{4,2}, {4.5,0}}}; 





  // wayfinder::Path::lLine l2 {{{8,4}, {10, 2}}};
  // wayfinder::Path::lLine l3 {{{10, 2}, {4, 0.8}}};
  // wayfinder::Path::lLine line3 {{{1.4, 1.7}, {4.5,1.7}}};
  // wayfinder::Path::lLine line4 {{{4.5,1.7}, {5.5,-0.1}}};
  // wayfinder::Path::lLine line5 {{{5.5,-0.1}, {6.2,1.4}}};
  // wayfinder::Path::lLine line6 {{{6.2,1.4}, {6,1.6}}};
  // wayfinder::Path::lLine line7 {{{6,1.6}, {5.5,1.6}}};
  // wayfinder::Path::lLine line8 {{{5.5,1.6}, {5,1.6}}};  
  

  // wayfinder::Path::lLine line9 {{{5, 1.6}, {5, 0.5}}};

  // wayfinder::Path::lLine line10 {{{5,0.5}, {2,0.5}}}; // Section 2, robot reverse
  // wayfinder::Path::lLine line10 {{{4,2}, {6,2}}};


  wayfinder::Path::lLine a {{{0,0}, {1, 2.5}}};
  wayfinder::Path::lLine b {{{1, 0}, {2, 1}}};
  wayfinder::Path::lLine c {{{2, 1}, {3, 1}}};

  wayfinder::Path::lPath path1L {
    {
      line1,
      line2,
      line3,
      line4,
      line5,
      line6,
      line7
      // line8
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
      l9,
      l10,
      l11,
      l12,
      l13,
      l14
      // l15
      // l12
    }
  };

  wayfinder::Path::lPath path3L {
    {
      a,
      b,
      c
    }
  };
};