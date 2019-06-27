function y = function_solve( alpha,beta,xp,yp,zp,p1,p2,p3)
r1=350;%ban kinh de
h1=60;
z2=151.6;
dbandau=341;

r2=180;% ban kinh ban may

q=sym('q',[3 1]);
%  di phy thuasi
chan=rz(alpha)*tx(r1)*tz(h1)*rx(q(2))*ry(q(3))*tz(q(1)+dbandau+z2);
banmay=tx(xp)*ty(yp)*tz(zp)*rz(p1)*ry(p2)*rz(p3)*rz(beta)*tx(r2);

f=sym('f',[3 1]);
for i=1:1:3
    f(i)=chan(i,4)-banmay(i,4);
end

%tinh ma tran jacobi

for i=1:1:3
    for j=1:1:3
        J(i,j)=diff(f(i),q(j));
    end
end
q_=[200;pi/12;0];
for i=1:1:20
    J_=vpa(subs(J,q,q_));
    f_=vpa(subs(f,q,q_));
    q_=q_-inv(J_)*f_;
end
y=q_;

end

