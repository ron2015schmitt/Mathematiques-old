
// flag for run-time bounds and size checking
 


#import "matricks.hpp"
using namespace Matricks;

#import "testlib.hpp"

#import <iostream>
using namespace std;

#import <vector>




int main()
{
  bool Q;
  int m =0;
  Matrix<double> A1(2,2,"A1");
  Matrix<double> A2(2,2,"A2");
  Matrix<double> A3(2,2,"A3");
  A1(0) = 1;
  A1(1) = 2;
  A1(2) = 3;
  A1(3) = 4;
  double ans1[] = {1,2,3,4};
  mcompare(A1,ans1);

  Matrix<bool> q1(2,2,"q1");
  Matrix<bool> q2(2,2,"q2");

  q1 = (A1==1.0);
  bool ans2[] = {1,0,0,0};
  mcompare(q1,ans2);

  // scalar == and !=

  A1(0) = 1.0;
  A1(1) = 2.0;
  A1(2) = 1.0;
  A1(3) = 4.0;
  q1 = (A1==1.0);
  bool ans3[] = {1,0,1,0};
  mcompare(q1,ans3);

  q1=0;
  q1 = (2.0==A1);
  bool ans4[] = {0,1,0,0};
  mcompare(q1,ans4);

  q1=0;
  q1 = (A1!=1.0);
  bool ans5[] = {0,1,0,1};
  mcompare(q1,ans5);

  q1=0;
  q1 = (2.0!=A1);
  bool ans6[] = {1,0,1,1};
  mcompare(q1,ans6);

  // intscalar == and !=


  A1(0) = 1.0;
  A1(1) = 1.0;
  A1(2) = 4.0;
  A1(3) = 2.0;

  q1 = (A1==1);
  bool ans3i[] = {1,1,0,0};
  mcompare(q1,ans3i);

  q1=0;
  q1 = (2==A1);
  bool ans4i[] = {0,0,0,1};
  mcompare(q1,ans4i);

  q1=0;
  q1 = (A1!=1);
  bool ans5i[] = {0,0,1,1};
  mcompare(q1,ans5i);

  q1=0;
  q1 = (2!=A1);
  bool ans6i[] = {1,1,1,0};
  mcompare(q1,ans6i);


  // scalar <= and <

  A1(0) = 2.3;
  A1(1) = -1.0;
  A1(2) = 5.0;
  A1(3) = 3.0;

  q1=0;
  q1 = (A1<=3.0);
  bool ans10[] = {1,1,0,1};
  mcompare(q1,ans10);

  q1=0;
  q1 = (3.0<=A1);
  bool ans11[] = {0,0,1,1};
  mcompare(q1,ans11);

  q1=0;
  q1 = (A1<3.0);
  bool ans12[] = {1,1,0,0};
  mcompare(q1,ans12);

  q1=0;
  q1 = (3.0<A1);
  bool ans13[] = {0,0,1,0};
  mcompare(q1,ans13);


  // intscalar <= and <

  A1(0) = 2.3;
  A1(1) = -1.0;
  A1(2) = 3.0;
  A1(3) = 3.5;


  q1=0;
  q1 = (A1<=3);
  bool ans10i[] = {1,1,1,0};
  mcompare(q1,ans10i);

  q1=0;
  q1 = (3<=A1);
  bool ans11i[] = {0,0,1,1};
  mcompare(q1,ans11i);

  q1=0;
  q1 = (A1<3);
  bool ans12i[] = {1,1,0,0};
  mcompare(q1,ans12i);

  q1=0;
  q1 = (3<A1);
  bool ans13i[] = {0,0,0,1};
  mcompare(q1,ans13i);

  // scalar >= and >

  A1(0) = 3.0;
  A1(1) = -1.0;
  A1(2) = 4.0;
  A1(3) = 2.1;

  q1=0;
  q1 = (A1>=2.1);
  bool ans14[] = {1,0,1,1};
  mcompare(q1,ans14);

  q1=0;
  q1 = (2.1>=A1);
  bool ans15[] = {0,1,0,1};
  mcompare(q1,ans15);


  q1=0;
  q1 = (A1>2.1);
  bool ans16[] = {1,0,1,0};
  mcompare(q1,ans16);

  q1=0;
  q1 = (2.1>A1);
  bool ans17[] = {0,1,0,0};
  mcompare(q1,ans17);


// intscalar >= and >

  A1(0) = 4.0;
  A1(1) = -1.2;
  A1(2) = 2.0;
  A1(3) = 3.0;

  q1=0;
  q1 = (A1>=2);
  bool ans14i[] = {1,0,1,1};
  mcompare(q1,ans14i);

  q1=0;
  q1 = (2>=A1);
  bool ans15i[] = {0,1,1,0};
  mcompare(q1,ans15i);


  q1=0;
  q1 = (A1>2);
  bool ans16i[] = {1,0,0,1};
  mcompare(q1,ans16i);

  q1=0;
  q1 = (2>A1);
  bool ans17i[] = {0,1,0,0};
  mcompare(q1,ans17i);


  // scalar &&, ||

  Matrix<bool> q3(2,2,"q3");

  q1(0) = 1;
  q1(1) = 0;
  q1(2) = 0;
  q1(3) = 1;

  q3 = q1 && true;
  bool ans20[] = {1,0,0,1};
  mcompare(q3,ans20);
  q3 = q1 && false;
  bool ans21[] = {0,0,0,0};
  mcompare(q3,ans21);
  q3 = q1 || true;
  bool ans22[] = {1,1,1,1};
  mcompare(q3,ans22);
  q3 = q1 || false;
  bool ans23[] = {1,0,0,1};
  mcompare(q3,ans23);

  q1(0) = 0;
  q1(1) = 1;
  q1(2) = 0;
  q1(3) = 1;

  q3 = true && q1;
  bool ans24[] = {0,1,0,1};
  mcompare(q3,ans24);
  q3 =  false && q1;
  bool ans25[] = {0,0,0,0};
  mcompare(q3,ans25);
  q3 = true ||q1;
  bool ans26[] = {1,1,1,1};
  mcompare(q3,ans26);
  q3 = false||q1;
  bool ans27[] = {0,1,0,1};
  mcompare(q3,ans27);

  
  // not -- !

  q1(0) = 1;
  q1(1) = 1;
  q1(2) = 0;
  q1(3) = 0;

  q2(0) = 1;
  q2(1) = 0;
  q2(2) = 1;
  q2(3) = 0;

  q3 = !q1;
  bool ans30[] = {0,0,1,1};
  mcompare(q3,ans30);
  q3 = !q2;
  bool ans31[] = {0,1,0,1};
  mcompare(q3,ans31);


  // matrix && matrix

  q3 = q1 && q2;
  bool ans32[] = {1,0,0,0};
  mcompare(q3,ans32);
  q3 = q1 && !q2;
  bool ans33[] = {0,1,0,0};
  mcompare(q3,ans33);
  q3 = !q1 && q2;
  bool ans34[] = {0,0,1,0};
  mcompare(q3,ans34);
  q3 = !q1 && !q2;
  bool ans35[] = {0,0,0,1};
  mcompare(q3,ans35);

  // matrix || matrix

  q3 = q1 || q2;
  bool ans36[] = {1,1,1,0};
  mcompare(q3,ans36);
  q3 = q1 || !q2;
  bool ans37[] = {1,1,0,1};
  mcompare(q3,ans37);
  q3 = !q1 || q2;
  bool ans38[] = {1,0,1,1};
  mcompare(q3,ans38);
  q3 = !q1 || !q2;
  bool ans39[] = {0,1,1,1};
  mcompare(q3,ans39);

  A1(0) = 4.0;
  A1(1) = -1.2;
  A1(2) = 2.0;
  A1(3) = 3.0;

  A2(0) = 4.0;
  A2(1) = -1.0;
  A2(2) = 1.9;
  A2(3) = 3.0;

  // matrix == matrix
  q1 = (A1==A2);
  bool ans50[] = {1,0,0,1};
  mcompare(q1,ans50);
  q1 = (A1==(A2+10));
  bool ans51[] = {0,0,0,0};
  mcompare(q1,ans51);

  // matrix != matrix
  q1 = (A1!=A2);
  bool ans52[] = {0,1,1,0};
  mcompare(q1,ans52);
  q1 = (A1!=(A2+10));
  bool ans53[] = {1,1,1,1};
  mcompare(q1,ans53);

  // matrix < matrix
  q1 = (A1<A2);
  bool ans54[] = {0,1,0,0};
  mcompare(q1,ans54);
  q1 = (A1<(A2+0.2));
  bool ans55[] = {1,1,1,1};
  mcompare(q1,ans55);

  // matrix <= matrix
  q1 = (A1<=A2);
  bool ans56[] = {1,1,0,1};
  mcompare(q1,ans56);
  q1 = (A1<=(A2-0.1));
  bool ans57[] = {0,1,0,0};
  mcompare(q1,ans57);


 // matrix > matrix
  q1 = (A1>A2);
  bool ans58[] = {0,0,1,0};
  mcompare(q1,ans58);
  q1 = (A1>(A2-0.1));
  bool ans59[] = {1,0,1,1};
  mcompare(q1,ans59);

  // matrix >= matrix
  q1 = (A1>=A2);
  bool ans60[] = {1,0,1,1};
  mcompare(q1,ans60);
  q1 = (A1>=(A2+0.05));
  bool ans61[] = {0,0,1,0};
  mcompare(q1,ans61);


  q1(0) = 1;
  q1(1) = 1;
  q1(2) = 0;
  q1(3) = 0;

  q2(0) = 1;
  q2(1) = 0;
  q2(2) = 1;
  q2(3) = 0;

  // alltrue
  Q = alltrue(q1);
  compare(Q,false);
  Q = alltrue(!q1);
  compare(Q,false);
  Q = alltrue(q1||!q1);
  compare(Q,true);

  // anytrue
  Q = anytrue(q1);
  compare(Q,true);
  Q = anytrue(!q1);
  compare(Q,true);
  Q = anytrue(q1&&!q1);
  compare(Q,false);

  // numtrue
  m = numtrue(q1);
  compare(m,2);
  m = numtrue(q1||true);
  compare(m,4);
  m = numtrue(q1&&false);
  compare(m,0);
  m = numtrue(!(q1||q2));
  compare(m,1);


  Matrix<bool> W1(3,4,"W1");
  Matrix<bool> W2(3,4,"W2");
  LAvector<bool> wr(3,"wr");
  LAvector<bool> wc(4,"wc");
  LAvector<unsigned int> mr(3,"mr");
  LAvector<unsigned int> mc(4,"mc");

  W1(0,0) = 1;
  W1(0,1) = 0;
  W1(0,2) = 1;
  W1(0,3) = 1;
  W1(1,0) = 1;
  W1(1,1) = 0;
  W1(1,2) = 1;
  W1(1,3) = 0;
  W1(2,0) = 1;
  W1(2,1) = 0;
  W1(2,2) = 0;
  W1(2,3) = 0;
  bool ans90[] = {1,0,1,1,1,0,1,0,1,0,0,0};
  mcompare(W1,ans90);

  // alltruebyrow
  wr = alltruebyrow(W1);
  bool ans91[] = {0,0,0};
  vcompare(wr,ans91);
  wr = alltruebyrow(W1||true);
  bool ans92[] = {1,1,1};
  vcompare(wr,ans92);

  // alltruebycol
  wc = alltruebycol(W1);
  bool ans93[] = {1,0,0,0};
  vcompare(wc,ans93);

  // anytruebyrow
  wr = anytruebyrow(W1);
  bool ans94[] = {1,1,1};
  vcompare(wr,ans94);
  wr = anytruebyrow(W1&&false);
  bool ans94b[] = {0,0,0};
  vcompare(wr,ans94b);

  // anytruebycol
  wc = anytruebycol(W1);
  bool ans95[] = {1,0,1,1};
  vcompare(wc,ans95);

  // numtruebyrow
  mr = numtruebyrow(W1);
  unsigned int ans96[] = {3,2,1};
  vcompare(mr,ans96);
  mr = numtruebyrow(W1&&false);
  unsigned int ans96b[] = {0,0,0};
  vcompare(mr,ans96b);

  // numytruebycol
  mc = numtruebycol(W1);
  unsigned int ans97[] = {3,0,2,1};
  vcompare(mc,ans97);


  // find true
  W1(0,0) = 1;
  W1(0,1) = 0;
  W1(0,2) = 1;
  W1(0,3) = 1;
  W1(1,0) = 1;
  W1(1,1) = 0;
  W1(1,2) = 1;
  W1(1,3) = 0;
  W1(2,0) = 1;
  W1(2,1) = 0;
  W1(2,2) = 0;
  W1(2,3) = 0;
  bool ans100[] = {1,0,1,1,1,0,1,0,1,0,0,0};
  mcompare(W1,ans100);
  W2(0,0) = 0;
  W2(0,1) = 0;
  W2(0,2) = 0;
  W2(0,3) = 0;
  W2(1,0) = 1;
  W2(1,1) = 1;
  W2(1,2) = 0;
  W2(1,3) = 0;
  W2(2,0) = 1;
  W2(2,1) = 1;
  W2(2,2) = 1;
  W2(2,3) = 1;
  bool ans101[] = {0,0,0,0,1,1,0,0,1,1,1,1};
  mcompare(W2,ans101);

  Matrix<unsigned int> R1(0,0,"R1");
  
  R1.resize() = findtrue(W1);
  unsigned int ans102[] = {0,0,
			   0,2,
			   0,3,
			   1,0,
			   1,2,
			   2,0  };
  mcompare(R1,ans102);

  R1.resize() = findtrue(W2);
  unsigned int ans103[] = {1,0,
			   1,1,
			   2,0,
			   2,1,
			   2,2,
			   2,3  };
  mcompare(R1,ans103);

  R1.resize() = findtrue(W2&&false);
  unsigned int ans104[] = {};
  mcompare(R1,ans104);

  cout << "<Boolean matrix tests passed>"<<endl;

  return 0;
}
