#ifndef TEST_H_INCLUDED
#define TEST_H_INCLUDED
#include "cppunitlite/TestHarness.h"
#include <string>
#include <algorithm>
#include "matrix.h"
#include "vector.h"
#include "enter.h"




TEST(Vector, first) {
    double a[] = {1,2,3,4,5,6,7};
    Vector v(7,a);
    LONGS_EQUAL(7,v.dimension());
    LONGS_EQUAL(1,v.component(1));
    LONGS_EQUAL(2,v.component(2));
}
/*TEST(Vector,matrix){
    double a[] = {1,2,3,4,5,6,7};
    double b[] = {3,2,3,9,4,2,7};
    Vector va(7,a);
    Vector vb(7,b);
    Vector vc = vb-va;
    LONGS_EQUAL(7,vc.dimension());
    DOUBLES_EQUAL(0,vc.component(1),0.00001);
    DOUBLES_EQUAL(4,vc.component(2),0.00001);
    DOUBLES_EQUAL(6,vc.component(3),0.00001);
    DOUBLES_EQUAL(3,vc.component(4),0.00001);
    DOUBLES_EQUAL(11,vc.component(5),0.00001);
    DOUBLES_EQUAL(16,vc.component(6),0.00001);
    DOUBLES_EQUAL(14,vc.component(7),0.00001);

}*/
TEST(reduce,matrix){
    /*double u[]={0,4,3}, v[]={4,8,3}, w[]={3,3,-1};
    double s[]={2,-3,6,7,9};
    Vector a(3,u), b(3,v), c(3,w),d(5,s);
    Vector vertices[]={a,b,c};
    matrix cp(3,vertices);
    cp.reduce();
    Vector t=cp.vertex(1);
    cp.independent();*/

    while(1)
        enter();


}




#endif // TEST_H_INCLUDED
