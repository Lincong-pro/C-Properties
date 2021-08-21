#pragma 
#include <iostream>

struct Vector2d {
  double x, y;
};

//Union主要用于解决以下问题,可以通过vector2d和x,y,z,f的方式进行访问
struct Vector4d {
  union  {
    struct {
      double x, y, z, f;
    };
    struct {
      Vector2d vec1,vec2;  
      // vec1 is the same as (x,y),and vec2 is the same as (z,f)
      // Debugging in memory,it shows the following number!
    };
  };
};


void testUnion() { 
    /**memory contents:
     * 00 00 00 00 | 00 00 f0 3f | 00 00 00 00 | 00 00 00 40 
     * 00 00 00 00 | 00 00 08 40 | 00 00 00 00 | 00 00 10 40
     */
    Vector4d vec{1,2,3,4}; //vector2d vector2d
    
    // use type punning to get the value,point to the same memory content
    double* d1 = (double *)(&vec.x);
    /**
     * 00 00 00 00 00 00 f0 3f 00 00 00 00 00 00 00 40 00 00 00 00 00 00 08 40 00 00 00 00 00 00 10 40
     */
    double* member_union1 = (double *)&vec.vec1;
    /**
     * 00 00 00 00 00 00 f0 3f 00 00 00 00 00 00 00 40 00 00 00 00 00 00 08 40 00 00 00 00 00 00 10 40
     */
    double* member_union2 = &vec.x;

    /**
     * 00 00 00 00 00 00 08 40 00 00 00 00 00 00 10 40
     */
    double* member_union1_z = &vec.z;
    // 内存只是向右移动4bytes
    /**
     * 00 00 00 00 00 00 08 40 00 00 00 00 00 00 10 40
     */
    double* member_union2_2 = (double*)&vec.vec2;



    std::cout << d1[0] << " " << d1[1] << "\n";
    std::cout << d1[2];
    std::cout << d1[3];
}


