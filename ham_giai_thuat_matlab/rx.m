function f = rx( x)
  mt(2,2)=cos(x);  
mt(1,1)=1;     mt(1,2)=0;         mt(1,3)=0;           mt(1,4)=0;

mt(2,1)=0;                     mt(2,3)=-sin(x);    mt(2,4)=0;

mt(3,1)=0;     mt(3,2)=sin(x);   mt(3,3)=cos(x);      mt(3,4)=0;

mt(4,1)=0;     mt(4,2)=0;         mt(4,3)=0;           mt(4,4)=1;

 f=mt;


end
