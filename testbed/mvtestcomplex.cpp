
// flag for run-time bounds and size checking
 


#import "matricks.hpp"
using namespace Matricks;

#import "testlib.hpp"

#import <iostream>
using namespace std;


#import <vector>


int main()
{

  typedef complex<double> cd;

  typedef complex<float> cf;



  LAvector<cd> va(3,"va");
  LAvector<double> vb(3,"vb");
  va[0] =  cd(-9,4);
  va[1] =  cd(13,1);
  va[2] =  cd(8,10);
  vb[0] = 3;
  vb[1] = -5;
  vb[2] = 2;
  Matrix<cd> A(3,3);

  A = (va^vb);
  cd ansa[] = {cd(-9,4)*3.0,  cd(13,1)*3.0,  cd(8,10)*3.0,
	       cd(-9,4)*-5.0, cd(13,1)*-5.0, cd(8,10)*-5.0,
	       cd(-9,4)*2.0,  cd(13,1)*2.0,  cd(8,10)*2.0
  };
  mcompare(A,ansa);


  A = 0;
  A = (vb^va);
  cd ansb[] = {3.0*cd(-9,4),  -5.0*cd(-9,4), 2.0*cd(-9,4),
	       3.0*cd(13,1),  -5.0*cd(13,1),  2.0*cd(13,1),
	       3.0*cd(8,10),  -5.0*cd(8,10), 2.0*cd(8,10)
  };
  mcompare(A,ansb);



  Matrix<cd> A1(3,3,"A1");


  // Initialization tests
  A1(0,0) = cd(1,-3);
  A1(0,1) = cd(2,4);
  A1(0,2) = cd(3,7);
  A1(1,0) = cd(4,-2);
  A1(1,1) = cd(5,-1);
  A1(1,2) = cd(6,0);
  A1(2,0) = cd(7,-4);
  A1(2,1) = cd(8,-8);
  A1(2,2) = cd(9,-10);
  cd ans0[] = { cd(1,-3),  cd(2,4),    cd(3,7),
		cd(4,-2),  cd(5,-1),   cd(6,0),
		cd(7,-4),  cd(8,-8),   cd(9,-10)};
  mcompare(A1,ans0);

  LAvector<cd> v3(3,"v3");

  LAvector<cd> v1(3,"v1");
  v1[0] =  cd(3,-1);
  v1[1] =  cd(-8,-4);
  v1[2] =  cd(4,-5);

  v3 = (A1|v1);
  cd ans3[] = { cd(1,-3)*cd(3,-1) + cd(2,4)*cd(-8,-4) +   cd(3,7)*cd(4,-5),
		cd(4,-2)*cd(3,-1) + cd(5,-1)*cd(-8,-4) +  cd(6,0)*cd(4,-5),
		cd(7,-4)*cd(3,-1) + cd(8,-8)*cd(-8,-4) +  cd(9,-10)*cd(4,-5)
  };
  vcompare(v3,ans3);


  LAvector<double> v2(3,"v2");
  v2[0] = 2;
  v2[1] = 3;
  v2[2] = -4;

  v3 = (A1|v2);
  cd ans4[] = { cd(1,-3)*2.0 + cd(2,4)*3.0 +   cd(3,7)*-4.0,
		cd(4,-2)*2.0 + cd(5,-1)*3.0 +  cd(6,0)*-4.0,
		cd(7,-4)*2.0 + cd(8,-8)*3.0 +  cd(9,-10)*-4.0
  };
  vcompare(v3,ans4);

  v3=0;
  v2[0] = 5;
  v2[1] = -6;
  v2[2] = 7;
  v3 = (v2|A1);
  cd ans5[] = { cd(1,-3)*5.0 + cd(4,-2)*-6.0 +   cd(7,-4)*7.0,
		cd(2,4)*5.0 + cd(5,-1)*-6.0 +  cd(8,-8)*7.0,
		cd(3,7)*5.0 + cd(6,0)*-6.0 +  cd(9,-10)*7.0
  };
  vcompare(v3,ans5);


  Matrix<double> A2(3,3,"A2");
  A2(0) = 11;
  A2(1) = -3;
  A2(2) = 3;
  A2(3) = 5;
  A2(4) = 41;
  A2(5) = -100;
  A2(6) = 36;
  A2(7) = 2;
  A2(8) = 34;
  double ans10[] = {11,-3,3,
		   5,41,-100,
		   36,2,34};
  mcompare(A2,ans10);



  v3=0;
  v3 = (A2|v1);
  cd ans11[] = { 11.0*cd(3,-1) + -3.0*cd(-8,-4) +   3.0*cd(4,-5),
		5.0*cd(3,-1) + 41.0*cd(-8,-4) +  -100.0*cd(4,-5),
		36.0*cd(3,-1) + 2.0*cd(-8,-4) +  34.0*cd(4,-5)
  };
  vcompare(v3,ans11);

  v3=0;
  v3 = v1|A2;
  cd ans12[] = { 11.0*cd(3,-1) + 5.0*cd(-8,-4) +   36.0*cd(4,-5),
		-3.0*cd(3,-1) + 41.0*cd(-8,-4) +  2.0*cd(4,-5),
		3.0*cd(3,-1) + -100.0*cd(-8,-4) +  34.0*cd(4,-5)
  };
  vcompare(v3,ans12);




  cout << "<Complex matrix-vector tests passed>"<<endl;
  return 0;


}
