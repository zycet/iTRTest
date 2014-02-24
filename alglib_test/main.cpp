#include <iostream>
#include <math.h>
#include "alglib.h"
#include "ap.h"
using namespace std;
using namespace alglib;

bool doc_test_real_matrix(const real_2d_array &v, const real_2d_array &t, double _threshold)
{
    ae_int_t i, j;
    if( v.rows()!=t.rows() )
        return false;
    if( v.cols()!=t.cols() )
        return false;
    for(i=0; i<v.rows(); i++)
        for(j=0; j<v.cols(); j++)
        {
            double s = _threshold>=0 ? 1.0 : fabs(t(i,j));
            double threshold = fabs(_threshold);
            if( fabs(v(i,j)-t(i,j))/s>threshold )
                return false;
        }
    return true;
}

void TestSVD()
{
    real_2d_array a;
    double data[8]={1,3,5,7,2,4,6,8};
    double data1[16]={0};
    double data2[4]={0};
    a.setcontent(2,4,data);
    real_2d_array u,vt;
    real_1d_array w;
    w.allocate_own(4,alglib_impl::DT_REAL);
    u.setcontent(2,2,data2);
    vt.setcontent(4,4,data1);
    rmatrixsvd(a,2,4,0,1,0,w,u,vt);

    for(int i=0; i<4; i++)
     {
        for(int j=0; j<4; j++)
        {
            printf("%f\t",vt(i,j));
        }
        printf("\n");
    }
}

int main()
{

    cout << "Hello world!" << endl;
    TestSVD();
    getchar();
    return 0;
}
